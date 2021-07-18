#ifndef CHECKER_H
# define CHECKER_H

# include<stdio.h>
# include<stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int				data;
	int				index;
	int				bool;
	struct s_pile	*previous;
}	t_pile;

typedef struct s_var
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;
}	t_var;

typedef struct s_stack
{
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lst
{
	t_stack			*p;
	struct s_lst	*next;
}	t_lst;

typedef struct s_operations
{
	char				*op;
	struct s_operations	*next;
}	t_operations;

void			print_instructions(t_operations *queue);
int				is_numberr(char *str);
void			reverse_rotate_a_b(t_pile **stack_a, t_pile **stack_b);
void			rotate_a_b(t_pile **stack_a, t_pile **stack_b);
void			swap_a_b(t_pile **stack_a, t_pile **stack_b);
void			check_dups(t_pile *a, int i, int j);
void			add_new_element(t_pile **p, t_pile **new, t_var var);
int				cost_b(t_pile *b, int t[], int index);
int				*duplicate_tab(int t[], int j);
t_pile			*markup_stack(t_pile *a, int tab[], int j);
int				*fill_tab(t_pile *p);
int				*fill_tab_1(t_pile *p);
t_pile			*duplicate(t_pile *a);
void			fill_index(t_pile *p, t_pile **a, int t[], int *size);
t_pile			*keep_in_a(t_pile *a);
int				is_number(char *str);
t_pile			*ft_fill_index(t_pile *a, int size);
int				max_stack(t_pile *b);
int				is_sup(t_pile *p, int index);
int				last(t_pile *a);
int				min_stack(t_pile *b);
int				max_b(t_pile *p);
int				min_index(int t[], t_pile *p);
void			find_right_place(t_pile *a, t_var *var, int ta[], int tb[]);
void			find_best_conditions(t_pile *a, t_pile *b, t_var *var,
					int *index_min);
int				find_best(t_pile *a, t_pile *b, int **tab, int max);
int				cost_a(t_pile *a, int ta[], int index, int max);
void			finalize(t_pile **a, t_operations **queue);
void			choose_to_push(t_pile **a, t_pile **b,
					t_operations **queue, int *i);
void			from_a_to_b(t_pile **a, t_pile **b, t_operations **queue);
void			push_1(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			push_6(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			push_5(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			push_4(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			push_3(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			push_2(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			push_7(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			cost_calculate(t_pile **a, t_pile **b, t_var *var);
void			push_8(t_pile **a, t_pile **b, t_operations **queue, t_var var);
void			push_b_to_a(t_pile **a, t_pile **b, t_operations **queue,
					t_var var);
int				ft_strcmp(char *s1, char *s2);
int				get_next_line(char **line);
void			ft_error(void);
void			ft_putchar_fd(char c, int fd);
long			ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);
t_stack			*ft_push_st(t_stack *pile, int index);
t_lst			*ft_push_list(t_lst *list, t_stack *pile);
t_operations	*enfiler(t_operations *f, char *op);
t_pile			*ft_push(t_pile *pile, int data, int index);
void			ft_push_ab(t_pile **a, t_pile **b);
int				depiler(t_pile **a);
t_pile			*rotate_ab(t_pile *p);
t_pile			*reverse_rotate_ab(t_pile *p);
t_pile			*swap_ab(t_pile *p);
int				stack_size(t_pile *a);
int				check_rotate(t_pile *p);
int				check_reverse_rotate(t_pile *p);
int				check_sort_a(t_pile *a);
int				check_sort_b(t_pile *b);
int				check_stack_max(t_pile *b);
int				check_stack_min(t_pile *b);
void			echanger(int t[], int i, int j);
int				minimum(int t[], int i_min, int i_max);
void			tri_selection(int t[], int n);
int				ft_mediane(t_pile *p);
int				get_second_element(t_pile *p);
int				get_last_element(t_pile *p);
t_operations	*push_swap(t_pile **a, t_pile **b);
void			message(char *str);
int				find_element(t_pile *p, int element);
int				choose_op(t_pile *p);
int				choose_op_a(t_pile *p);
int				check(t_pile *a, t_pile *b);
int				check_under_mediane(t_pile *p, int mediane);
void			ft_putstr_fd(char *s, int fd);
int				get_index(t_pile *p, int m, int n);
void			push_ra(t_operations **queue, t_pile **a, t_pile **b,
					int index);
int				ft_find_index(t_pile *a, int chunk);
int				ft_get_index(t_pile *a, int index);
void			push_rra(t_operations **queue, t_pile **a, t_pile **b,
					int index);
void			push_rb(t_operations **queue, t_pile **a, t_pile **b,
					int index);
void			push_rrb(t_operations **queue, t_pile **a, t_pile **b,
					int index);
int				test_rrr(t_pile *p);

#endif
