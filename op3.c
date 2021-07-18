#include "checker.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

void	message(char *str)
{
	ft_putstr_fd(str, 1);
}

t_pile	*ft_push(t_pile *pile, int data, int index)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	if (new)
	{
		new->data = data;
		new->index = index;
		new->previous = pile;
		return (new);
	}
	return (NULL);
}

int	stack_size(t_pile *a)
{
	int	size;

	size = 0;
	while (a)
	{
		a = a->previous;
		size ++;
	}
	return (size);
}

void	ft_push_ab(t_pile **a, t_pile **b)
{
	t_pile	*mem;
	int		val;
	int		ind;

	if (*a)
	{
		ind = (*a)->index;
		val = (*a)->data;
		*b = ft_push(*b, val, ind);
		mem = (*a)->previous;
		free(*a);
		*a = mem;
	}
}
