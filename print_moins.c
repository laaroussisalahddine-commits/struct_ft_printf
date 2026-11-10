#include "ft_printf.h"

int	count(char *str, int start)
{
	int	count;

	count = 0;
	while (str[start] && str[start] != 'd')
	{
		count++;
		start++;
	}
	return (count);
}
void print_spaces(int len)
{

	while (len-- > 0)
		write(1, " ", 1);
	
}

int	print_moins(char *str)
{
	char		*new;
	int			i;
	int			len;
	int			j;

	len = 0;
	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	if (str[i] == '%' && str[i + 1] == '-')
	{
		i += 2;
		len = count(str, i);
		if (!(new = malloc(len + 1)))
			return (0);
		j = 0;
		while (str[i] && str[i] != 'd')
		{
			new[j] = str[i];
			i++;
			j++;
		}
		new = '\0';
		len = atoi(new);
		print_spaces(len);
	}
	return (len);
}
