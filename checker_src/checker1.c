#include "../checker.h"

void	rotate_a_b(t_pile **stack_a, t_pile **stack_b)
{
	*stack_a = rotate_ab(*stack_a);
	*stack_b = rotate_ab(*stack_b);
}

void	swap_a_b(t_pile **stack_a, t_pile **stack_b)
{
	*stack_a = swap_ab(*stack_a);
	*stack_b = swap_ab(*stack_b);
}

void	reverse_rotate_a_b(t_pile **stack_a, t_pile **stack_b)
{
	*stack_a = reverse_rotate_ab(*stack_a);
	*stack_b = reverse_rotate_ab(*stack_b);
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
