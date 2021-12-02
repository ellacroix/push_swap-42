/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:04:08 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:13:16 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	algo_500(t_stack *a, t_stack *b)
{
	push_b(a, b, 13);
	sort(a, b);
}
