#include "checker.h"

int	*fill_tab_1(t_pile *p)
{
	int	i;
	int	*t;

	i = 0;
	t = (int *)malloc(sizeof(int) * stack_size(p));
	while (p)
	{
		t[i] = p->index;
		p = p->previous;
		i++;
	}
	return (t);
}

t_pile	*reverse_rotate_ab(t_pile *p)
{
	t_pile	*tmp;
	t_pile	*new;

	if (!p)
		return (p);
	tmp = p;
	while (tmp->previous->previous)
		tmp = tmp->previous;
	tmp->previous->previous = p;
	p = tmp->previous;
	new = tmp->previous;
	tmp->previous = NULL;
	return (p);
}

void	check_dups(t_pile *a, int i, int j)
{
	int	*t;
	int	elem;
	int	tag;

	t = fill_tab_1(a);
	j = -1;
	while (++j < stack_size(a))
	{
		i = -1;
		elem = t[j];
		tag = 0;
		while (++i < stack_size(a))
		{
			if (t[i] == elem)
				tag++;
			if (tag == 2)
			{
				ft_putstr_fd("Error\n", 1);
				free(t);
				exit(0);
			}
		}
	}
	free(t);
}
