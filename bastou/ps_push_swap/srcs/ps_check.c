/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:19:46 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/21 08:30:37 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_simple_sa(t_inf *inf)
{
	int min;

	min = take_min(inf->a, inf->len_a - 2);
	if (inf->a[inf->len_a - 1] < min && inf->a[inf->len_a - 2] < min)
	{
		rule_rra(inf);
		rule_rra(inf);
		rule_sa(inf);
		if (check_sort(inf->a, inf->len_a))
			return (_SUCCESS_);
	}
	return (_ERROR_);
}

int			sort_ra_rra(t_inf *inf)
{
	int	i;
	int	end;

	if (inf->len_a < 2)
		return (_ERROR_);
	i = -1;
	end = inf->a[inf->len_a - 1];
	if (inf->a[0] > end && end > inf->a[1])
	{
		rule_ra(inf);
		return (_SUCCESS_);
	}
	else if (inf->a[0] > end)
	{
		rule_rra(inf);
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static void	rotate_hard_help(t_inf *inf, int i, int tmp, int tmp2)
{
	int	factor_good;

	factor_good = 0;
	while (inf->a[tmp - 1] < inf->a[tmp])
	{
		factor_good++;
		tmp--;
	}
	tmp2 = inf->len_a;
	tmp = (tmp2 - i) + factor_good;
	while (tmp--)
		rule_rra(inf);
	if (check_sort(inf->a, inf->len_a))
		return ;
	tmp = factor_good + 1;
	if (tmp == 1 && (tmp2 - i) - 1 <= 0)
		return ;
	while (tmp--)
		rule_pb(inf);
	tmp = (tmp2 - i) - 1;
	while (tmp--)
		rule_ra(inf);
	tmp = factor_good + 1;
	while (tmp--)
		rule_pa(inf);
}

int			sort_piece(t_inf *inf)
{
	int	i;
	int	factor_good;

	i = inf->len_a;
	factor_good = 0;
	while (--i >= inf->len_a / 2)
	{
		if (inf->a[i] < inf->a[0])
		{
			rotate_hard_help(inf, i, i, inf->len_a);
			return (_SUCCESS_);
		}
	}
	return (_ERROR_);
}

int			is_it_necessary(t_inf *inf)
{
	int cpt;

	cpt = 0;
	while (cpt < inf->len_a - 1 && inf->a[cpt] < inf->a[cpt + 1])
		cpt++;
	if (cpt == inf->len_a - 1)
		return (_ERROR_);
	cpt++;
	while (cpt < inf->len_a - 1 && inf->a[cpt] < inf->a[cpt + 1] &&
			inf->a[cpt + 1] < inf->a[0])
		cpt++;
	if (inf->a[cpt] > inf->a[0])
		return (_ERROR_);
	else if (cpt == inf->len_a - 1)
		return (1);
	cpt++;
	while (cpt < inf->len_a - 1 && inf->a[cpt] < inf->a[cpt + 1])
		cpt++;
	if (cpt == inf->len_a - 1)
		return (2);
	return (_ERROR_);
}
