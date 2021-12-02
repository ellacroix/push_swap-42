/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:40:17 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:16:06 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <../libft/libft.h>

typedef struct s_element
{
	int					num;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct s_stack
{
	t_element	*top;
	int			size;
	t_element	*bot;
	int			*unsorted_list;
	int			*sorted_list;
	char		name;
}				t_stack;

int			check_args(char **av, t_stack *a);
int			check_integer(char **av);
int			check_dupli(char **av, t_stack *a);
int			is_sorted(int *tab, int size);
int			is_stack_sorted(t_stack *a);

t_element	*new_element(int number);
void		add_back(t_stack *s, t_element *element);
void		add_front(t_stack *s, t_element *element);
t_element	*find_biggest(t_stack *stack);
t_element	*find_smallest(t_stack *stack);
int			element_index(t_stack *stack, t_element *element);
void		bring_to_top(t_stack *stack, t_element *element);
t_element	*closest_element(t_stack *stack, int nbr_max);

void		swap(t_stack *stack);
void		push(t_stack *receiver, t_stack *donor);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

void		algo_3(t_stack *a);
void		algo_5(t_stack *a, t_stack *b);
void		algo_100(t_stack *a, t_stack *b);
void		algo_500(t_stack *a, t_stack *b);
void		sort(t_stack *a, t_stack *b);

void		init_stacks(t_stack *a, t_stack *b);
void		free_memory(t_stack *stack_a, t_stack *stack_b);

int			val_aprox(float f);
int			smallest_num(t_stack *stack);

#endif