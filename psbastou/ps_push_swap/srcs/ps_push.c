/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 14:16:48 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/25 06:02:19 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_up_sort(int *t, int len)
{
	int	i;

	i = -1;
	while (++i < len - 1)
		t[i] = t[i + 1];
	t[len - 1] = 0;
}

void	push_back_sort(int *t, int len)
{
	while (--len > 0)
		t[len] = t[len - 1];
	t[len] = 0;
}

int		is_rb(t_inf *inf)
{
	int cpt;
	int cpt2;
	int cpt3;

	cpt = 0;
	while (inf->b[cpt] != take_max(inf->b, inf->len_b))
		cpt++;
	cpt2 = inf->len_b - 1;
	cpt3 = 0;
	while (inf->b[cpt2] != take_max(inf->b, inf->len_b))
	{
		cpt2--;
		cpt3++;
	}
	return (cpt > cpt3 ? 0 : 1);
}

int		is_ra(t_inf *inf, int pivot)
{
	int cpt;
	int cpt2;
	int cpt3;

	cpt = 0;
	while (inf->a[cpt] >= pivot)
		cpt++;
	cpt3 = 0;
	cpt2 = inf->len_a - 1;
	while (inf->a[cpt2] >= pivot)
	{
		cpt2--;
		cpt3++;
	}
	return (cpt > cpt3 ? 0 : 1);
}

int		is_rabis(t_inf *inf, int pivot)
{
	int cpt;
	int cpt2;
	int cpt3;

	cpt = 0;
	while (inf->a[cpt] > pivot)
		cpt++;
	cpt3 = 0;
	cpt2 = inf->len_a - 1;
	while (inf->a[cpt2] > pivot)
	{
		cpt2--;
		cpt3++;
	}
	return (cpt > cpt3 ? 0 : 1);
}
