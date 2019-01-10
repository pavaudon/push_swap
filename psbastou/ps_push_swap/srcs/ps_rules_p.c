/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rule_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 14:55:40 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/12 16:09:19 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_sa(t_inf *inf)
{
	if (inf->len_a < 2)
		return ;
	ft_swap(&inf->a[0], &inf->a[1]);
	if (inf->print_rules == true)
		ft_putendl("sa");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}

void	rule_sb(t_inf *inf)
{
	if (inf->len_b < 2)
		return ;
	ft_swap(&inf->b[0], &inf->b[1]);
	if (inf->print_rules == true)
		ft_putendl("sb");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}

void	rule_pa(t_inf *inf)
{
	int	tmp;

	if (inf->len_b < 1)
		return ;
	tmp = inf->b[0];
	push_up_sort(inf->b, inf->len_b--);
	if (inf->len_a > 0)
		push_back_sort(inf->a, ++inf->len_a);
	else
		inf->len_a++;
	inf->a[0] = tmp;
	if (inf->print_rules == true)
		ft_putendl("pa");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}

void	rule_pb(t_inf *inf)
{
	int	tmp;

	if (inf->len_a < 1)
		return ;
	tmp = inf->a[0];
	push_up_sort(inf->a, inf->len_a--);
	if (inf->len_b > 0)
		push_back_sort(inf->b, ++inf->len_b);
	else
		inf->len_b++;
	inf->b[0] = tmp;
	if (inf->print_rules == true)
		ft_putendl("pb");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}
