#include "../checker.h"

int	min_stack(t_pile *b)
{
	int	min;

	min = b->index;
	while (b)
	{
		if (b->index < min)
			min = b->index;
		b = b->previous;
	}
	return (min);
}

int	last(t_pile *a)
{
	while (a->previous)
		a = a->previous;
	return (a->index);
}

int	is_sup(t_pile *p, int index)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = p;
	while (p && i <= stack_size(tmp))
	{
		if (p->index == index)
			return (i);
		i++;
		p = p->previous;
	}
	return (0);
}

int	max_b(t_pile *p)
{
	int	max;

	max = p->index;
	while (p)
	{
		if (max < p->index)
			max = p->index;
		p = p->previous;
	}
	return (max);
}

int	min_index(int t[], t_pile *p)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	pos = i;
	min = t[i];
	while (i < stack_size(p))
	{
		if (min > t[i])
		{
			min = t[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
