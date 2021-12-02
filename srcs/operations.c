/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:38:48 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:07:30 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top->next)
	{
		printf("s%c\n", stack->name);
		tmp = stack->top->next->num;
		stack->top->next->num = stack->top->num;
		stack->top->num = tmp;
	}
	else
		return ;
}

void	push(t_stack *receiver, t_stack *donor)
{
	t_element	*tmp;

	if (donor->top)
	{
		printf("p%c\n", receiver->name);
		tmp = donor->top;
		if (donor->top->next)
		{
			donor->top->next->prev = NULL;
			donor->top = donor->top->next;
		}
		else
			donor->top = NULL;
		add_front(receiver, tmp);
		donor->size -= 1;
		receiver->size += 1;
	}
	else
		return ;
}

void	rotate(t_stack *stack)
{
	t_element	*element;

	if (stack->top->next)
	{
		printf("r%c\n", stack->name);
		element = stack->top;
		stack->top = stack->top->next;
		stack->top->prev = NULL;
		add_back(stack, element);
	}
	else
		return ;
}

void	reverse_rotate(t_stack *stack)
{
	t_element	*element;

	if (stack->top->next)
	{
		printf("rr%c\n", stack->name);
		element = stack->bot;
		stack->bot = stack->bot->prev;
		stack->bot->next = NULL;
		add_front(stack, element);
	}
	else
		return ;
}
