/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_take_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:34:54 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/25 06:10:45 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		take_max(int *list, int len)
{
	int	max;

	max = -2147483648;
	while (len--)
	{
		if (max < list[len])
			max = list[len];
	}
	return (max);
}

int		take_min(int *list, int len)
{
	int	min;

	min = 2147483647;
	while (len--)
	{
		if (min > list[len])
			min = list[len];
	}
	return (min);
}

int		take_index(t_inf *inf, int present)
{
	int	i;

	i = -1;
	while (++i < inf->len_b)
	{
		if (inf->b[i] == present)
			break ;
	}
	return (i);
}

int		is_reverse(t_inf *inf)
{
	int cpt;

	cpt = 0;
	if (inf->len_a <= 10)
		return (check_five_less(inf));
	while (cpt < inf->len_a - 1)
	{
		if (inf->a[cpt] < inf->a[cpt + 1])
			return (_ERROR_);
		cpt++;
	}
	while (inf->len_a > 1)
	{
		rule_rra(inf);
		if (check_sort(inf->a, inf->len_a) && !inf->len_b)
			return (_SUCCESS_);
		rule_pb(inf);
	}
	while (inf->len_b)
		rule_pa(inf);
	if (check_sort(inf->a, inf->len_a) && !inf->len_b)
		return (_SUCCESS_);
	return (_ERROR_);
}

int		check_sort(int *i, int len)
{
	int cpt;

	cpt = 0;
	while (cpt < len - 1)
	{
		if (i[cpt] > i[cpt + 1])
			return (_ERROR_);
		cpt++;
	}
	return (_SUCCESS_);
}
