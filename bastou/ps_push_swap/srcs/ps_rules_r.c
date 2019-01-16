/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:30:25 by bchanot           #+#    #+#             */
/*   Updated: 2016/09/22 11:47:53 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_ra(t_inf *inf)
{
	int	tmp;

	tmp = inf->a[0];
	push_up_sort(inf->a, inf->len_a);
	inf->a[inf->len_a - 1] = tmp;
	if (inf->print_rules == true)
		ft_putendl("ra");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}

void	rule_rb(t_inf *inf)
{
	int	tmp;

	tmp = inf->b[0];
	push_up_sort(inf->b, inf->len_b);
	inf->b[inf->len_b - 1] = tmp;
	if (inf->print_rules == true)
		ft_putendl("rb");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}

void	rule_rra(t_inf *inf)
{
	int	tmp;

	tmp = inf->a[inf->len_a - 1];
	push_back_sort(inf->a, inf->len_a);
	inf->a[0] = tmp;
	if (inf->print_rules == true)
		ft_putendl("rra");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}

void	rule_rrb(t_inf *inf)
{
	int		tmp;

	tmp = inf->b[inf->len_b - 1];
	push_back_sort(inf->b, inf->len_b);
	inf->b[0] = tmp;
	if (inf->print_rules == true)
		ft_putendl("rrb");
	if (inf->print_display == true)
		display(inf);
	inf->cpt++;
}
