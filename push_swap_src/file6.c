#include "../checker.h"

void	push_2(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	while (var.j > var.l && var.l > 0)
	{
		*queue = enfiler(*queue, "rrr");
		*a = reverse_rotate_ab(*a);
		*b = reverse_rotate_ab(*b);
		var.j--;
		var.l--;
	}
	while (var.j)
	{
		*queue = enfiler(*queue, "rra");
		*a = reverse_rotate_ab(*a);
		var.j--;
	}
}

void	push_3(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	while (var.l >= var.j && var.j > 0)
	{
		*queue = enfiler(*queue, "rr");
		*a = rotate_ab(*a);
		*b = rotate_ab(*b);
		var.j--;
		var.l--;
	}
	while (var.l > 0)
	{
		*queue = enfiler(*queue, "rb");
		*b = rotate_ab(*b);
		var.l--;
	}
}

void	push_4(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	while (*a && (*b)->previous && var.j > var.l && var.l > 0)
	{
		*queue = enfiler(*queue, "rr");
		*a = rotate_ab(*a);
		*b = rotate_ab(*b);
		var.j--;
		var.l--;
	}
	while (var.j)
	{
		*queue = enfiler(*queue, "ra");
		*a = rotate_ab(*a);
		var.j--;
	}
}

void	push_5(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	var.l = stack_size(*b) - var.l;
	while (var.l)
	{
		*queue = enfiler(*queue, "rrb");
		*b = reverse_rotate_ab(*b);
		var.l--;
	}
	while (var.j)
	{
		*queue = enfiler(*queue, "ra");
		*a = rotate_ab(*a);
		var.j--;
	}
	ft_push_ab(b, a);
	*queue = enfiler(*queue, "pa");
}

void	push_6(t_pile **a, t_pile **b, t_operations **queue, t_var var)
{
	var.j = stack_size(*a) - var.j;
	while (var.l)
	{
		*queue = enfiler(*queue, "rb");
		*b = rotate_ab(*b);
		var.l--;
	}
	while (var.j)
	{
		*queue = enfiler(*queue, "rra");
		*a = reverse_rotate_ab(*a);
		var.j--;
	}
	ft_push_ab(b, a);
	*queue = enfiler(*queue, "pa");
}
