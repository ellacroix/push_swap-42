/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:51:18 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:08:11 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*new_element(int number)
{
	t_element	*elem;

	elem = (t_element *)malloc(sizeof(t_element));
	if (elem == NULL)
		return (NULL);
	elem->num = number;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	add_back(t_stack *stack, t_element *element)
{
	if (stack->top != NULL)
	{
		stack->bot->next = element;
		element->prev = stack->bot;
		stack->bot = element;
		stack->bot->next = NULL;
	}
	else
	{
		stack->top = element;
		stack->bot = stack->top;
		stack->top->next = NULL;
		stack->top->prev = NULL;
	}
}

void	add_front(t_stack *stack, t_element *element)
{
	if (stack->top != NULL)
	{
		stack->top->prev = element;
		element->next = stack->top;
		element->prev = NULL;
		stack->top = element;
	}
	else
	{
		stack->top = element;
		element->next = NULL;
		element->prev = NULL;
		stack->bot = stack->top;
	}
}

t_element	*find_biggest(t_stack *stack)
{
	t_element	*biggest;
	t_element	*tmp;

	tmp = stack->top;
	biggest = stack->top;
	while (tmp)
	{
		if (biggest->num < tmp->num)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}

t_element	*find_smallest(t_stack *stack)
{
	t_element	*smallest;
	t_element	*tmp;

	tmp = stack->top;
	smallest = stack->top;
	while (tmp)
	{
		if (smallest->num > tmp->num)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}
