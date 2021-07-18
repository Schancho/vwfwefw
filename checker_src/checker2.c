#include "../checker.h"

int	is_numberr(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
	}
	return (1);
}
