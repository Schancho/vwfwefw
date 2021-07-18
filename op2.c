#include "checker.h"

t_pile	*swap_ab(t_pile *p)
{
	t_pile	*tmp;
	t_var	var;
	int		ind2;

	if (p)
	{
		tmp = p;
		var.i = p->data;
		var.k = p->index;
		if (stack_size(p) >= 2)
		{
			tmp = tmp->previous;
			var.j = tmp->data;
			ind2 = tmp->index;
			tmp->data = var.i;
			tmp->index = var.k;
			p->data = var.j;
			p->index = ind2;
		}
	}
	return (p);
}

void	add_new_element(t_pile **p, t_pile **new, t_var var)
{
	if (new)
	{
		(*new)->previous = NULL;
		(*new)->data = var.i;
		(*new)->index = var.k;
		(*new)->bool = var.j;
		while ((*p)->previous)
			*p = (*p)->previous;
		(*p)->previous = *new;
	}
}

t_pile	*rotate_ab(t_pile *p)
{
	t_pile	*tmp;
	t_pile	*new;
	t_var	var;

	tmp = p;
	if (p)
	{
		var.j = p->bool;
		var.i = p->data;
		var.k = p->index;
		tmp = p;
		p = p->previous;
		free(tmp);
		tmp = p;
		new = (t_pile *)malloc(sizeof (t_pile));
		add_new_element(&p, &new, var);
	}
	return (tmp);
}

t_operations	*enfiler(t_operations *f, char *op)
{
	t_operations	*new;
	t_operations	*tmp;

	new = (t_operations *)malloc(sizeof(t_operations));
	if (new)
	{
		new->next = NULL;
		new->op = op;
		if (f == NULL)
			return (new);
		else
		{
			tmp = f;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	return (f);
}
