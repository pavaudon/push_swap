/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:44:47 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 19:44:49 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabjoin(int *tab, int *to_add, char where, char to_free)
{
	int *new;
	int	i;

	i = 0;
	if (!new = (int*)ft_memalloc(sizeof(int) * (ft_inttablen(tab) + (ft_inttablen(to_add)))))
		return (NULL);
	if (where == 'b')
	{
		ft_tabcpy(tab, new);
		i += ft_inttablen(tab);
		ft_tabcpy(to_add, new + i);
	}
	else
	{
		ft_tabcpy(to_add, new);
		i += ft_inttablen(to_add);
		ft_tabcpy(to_add, new + i);
	}
	if (to_free == 'f' || to_free == 'b')
		ft_memdel((void)&tab);
	if (to_free == 's' || to_free == 'b')
		ft_memdel((void)&to_add);
	return (new);
}
