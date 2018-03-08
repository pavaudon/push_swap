/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:53:38 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/08 15:53:40 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabndup(int *tab, int n)
{
	int		*new;
	int		size;
	int		i;

	i = 0;
	size = (ft_inttablen(tab) >= n) ? (n + 1) : (ft_inttablen(tab) + 1);
	if (!(new = (int*)ft_memalloc(sizeof(int) * size)))
		return (NULL);
	while (tab[i] && i < n)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}
