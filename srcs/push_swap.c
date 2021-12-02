/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:29:45 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:15:11 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_list(t_stack *a)
{
	int	i;

	i = 0;
	if (is_sorted(a->unsorted_list, a->size) == 0)
		return (1);
	a->sorted_list = malloc(sizeof(int) * a->size);
	if (a->sorted_list == NULL)
		return (1);
	while (i < a->size)
	{
		a->sorted_list[i] = a->unsorted_list[i];
		i++;
	}
	ft_sort_int_tab(a->sorted_list, a->size);
	return (0);
}

int	fill_stack(t_stack *a)
{
	int			i;
	t_element	*element;

	i = 0;
	element = NULL;
	while (i < a->size)
	{
		element = new_element(a->unsorted_list[i]);
		add_back(a, element);
		i++;
	}
	return (0);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (sort_list(a) != 0)
		return ;
	if (fill_stack(a) != 0)
		return ;
	if (a->size == 2)
		swap(a);
	else if (a->size == 3)
		algo_3(a);
	else if (a->size <= 5)
		algo_5(a, b);
	else if (a->size <= 100)
		algo_100(a, b);
	else if (a->size > 100)
		algo_500(a, b);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	init_stacks(&a, &b);
	if (ac == 1)
		return (write(2, "Error\nLack of argument\n", 23));
	else if (check_args(av, &a) != 0)
		write(2, "Error\nBad arguments\n", 20);
	else
	{
		push_swap(&a, &b);
	}
	free_memory(&a, &b);
	return (0);
}
