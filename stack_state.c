#include "checker.h"

void	echanger(int t[], int i, int j)
{
	int	tmp;

	tmp = t[i];
	t[i] = t[j];
	t[j] = tmp;
}

int	minimum(int t[], int i_min, int i_max)
{
	int	i;
	int	indice_min;

	indice_min = i_min;
	i = i_min;
	while (i <= i_max)
	{
		if (t[i] < t[indice_min])
			indice_min = i;
		i++;
	}
	return (indice_min);
}

void	tri_selection(int t[], int n)
{
	int	i;
	int	i_min;

	i = 0;
	while (i < n - 1)
	{
		i_min = minimum(t, i, n - 1);
		if (i_min != i)
			echanger(t, i, i_min);
		i++;
	}
}

int	check_sort_a(t_pile *b)
{
	int		first;

	if (stack_size(b) <= 1)
		return (1);
	first = b->data;
	b = b->previous;
	while (b)
	{
		if (first > b->data)
			return (0);
		first = b->data;
		b = b->previous;
	}
	return (1);
}
