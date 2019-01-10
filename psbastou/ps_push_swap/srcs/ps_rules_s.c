/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:05:27 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/17 10:01:18 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_ss(t_inf *inf)
{
	rule_sa(inf);
	rule_sb(inf);
}

void	rule_rr(t_inf *inf)
{
	rule_ra(inf);
	rule_rb(inf);
}

void	rule_rrr(t_inf *inf)
{
	rule_rra(inf);
	rule_rrb(inf);
}
