/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:51:54 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/24 06:56:12 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_order(t_inf *inf)
{
	int rb;

	rb = 0;
	while (inf->len_b)
	{
		rb = is_rb(inf);
		while (inf->b[0] != take_max(inf->b, inf->len_b))
			rb ? rule_rb(inf) : rule_rrb(inf);
		rule_pa(inf);
	}
}

static void	preorder(t_inf *inf, int pivot)
{
	int	cpt;
	int	len;
	int ra;

	cpt = -1;
	len = inf->len_a;
	while (take_min(inf->a, inf->len_a) < pivot)
	{
		ra = is_ra(inf, pivot);
		while (inf->a[0] >= pivot)
			ra ? rule_ra(inf) : rule_rra(inf);
		rule_pb(inf);
	}
}

static int	take_div(int len)
{
	if (len >= 8000)
		return (50);
	else if (len >= 4000)
		return (35);
	else if (len >= 2000)
		return (25);
	else if (len >= 1000)
		return (20);
	else if (len >= 500)
		return (14);
	else if (len >= 400)
		return (12);
	else if (len >= 300)
		return (10);
	else if (len >= 200)
		return (8);
	else if (len >= 100)
		return (5);
	else if (len >= 25)
		return (4);
	return (2);
}

static int	is_simple_move(t_inf *inf)
{
	if (inf->print_display == true)
		display(inf);
	if (check_sort(inf->a, inf->len_a))
		return (_SUCCESS_);
	else if (is_reverse(inf))
		return (_SUCCESS_);
	else if (is_it_necessary(inf) == 1)
	{
		while (sort_ra_rra(inf))
			;
		if (check_sort(inf->a, inf->len_a))
			return (_SUCCESS_);
	}
	else if (is_simple_sa(inf))
		return (_SUCCESS_);
	else if (is_it_necessary(inf) == 2)
	{
		while (sort_piece(inf))
			;
		if (check_sort(inf->a, inf->len_a))
			return (_SUCCESS_);
	}
	return (_ERROR_);
}

void		push_swap(t_inf *inf)
{
	int *tmp;
	int cpt;
	int len;
	int mult;

	if (is_simple_move(inf))
		return ;
	cpt = -1;
	tmp = (int *)ft_memalloc(sizeof(int) * (inf->len_a));
	while (++cpt < inf->len_a)
		tmp[cpt] = inf->a[cpt];
	check_list(tmp, 0, inf->len_a - 1);
	cpt = take_div(inf->len_a);
	mult = inf->len_a / cpt;
	len = mult;
	while (cpt-- > 1)
	{
		preorder(inf, tmp[mult]);
		mult += len;
	}
	while (inf->len_a)
		rule_pb(inf);
	ft_memdel((void **)&tmp);
	make_order(inf);
}
