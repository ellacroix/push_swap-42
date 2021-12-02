/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:42:06 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:12:49 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3(t_stack *a)
{
	if (a->top->num < a->top->next->num && a->top->num < a->bot->num)
	{
		swap(a);
		rotate(a);
	}
	else if (a->top->num > a->top->next->num && a->top->num > a->bot->num)
	{
		if (a->bot->num < a->bot->prev->num)
		{
			swap(a);
			reverse_rotate(a);
		}
		else if (a->bot->num > a->bot->prev->num)
			rotate(a);
	}
	else if (a->bot->num > a->bot->prev->num)
		swap(a);
	else
		reverse_rotate(a);
}

void	algo_5(t_stack *a, t_stack *b)
{
	t_element	*smallest;

	while (a->size > 3)
	{
		smallest = find_smallest(a);
		bring_to_top(a, smallest);
		push(b, a);
	}
	if (is_stack_sorted(a) == 1)
		algo_3(a);
	push(a, b);
	push(a, b);
}
