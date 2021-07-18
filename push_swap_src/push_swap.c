#include "../checker.h"

t_pile	*first_markup(t_pile *a)
{
	t_pile	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->bool = 0;
		tmp = tmp->previous;
	}
	return (a);
}

void	free_queue(t_operations *queue)
{
	t_operations	*tmp;

	while (queue->next)
	{
		tmp = queue->next;
		free(queue);
		queue = tmp;
	}
	free(queue);
}

void	ft_free_stack(t_pile *p)
{
	t_pile	*tmp;

	while (p->previous)
	{
		tmp = p->previous;
		free(p);
		p = tmp;
	}
	free(p);
}

void 	solve_3(t_pile **a, t_operations **queue)
{
	if (!check_sort_a(*a))
	{
		if ((*a)->index > (*a)->previous->index && (*a)->index < (*a)->previous->previous->index)
		{
			*a = swap_ab(*a);
			*queue = enfiler(*queue, "sa");
		}
		else if ((*a)->index > (*a)->previous->index && (*a)->previous->index > (*a)->previous->previous->index)
		{
			*a = swap_ab(*a);
			*queue = enfiler(*queue, "sa");
			*a = reverse_rotate_ab(*a);
			*queue = enfiler(*queue, "rra");
		}
		else if ((*a)->index > (*a)->previous->index && (*a)->previous->index < (*a)->previous->previous->index)
		{
			*a = rotate_ab(*a);
			*queue = enfiler(*queue, "ra");
		}
		else if ((*a)->previous->index > (*a)->index && (*a)->previous->index > (*a)->previous->previous->index && (*a)->previous->previous->index > (*a)->index)
		{
			*a = swap_ab(*a);
			*queue = enfiler(*queue, "sa");
			*a = rotate_ab(*a);
			*queue = enfiler(*queue, "ra");
		}
		else
		{
			*a = reverse_rotate_ab(*a);
			*queue = enfiler(*queue, "rra");
		}
	}
}

void	push_min(t_pile **a, t_pile **b, t_operations **queue)
{
	int min;

	min = min_stack(*a);
	while ((*a)->index != min)
	{
		*a = rotate_ab(*a);
		*queue = enfiler(*queue, "ra");
	}
	ft_push_ab(a, b);
	*queue = enfiler(*queue, "pb");
}

t_operations 	*solve_short_stack(t_pile *a, t_pile *b, int ac)
{
	t_operations *queue;

	queue = NULL;
	if (ac == 4)
	{
		solve_3(&a, &queue);
		return (queue);
	}
	else 
	{
		push_min(&a, &b, &queue);
		push_min(&a, &b, &queue);
		solve_3(&a, &queue);
		ft_push_ab(&b, &a);
		ft_push_ab(&b, &a);
		queue = enfiler(queue, "pa");
		queue = enfiler(queue, "pa");
	}
	return (queue);
}

int	main(int argc, char **argv)
{
	t_pile			*stack_a;
	t_pile			*stack_b;
	t_operations	*queue;
	t_operations	*queue2;
	int				i;

	queue = NULL;
	stack_a = NULL;
	stack_b = NULL;
	i = argc;
	while (argc > 1)
	{
		is_number(argv[argc - 1]);
		stack_a = ft_push(stack_a, atoi(argv[argc - 1]), 0);
		argc--;
	}
	stack_a = ft_fill_index(stack_a, stack_size(stack_a));
	check_dups(stack_a, 1, 1);
	if (check_sort_a(stack_a))
		exit(0);
	if(i == 6 || i == 4)
	{
		queue = solve_short_stack(stack_a, stack_b, i);
	}
	else
	{
		
		stack_a = first_markup(stack_a);
		stack_a = keep_in_a(stack_a);
		queue = push_swap(&stack_a, &stack_b);
	}
	queue2 = queue;
	print_instructions(queue);
	//free_queue(queue2);
	return (0);
}
