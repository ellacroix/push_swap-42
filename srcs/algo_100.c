/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:08:25 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:15:31 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	path_from_top(t_stack *stack, int nbr_max)
{
	int			count;
	t_element	*tmp;

	count = 0;
	tmp = stack->top;
	while (tmp->num > nbr_max)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	path_from_bot(t_stack *stack, int nbr_max)
{
	int			count;
	t_element	*tmp;

	count = 0;
	tmp = stack->bot;
	while (tmp->num > nbr_max)
	{
		count++;
		tmp = tmp->prev;
	}
	return (count);
}

t_element	*closest_element(t_stack *stack, int nbr_max)
{
	t_element	*tmp_top;
	t_element	*tmp_bot;

	tmp_top = stack->top;
	tmp_bot = stack->bot;
	while (1)
	{
		if (tmp_top->num <= nbr_max)
			return (tmp_top);
		else if (tmp_bot->num <= nbr_max)
			return (tmp_bot);
		tmp_top = tmp_top->next;
		tmp_bot = tmp_bot->prev;
	}
}

static void	push_b(t_stack *a, t_stack *b, int denominator)
{
	int	key_nbr;
	int	original_size;
	int	count;

	key_nbr = a->sorted_list[val_aprox(a->size / denominator) - 1];
	original_size = a->size;
	count = 1;
	while (a->size > val_aprox(original_size / denominator))
	{
		if (b->size == val_aprox(count * original_size / denominator))
		{
			count++;
			if (count != denominator)
				key_nbr = a->sorted_list[val_aprox(count * original_size
						/ denominator) - 1];
		}
		if (smallest_num(a) > key_nbr)
			break ;
		bring_to_top(a, closest_element(a, key_nbr));
		push(b, a);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	while (a->size > 0)
	{
		bring_to_top(a, find_smallest(a));
		push(b, a);
	}
	while (b->size > 0)
	{
		bring_to_top(b, find_biggest(b));
		push(a, b);
	}
}

void	algo_100(t_stack *a, t_stack *b)
{
	push_b(a, b, 4);
	sort(a, b);
}
