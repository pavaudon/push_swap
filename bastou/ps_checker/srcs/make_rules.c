/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:46:22 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/24 06:21:11 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		easy_rule(t_inf *inf, char *rule)
{
	if (ft_strncmp(rule, "ss", 2) == 0)
	{
		rule_sa(inf);
		rule_sb(inf);
	}
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		rule_rra(inf);
		rule_rrb(inf);
	}
	else if (ft_strncmp(rule, "rr", 2) == 0)
	{
		rule_ra(inf);
		rule_rb(inf);
	}
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

static int		select_rule(t_inf *inf, char *rule)
{
	if (ft_strncmp(rule, "sa", 2) == 0)
		rule_sa(inf);
	else if (ft_strncmp(rule, "sb", 2) == 0)
		rule_sb(inf);
	else if (ft_strncmp(rule, "pa", 2) == 0)
		rule_pa(inf);
	else if (ft_strncmp(rule, "pb", 2) == 0)
		rule_pb(inf);
	else if (ft_strncmp(rule, "ra", 2) == 0)
		rule_ra(inf);
	else if (ft_strncmp(rule, "rb", 2) == 0)
		rule_rb(inf);
	else if (ft_strncmp(rule, "rra", 3) == 0)
		rule_rra(inf);
	else if (ft_strncmp(rule, "rrb", 3) == 0)
		rule_rrb(inf);
	else if (easy_rule(inf, rule) == 1)
		;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

int				make_rules(t_inf *inf)
{
	t_list	*tmp;

	tmp = inf->list;
	inf->len_a = inf->len;
	inf->len_b = 0;
	while (tmp)
	{
		if (!select_rule(inf, tmp->line))
			return (_ERROR_);
		tmp = tmp->next;
	}
	return (_SUCCESS_);
}

int				ms_free_error(char *tmp, char **list)
{
	ft_memdel((void **)&tmp);
	ft_memdel2((void ***)&list);
	return (_ERROR_);
}
