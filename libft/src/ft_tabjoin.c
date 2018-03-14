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

int		*ft_tabjoin(int *tab, int *to_add, int tablen, int to_addlen, char to_free)
{
	int *new;

	if (!(new = (int*)ft_memalloc(sizeof(int) * (tablen + to_addlen))))
		return (NULL);
	ft_tabcpy(tab, new, tablen);
	ft_tabcpy(to_add, new + tablen, to_addlen);
	if (to_free == 'f' || to_free == 'b')
		ft_memdel((void**)&tab);
	if (to_free == 's' || to_free == 'b')
		ft_memdel((void**)&to_add);
	return (new);
}
