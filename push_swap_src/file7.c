#include "../checker.h"

void	push_7(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	if (var.j >= stack_size(*a) / 2)
	{
		var.j = stack_size(*a) - var.j;
		while (var.j)
		{
			*queue = enfiler(*queue, "rra");
			*a = reverse_rotate_ab(*a);
			var.j--;
		}
		ft_push_ab(b, a);
		*queue = enfiler(*queue, "pa");
	}
	else
	{
		while (var.j)
		{
			*queue = enfiler(*queue, "ra");
			*a = rotate_ab(*a);
			var.j--;
		}
		ft_push_ab(b, a);
		*queue = enfiler(*queue, "pa");
	}
}

void	cost_calculate(t_pile **a, t_pile **b, t_var *var)
{
	int	*ta;
	int	*tb;
	int	**tabl;

	tabl = malloc(sizeof(int *) * 2);
	ta = fill_tab_1(*a);
	tb = fill_tab_1(*b);
	tabl[0] = ta;
	tabl[1] = tb;
	(*var).i = find_best(*a, *b, tabl, (*var).k);
	(*var).j = cost_a(*a, ta, (*var).i, (*var).k);
	(*var).l = cost_b(*b, tb, (*var).i);
	free(ta);
	free(tb);
	free(tabl);
}

void	push_8(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	var.l = stack_size(*b) - var.l;
	var.j = stack_size(*a) - var.j;
	if (var.l >= var.j)
		push_1(a, b, queue, var);
	else
		push_2(a, b, queue, var);
	ft_push_ab(b, a);
	*queue = enfiler(*queue, "pa");
}

void	push_b_to_a(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	while (*b)
	{
		cost_calculate(a, b, &var);
		if (stack_size(*b) > 1
			&& var.l >= stack_size(*b) / 2 && var.j >= stack_size(*a) / 2)
			push_8(a, b, queue, var);
		else if (stack_size(*b) > 1
			&& var.l <= stack_size(*b) / 2 && var.j <= stack_size(*a) / 2)
		{
			if (var.l >= var.j)
				push_3(a, b, queue, var);
			else
				push_4(a, b, queue, var);
			ft_push_ab(b, a);
			*queue = enfiler(*queue, "pa");
		}
		else if (stack_size(*b) > 1
			&& var.j <= stack_size(*a) / 2 && var.l >= stack_size(*b) / 2)
			push_5(a, b, queue, var);
		else if (stack_size(*b) > 1
			&& var.j >= stack_size(*a) / 2 && var.l <= stack_size(*b) / 2)
			push_6(a, b, queue, var);
		else
			push_7(a, b, queue, var);
	}
}

t_operations	*push_swap(t_pile **a, t_pile **b)
{
	t_var			var;
	t_operations	*queue;

	queue = NULL;
	var.k = max_b(*a);
	from_a_to_b(a, b, &queue);
	push_b_to_a(a, b, &queue, var);
	finalize(a, &queue);
	return (queue);
}
