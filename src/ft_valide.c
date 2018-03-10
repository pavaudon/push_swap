/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:24:53 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 17:24:54 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(int *tab, t_both *both)
{
	int i;
	int j;

	j = 0;
	if (both->the_size == 1)
		return (1);
	while (tab[++j])
	{
		i = j - 1;
		if (tab[i] > tab[j])
			return (0);
	}
	return (1);
}
void	ft_current_data(t_both *both)
{
	both->stack_a->min = ft_get_min_max(both->stack_a->tab, "min");
	both->stack_b->min = ft_get_min_max(both->stack_b->tab, "min");
	both->stack_a->max = ft_get_min_max(both->stack_a->tab, "max");
	both->stack_b->max = ft_get_min_max(both->stack_b->tab, "max");
}

int     ft_is_good_int(char *str)
{
	int i;

	i = -1;
	while (str[i++])
	{
    	if (!ft_isdigit(str[i]) && str[0] != '-')
      		return (-1);
	}
	if (!ft_atoi(str))
    	return (-1);
	return (1);
}

int     ft_checkarg(int argc, char **argv)
{
	int i;
	int tmp;
	int j;
	int value;

	j = 0;
	while (++j < argc)
	{
    	i = 0;
    	while (++i < argc)
    	{
			value = ft_atoi(argv[i]);
			tmp = ft_atoi(argv[j]);
			if (tmp == value)
				return (-1);
		}
	}
	return (1);
}
