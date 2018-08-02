/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:15:53 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 11:16:01 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_nb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || (str[i] == '-' && i == 0))
		{
			i++;
			while (str[i] && (ft_isdigit(str[i])))
				i++;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_is_int(char *str)
{
	if (ft_atoi(str) && ft_atoi(str) <= 2147483647)
		return (1);
	return (0);
}

int		ft_check_data(char **argv, int j, int size)
{
	char	**tmp;
	int		i;

	while (++j < size)
	{
		if (ft_strchr(argv[j], ' '))
		{
			i = -1;
			tmp = ft_strsplit(argv[j], ' ');
			while (tmp[++i])
			{
				if (!ft_is_nb(tmp[i]) || !ft_is_int(tmp[i]))
					return (0);
			}
			free(tmp);
		}
		else
		{
			if (!ft_is_nb(argv[j]) || !ft_is_int(argv[j]))
				return (0);
		}
	}
	return (1);
}

int		ft_is_in_tab(char **tab, int value)
{
	while (tab)
	{
		if (value == ft_atoi(*tab))
			return (0);
		tab++;
	}
	return (1);
}

int		ft_strtablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_again_in_tab(char **tab, int *j, int value, int len)
{
	if (*j < (len - 1))
	{
		if (!(ft_is_in_tab(tab + 1, value)))
			return (0);
		*j += 1;
	}
	else
	{
		*j = 0;
		free(tab);
	}
	return (1);
}

char	**ft_filltabvalue(char *str, int *len)
{
	char **tab;

	tab = ft_strsplit(str, ' ');
	*len = ft_strtablen(tab);
	return (tab);
}

int		ft_is_again(char **argv, int argc, int value)
{
	int		i;
	int		j;
	int		len;
	char	**tab;

	i = 0;
	j = 0;
	while (++i < argc - 1)
	{
		if (ft_strchr(argv[i], ' ') && !tab)
			tab = ft_filltabvalue(argv[i], &len);
		value = !tab ? ft_atoi(argv[i]) : ft_atoi(tab[j]);
		if (tab && j < len && !ft_again_in_tab(tab, &j, value, len))
			return (0);
		else if (ft_strchr(argv[i + 1], ' ') &&
		!ft_is_in_tab(ft_strsplit(argv[i + 1], ' '), value))
			return (0);
		else
		{
			if (value == ft_atoi(argv[i + 1]))
				return (0);
		}
	}
	return (1);
}
