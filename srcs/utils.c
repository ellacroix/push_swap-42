/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 11:43:22 by ellacroi          #+#    #+#             */
/*   Updated: 2021/06/28 15:25:14 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_aprox(float f)
{
	int	i;

	i = (int) f;
	if ((f - i) >= 0.5)
		return ((int) f + 1);
	else
		return ((int) f);
}

int	smallest_num(t_stack *stack)
{
	t_element	*tmp;
	int			smallest;

	tmp = stack->top;
	smallest = tmp->num;
	while (tmp)
	{
		if (tmp->num < smallest)
			smallest = tmp->num;
		tmp = tmp->next;
	}
	return (smallest);
}