
#include <stdio.h>
#include "ft_printf.h"


int	main(void)
{
	t_format	fmt;
	int			numbers[] = {42, -42, 0, 123, -123};
	int			widths[] = {0, 2, 3, 5, 8};
	int			i;
	int			j;
	int			k;
	int			ret;
	int			expected;

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

				printf("\n=== zero=%d plus=%d n=%d width=%d ===\n",
					fmt.zero, fmt.plus, numbers[i], widths[j]);

				printf("Expected: |");
				if (k == 0)
					expected = printf("%0*d", widths[j], numbers[i]);
				else if (k == 1)
					expected = printf("%+*d", widths[j], numbers[i]);
				else
					expected = printf("%+0*d", widths[j], numbers[i]);
				printf("| (return=%d)\n", expected);

				printf("Yours:    |");
				fflush(stdout);
				ret = ft_ze_pl(&fmt, numbers[i]);
				printf("| (return=%d)\n", ret);

				j++;
			}
			i++;
		}
		k++;
	}
	return (0);
}
