
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	t_format	fmt;
	int			ret;
	int			expected;
	int			numbers[] = {42, -42, 0, 123, -123};
	int			widths[] = {0, 2, 3, 5, 8};
	int			i;
	int			j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			initial_format(&fmt);
			fmt.zero = 1;
			fmt.spaces = 1;
			fmt.width = widths[j];

			printf("\n=== n=%d | width=%d ===\n",
				numbers[i], widths[j]);

			printf("Expected: |");
			expected = printf("% 0*d", widths[j], numbers[i]);
			printf("| (return=%d)\n", expected);

			printf("Yours:    |");
			fflush(stdout);
			ret = print_zero_plus(&fmt, numbers[i]);
			printf("| (return=%d)\n", ret);

			j++;
		}
		i++;
	}
	return (0);
}
