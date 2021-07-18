#include "../checker.h"

void	finalize(t_pile **a, t_operations **queue)
{
	if ((*a)->index > stack_size(*a) / 2)
	{
		while (!check_sort_a(*a))
		{
			*queue = enfiler(*queue, "ra");
			*a = rotate_ab(*a);
		}
	}
	else
	{
		while (!check_sort_a(*a))
		{
			*queue = enfiler(*queue, "rra");
			*a = reverse_rotate_ab(*a);
		}
	}
}

void	choose_to_push(t_pile **a, t_pile **b, t_operations **queue, int *i)
{
	if ((*a)->bool == 0)
	{
		ft_push_ab(a, b);
		*queue = enfiler(*queue, "pb");
		*i = 1;
	}
	else if ((*a)->bool == 1)
	{
		*a = rotate_ab(*a);
		*queue = enfiler(*queue, "ra");
		*i = 1;
	}
}

void	from_a_to_b(t_pile **a, t_pile **b, t_operations **queue)
{
	t_pile	*t;
	int		i;

	while (!check_sort_a(*a))
	{
		i = 1;
		t = *a;
		while (t)
		{
			if (t->bool == 0)
				i = 0;
			t = t->previous;
		}
		if (i == 1)
			break ;
		choose_to_push(a, b, queue, &i);
	}
}

void	push_1(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	while (var.l >= var.j && var.j > 0)
	{
		*queue = enfiler(*queue, "rrr");
		*a = reverse_rotate_ab(*a);
		*b = reverse_rotate_ab(*b);
		var.j--;
		var.l--;
	}
	while (var.l > 0)
	{
		*queue = enfiler(*queue, "rrb");
		*b = reverse_rotate_ab(*b);
		var.l--;
	}
}
