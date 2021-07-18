#include "../checker.h"

void	ft_put_error(void)
{
	ft_putstr_fd("Error", 1);
	exit(0);
}

void	check_ra1(t_pile **stack_a)
{
	if (stack_size(*stack_a) >= 2)
		*stack_a = rotate_ab(*stack_a);
}

void	check_helf1(t_pile **stack_a, t_pile **stack_b, char **line)
{
	if (ft_strcmp(*line, "sa") == 0)
		*stack_a = swap_ab(*stack_a);
	else if (ft_strcmp(*line, "sb") == 0)
		*stack_b = swap_ab(*stack_b);
	else if (ft_strcmp(*line, "ss" ) == 0)
		swap_a_b(stack_a, stack_b);
	else if (ft_strcmp(*line, "ra") == 0)
		check_ra1(stack_a);
	else if (ft_strcmp(*line, "rb") == 0)
		*stack_b = rotate_ab(*stack_b);
	else if (ft_strcmp(*line, "rr") == 0)
		rotate_a_b(stack_a, stack_b);
	else if (ft_strcmp(*line, "rra") == 0)
		*stack_a = reverse_rotate_ab(*stack_a);
	else if (ft_strcmp(*line, "rrb") == 0)
		*stack_b = reverse_rotate_ab(*stack_b);
	else if (ft_strcmp(*line, "rrr") == 0)
		reverse_rotate_a_b(stack_a, stack_b);
	else if (ft_strcmp(*line, "pa") == 0)
		ft_push_ab(stack_b, stack_a);
	else if (ft_strcmp(*line, "pb") == 0)
		ft_push_ab(stack_a, stack_b);
	else
		ft_put_error();
}

void	ft_four_lines(t_pile *stack_a, t_pile *stack_b)
{
	if (check_sort_a(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_pile	*stack_a;
	t_pile	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	while (argc > 1)
	{
		is_numberr(argv[argc - 1]);
		stack_a = ft_push(stack_a, ft_atoi(argv[argc - 1]), 0);
		argc--;
	}
	stack_a = ft_fill_index(stack_a, stack_size(stack_a));
	check_dups(stack_a, 1, 1);
	while ((get_next_line(&line)))
	{
		check_helf1(&stack_a, &stack_b, &line);
		free(line);
	}
	free(line);
	ft_four_lines(stack_a, stack_b);
	return (0);
}
