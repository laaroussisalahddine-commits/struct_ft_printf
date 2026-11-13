
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

static int	check_test(t_format *fmt, int n, int width, int mode)
{
	int		expected;
	int		actual;
	char	expected_str[100];
	char	actual_str[100];
	FILE	*tmp;
	int		saved;
	int		fd;

	if (mode == 0)
		expected = snprintf(expected_str, sizeof(expected_str),
				"%0*d", width, n);
	else if (mode == 1)
		expected = snprintf(expected_str, sizeof(expected_str),
				"%+*d", width, n);
	else
		expected = snprintf(expected_str, sizeof(expected_str),
				"%+0*d", width, n);

	tmp = tmpfile();
	if (!tmp)
		return (0);
	fd = fileno(tmp);
	saved = dup(STDOUT_FILENO);
	fflush(stdout);
	dup2(fd, STDOUT_FILENO);
	actual = ft_ze_pl(fmt, n);
	fflush(stdout);
	dup2(saved, STDOUT_FILENO);
	close(saved);

	rewind(tmp);
	memset(actual_str, 0, sizeof(actual_str));
	fread(actual_str, 1, sizeof(actual_str) - 1, tmp);
	fclose(tmp);

	if (expected == actual
		&& strcmp(expected_str, actual_str) == 0)
		return (1);
	printf("FAIL | mode=%d n=%d width=%d\n", mode, n, width);
	printf("  Expected: [%s] return=%d\n", expected_str, expected);
	printf("  Actual:   [%s] return=%d\n", actual_str, actual);
	return (0);
}

int	main(void)
{
	t_format	fmt;
	int			numbers[] = {42, -42, 0, 123, -123};
	int			widths[] = {0, 2, 3, 5, 8};
	int			i;
	int			j;
	int			k;
	int			passed;
	int			failed;

	passed = 0;
	failed = 0;
	k = 0;
	while (k < 3)
	{
		i = 0;
		while (i < 5)
		{
			j = 0;
			while (j < 5)
			{
				initial_format(&fmt);
				fmt.width = widths[j];
				fmt.zero = (k == 0 || k == 2);
				fmt.plus = (k == 1 || k == 2);
				if (check_test(&fmt, numbers[i], widths[j], k))
					passed++;
				else
					failed++;
				j++;
			}
			i++;
		}
		k++;
	}
	printf("\n========== TEST RESULTS ==========\n");
	printf("Passed: %d / %d\n", passed, passed + failed);
	printf("Failed: %d\n", failed);
	if (failed == 0)
	{
		printf("✅ ALL TESTS PASSED!\n");
		return (0);
	}
	printf("❌ SOME TESTS FAILED!\n");
	return (1);
}
