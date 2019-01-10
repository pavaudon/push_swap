/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_take_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:13:21 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/25 06:08:51 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	take_arg_help(t_inf *inf, int ac, char **av, int arg)
{
	char	**list;
	int		i;
	int		j;
	int		tmp;

	inf->a = (int *)ft_memalloc(sizeof(int) * (inf->len));
	inf->b = (int *)ft_memalloc(sizeof(int) * (inf->len));
	i = arg;
	tmp = -1;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
			inf->a[++tmp] = ft_atoi(list[j]);
		ft_memdel2((void ***)&list);
	}
	inf->len_a = inf->len;
	inf->len_b = 0;
}

static int	exit_free_tmp(char **list, char *tmp)
{
	ft_memdel((void **)&tmp);
	ft_memdel2((void ***)&list);
	return (_ERROR_);
}

int			take_arg(t_inf *inf, int ac, char **av, int arg)
{
	int		i;
	int		j;
	char	**list;
	char	*tmp;
	int		len;

	i = arg;
	inf->len = 0;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
		{
			len = ft_atoi(list[j]);
			tmp = ft_itoa(len);
			if (!ft_strisdigit(list[j]) || ft_strcmp(list[j], tmp))
				return (exit_free_tmp(list, tmp));
			inf->len++;
		}
		ft_memdel2((void ***)&list);
	}
	take_arg_help(inf, ac, av, arg);
	return (_SUCCESS_);
}

static void	make_pa(t_inf *inf)
{
	while (inf->len_b > 2)
	{
		if (inf->b[0] == take_max(inf->b, inf->len_b))
			rule_pa(inf);
		if (inf->len_b == 2)
			break;
		if (is_rb(inf) && inf->b[0] != take_max(inf->b, inf->len_b))
			rule_rb(inf);
		else if (inf->b[0] != take_max(inf->b, inf->len_b))
			rule_rrb(inf);
	}
	if (inf->b[0] < inf->b[1])
		rule_sb(inf);
	rule_pa(inf);
	rule_pa(inf);
}

int			check_five_less(t_inf *inf)
{
	while (inf->len_a > 3 && !check_sort(inf->a, inf->len_a))
	{
		if (inf->a[0] == take_min(inf->a, inf->len_a))
			rule_pb(inf);
		if (inf->len_a > 3 && is_rabis(inf, take_min(inf->a, inf->len_a)))
			rule_ra(inf);
		else if (inf->len > 3)
			rule_rra(inf);
	}
	while (!check_sort(inf->a, inf->len_a))
	{
		if (inf->len_a > 2 &&inf->a[0] == take_max(inf->a, inf->len_a) &&
			inf->a[1] > inf->a[2])
			rule_ra(inf);
		if (inf->a[0] > inf->a[1])
			rule_sa(inf);
		else
			rule_rra(inf);
	}
	if (!check_sort(inf->a, inf->len_a) || inf->len_b)
		make_pa(inf);
	if (check_sort(inf->a, inf->len_a) && !inf->len_b)
		return (_SUCCESS_);
	return (_ERROR_);
}
