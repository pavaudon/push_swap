/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:04:16 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/08 16:04:18 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabdup(int *tab)
{
	int i;
	int *new;

	i = 0;
	if (!(new = (int*)ft_memalloc(sizeof(int) * ft_inttablen(tab))))
		return (NULL);
	while (tab[i])
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}
