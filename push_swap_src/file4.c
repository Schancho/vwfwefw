#include "../checker.h"

void	find_right_place(t_pile *a, t_var *var, int ta[], int tb[])
{
	(*var).j = 1;
	(*var).k = 1;
	while ((*var).j < stack_size(a) - 1)
	{
		if (tb[(*var).i] > ta[(*var).j] && tb[(*var).i] < ta[(*var).j + 1])
			break ;
		(*var).j++;
		(*var).k++;
	}
}

void	find_best_conditions(t_pile *a, t_pile *b, t_var *var, int *index_min)
{
	if ((*var).k <= stack_size(a) / 2)
		(*var).m = (*var).k;
	else
		(*var).m = stack_size(a) - (*var).k;
	if ((*var).i <= stack_size(b) / 2)
		(*var).m = (*var).m + (*var).i;
	else
		(*var).m = (*var).m + stack_size(b) - (*var).i;
	if ((*var).l > (*var).m)
	{
		(*var).l = (*var).m;
		*index_min = (*var).i;
	}
}

int	find_best(t_pile *a, t_pile *b, int **tabl, int max)
{
	t_var	var;
	int		*tab;
	int		index_min;

	index_min = -1;
	tab = malloc(sizeof(int) * stack_size(b));
	var.l = 1000000;
	var.i = 0;
	while (var.i < stack_size(b))
	{
		var.m = 0;
		var.k = 0;
		if (tabl[1][var.i] == max)
			var.k = min_index(tabl[0], a);
		else if (tabl[1][var.i] < tabl[0][0] &&
			tabl[1][var.i] > tabl[0][stack_size(a) - 1])
			var.k = 0;
		else
			find_right_place(a, &var, tabl[0], tabl[1]);
		find_best_conditions(a, b, &var, &index_min);
		var.i++;
	}
	var.i = tabl[1][index_min];
	free(tab);
	return (var.i);
}

int	cost_a(t_pile *a, int ta[], int index, int max)
{
	int	i;
	int	j;
	int	k;
	int	ret;

	i = 0;
	ret = 0;
	k = 0;
	if (index == max || index > max_b(a))
		k = min_index(ta, a);
	else if (index < ta[0] && index > ta[stack_size(a) - 1])
		k = 0;
	else
	{
		j = 0;
		k = 1;
		while (j < stack_size(a) - 1)
		{
			if (index > ta[j] && index < ta[j + 1])
				break ;
			j++;
			k++;
		}
	}
	return (k);
}

int	cost_b(t_pile *b, int t[], int index)
{
	int	i;

	i = 0;
	while (i < stack_size(b))
	{
		if (t[i] == index)
			return (i);
		i++;
	}
	return (0);
}
