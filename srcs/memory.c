/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:57:14 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:12:31 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->unsorted_list = NULL;
	a->sorted_list = NULL;
	a->top = NULL;
	a->bot = NULL;
	a->size = 0;
	a->name = 'a';
	b->unsorted_list = NULL;
	b->sorted_list = NULL;
	b->top = NULL;
	b->bot = NULL;
	b->size = 0;
	b->name = 'b';
}

void	free_memory(t_stack *a, t_stack *b)
{
	t_element	*tmp;

	if (a->unsorted_list != NULL)
		free (a->unsorted_list);
	if (a->sorted_list != NULL)
		free (a->sorted_list);
	while (a->top != NULL)
	{
		tmp = a->top->next;
		free (a->top);
		a->top = tmp;
	}
	while (b->top != NULL)
	{
		tmp = b->top->next;
		free (b->top);
		b->top = tmp;
	}
}
