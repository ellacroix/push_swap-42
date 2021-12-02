/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:09:31 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:12:39 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	element_index(t_stack *stack, t_element *element)
{
	int			index;
	t_element	*tmp;

	index = 0;
	tmp = stack->top;
	while (tmp && tmp != element)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

void	bring_to_top(t_stack *stack, t_element *element)
{
	int	middle;
	int	index;

	if (!stack)
		return ;
	if (stack->top == element)
		return ;
	middle = (stack->size - 1) / 2;
	index = element_index(stack, element);
	if (index <= middle)
		while (index-- != 0)
			rotate(stack);
	else
		while (index++ != stack->size)
			reverse_rotate(stack);
}

int	is_stack_sorted(t_stack *a)
{
	t_element	*ptr;

	ptr = a->top;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
