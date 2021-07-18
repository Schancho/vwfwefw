#include "../checker.h"

t_pile	*duplicate(t_pile *a)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	while (a)
	{
		new = ft_push(new, a->data, a->index);
		a = a->previous;
	}
	return (new);
}

int	*fill_tab(t_pile *p)
{
	int		*t;
	int		i;
	t_pile	*tmp;

	tmp = p;
	i = 0;
	t = (int *)malloc(sizeof(int) * stack_size(p));
	while (p && p->index != 0)
		p = p->previous;
	while (p)
	{
		t[i] = p->index;
		p = p->previous;
		i++;
	}
	while (tmp && tmp->index != 0)
	{
		t[i] = tmp->index;
		tmp = tmp->previous;
		i++;
	}
	return (t);
}

t_pile	*markup_stack(t_pile *a, int tab[], int j)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < j)
		{
			if (tab[i] == tmp->index)
			{
				tmp->bool = 1;
				break ;
			}
			i++;
		}
		tmp = tmp->previous;
	}
	free(tab);
	return (a);
}

int	*duplicate_tab(int t[], int j)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * j);
	while (i < j)
	{
		tab[i] = t[i];
		i++;
	}
	return (tab);
}

void	print_instructions(t_operations *queue)
{
	while (queue)
	{
		ft_putstr_fd(queue->op, 1);
		write(1, "\n", 1);
		queue = queue->next;
	}
}
