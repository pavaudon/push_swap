/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:30:25 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/12 19:22:57 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rule_ra(t_inf *inf)
{
	int	tmp;

	tmp = inf->a[0];
	push_up_sort(inf->a, inf->len_a);
	inf->a[inf->len_a - 1] = tmp;
}

void	rule_rb(t_inf *inf)
{
	int	tmp;

	tmp = inf->b[0];
	push_up_sort(inf->b, inf->len_b);
	inf->b[inf->len_b - 1] = tmp;
}

void	rule_rra(t_inf *inf)
{
	int	tmp;

	tmp = inf->a[inf->len_a - 1];
	push_back_sort(inf->a, inf->len_a);
	inf->a[0] = tmp;
}

void	rule_rrb(t_inf *inf)
{
	int	tmp;

	tmp = inf->b[inf->len_b - 1];
	push_back_sort(inf->b, inf->len_b);
	inf->b[0] = tmp;
}

void	freeinf(t_inf *inf)
{
	inf->list = freelist(inf->list);
	ft_memdel((void **)&inf->a);
	ft_memdel((void **)&inf->b);
}
