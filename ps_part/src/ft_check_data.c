/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:54:15 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/19 16:12:12 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_nb(char *str)
{
	int	i;
	int	arg;

	i = 0;
	while (str[i])
	{
		if (i > 0 && str[i] && (str[i] == ' ' || str[i] == ' '))
			i++;
		arg = 0;
		if ((str[i] == '-' && arg == 0) || ft_isdigit(str[i]))
		{
			i++;
			while (str[i] && (ft_isdigit(str[i])))
			{
				i++;
				arg++;
			}
			if (str[i] && str[i] == '-')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	n;
	int		neg;
	int		i;

	n = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10;
		n = n + (str[i] - 48);
		i++;
	}
	return (n * neg);
}

int		ft_int_max_min(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if ((str[0] == '-' && i > 11) || i > 10)
		return (0);
	if (str[0] == '-' && ft_atol(str) < -2147483648)
		return (0);
	if (str[0] != '-' && ft_atol(str) > 2147483647)
		return (0);
	return (1);
}

int		ft_is_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_int_max_min(&str[i]))
			return (0);
		if (str[i] == '-')
		{
			i++;
			if (!str[i] || !ft_isdigit(str[i]))
				return (0);
		}
		while (str[i] && (ft_isdigit(str[i])))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '	'))
			i++;
	}
	return (1);
}

int		ft_check_data(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_is_nb(argv[i]) || !ft_is_int(argv[i]))
			return (0);
	}
	return (1);
}
