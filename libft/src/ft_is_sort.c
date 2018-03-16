/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:21:53 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/15 16:21:55 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int len)
{
	int i;
	int tmp;
	int j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (tab[++j])
		{
			tmp = tab[i];
			if (tmp > tab[j])
				return (0);
		}
	}
	return (1);
}
