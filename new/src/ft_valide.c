/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:50:37 by pavaudon          #+#    #+#             */
/*   Updated: 2018/05/17 14:50:39 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_nb_arg(char *str)
{
	int i;
	int	arg;

	arg = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			arg++;
			while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
				i++;
		}
		else if (str[i] == ' ')
			i++;
		else
			return (-1);
	}
	printf("size : '%d'\n", arg);
	return (arg);
}

int		ft_is_good_int(char **arg)
{
	int i;
	int j;

	j = -1;
	while (arg[++j])
	{
		i = -1;
		printf("j : %d\n", j);
		while (arg[j][++i])
		{
			if (!ft_isdigit(arg[j][i]) && arg[j][0] != '-')
				return (-1);
		}
		if (!ft_atoi(arg[j]))
			return (-1);
	}
	return (1);
}

int		ft_checkarg(char **argv)
{
	int i;
	int tmp;
	int j;
	int value;

	j = -1;
	while (argv[++j])
	{
		i = 0;
		tmp = ft_atoi(argv[j]);
		while (++i < j)
		{
			value = ft_atoi(argv[i]);
			if (tmp == value)
				return (0);
		}
	}
	return (1);
}