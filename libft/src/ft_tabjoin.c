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

int		*ft_tabjoin(int *tab, int *to_add, int tablen, int to_addlen, char where, char to_free)
{
	int *new;
	int	i;

	i = 0;
	if (!(new = (int*)ft_memalloc(sizeof(int) * (tablen + to_addlen))))
		return (NULL);
	if (where == 'b')
	{
		ft_tabcpy(tab, new, tablen);
		i += tablen;
		ft_tabcpy(to_add, new + i, to_addlen);
	}
	else
	{
		ft_tabcpy(to_add, new, to_addlen);
		i += to_addlen;
		ft_tabcpy(tab, new + i, tablen);
	}
	if (to_free == 'f' || to_free == 'b')
		ft_memdel((void*)tab);
	if (to_free == 's' || to_free == 'b')
		ft_memdel((void*)to_add);
	return (new);
}
