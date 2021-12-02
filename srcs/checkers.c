/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellacroi <ellacroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:51:52 by ellacroi          #+#    #+#             */
/*   Updated: 2021/12/02 15:08:37 by ellacroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	check_integer(char **av)
{
	int			i;
	long long	num;

	i = 1;
	while (av[i])
	{
		num = ft_atoi_long_long(av[i]);
		if (num < -2147483648 || num > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	check_dupli(char **av, t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	a->unsorted_list = malloc(sizeof(int) * (a->size));
	if (a->unsorted_list == NULL)
		return (write(2, "Error\na->unsorted_list malloc failed\n", 29));
	if (check_integer(av) != 0)
		return (write(2, "Error\nBad integer in args\n", 26));
	while (i++ < a->size)
		a->unsorted_list[i - 1] = ft_atoi(av[i]);
	i = 0;
	while (i < a->size - 1)
	{
		j = i;
		while (j++ < a->size - 1)
			if (a->unsorted_list[i] == a->unsorted_list[j])
				return (write(2, "Error\nDuplicates in args\n", 25));
		i++;
	}
	return (0);
}

int	check_args(char **av, t_stack *a)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (ft_isdigit(av[i][j]) || av[i][j] == '-')
			j++;
		if (av[i][j] != '\0' || !(ft_isdigit(av[i][j - 1])))
			return (write(2, "Error\nWrong character in args\n", 30));
		i++;
	}
	a->size = i - 1;
	if (check_dupli(av, a))
		return (1);
	return (0);
}
