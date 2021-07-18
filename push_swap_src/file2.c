#include "../checker.h"

t_pile	*keep_in_a(t_pile *a)
{
	int	*t;
	int	value;
	int	i;
	int	*tab;
	int	j;

	j = 0;
	i = 0;
	value = 0;
	t = fill_tab(a);
	tab = malloc(sizeof(int) * stack_size(a));
	while (i < stack_size(a))
	{
		if (t[i] >= value)
		{
			tab[j] = t[i];
			value = t[i];
			j++;
		}
		i++;
	}
	free(t);
	return (markup_stack(a, tab, j));
}

void	fill_index(t_pile *p, t_pile **a, int t[], int *size)
{
	int	i;

	i = 0;
	while (i < *size)
	{
		p = *a;
		while (p)
		{
			if (t[i] == p->data)
				p->index = i;
			p = p->previous;
		}
		i++;
	}
	free(t);
}

t_pile	*ft_fill_index(t_pile *a, int size)
{
	int		*t;
	int		i;
	t_pile	*p;

	p = a;
	i = 0;
	t = malloc(sizeof(int) * size);
	while (p)
	{
		t[i] = p->data;
		i++;
		p = p->previous;
	}
	tri_selection(t, size);
	i = 0;
	fill_index(p, &a, t, &size);
	return (a);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
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

int	max_stack(t_pile *b)
{
	int	max;

	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->previous;
	}
	return (max);
}
