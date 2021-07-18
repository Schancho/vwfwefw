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
		while (++i < stack_size(a) && i != j)
		{
			if (t[i] == elem)
			{
				ft_putstr_fd("Error\n", 1);
				free(t);
				exit(0);
			}
		}
	}
	free(t);
}