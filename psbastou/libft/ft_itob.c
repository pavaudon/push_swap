/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 20:56:24 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/20 11:18:24 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_itob2(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] == '0')
		cpt++;
	while ((ft_strlen(&str[cpt]) % 4) != 0)
		cpt--;
	return (ft_strdup(&str[cpt]));
}

char		*ft_itob(int nb)
{
	int		bin;
	int		cpt;
	char	*str;

	bin = 4096;
	cpt = -1;
	str = (char *)malloc(sizeof(char *) * 14);
	str[13] = 0;
	if (nb < 0)
		nb = -nb;
	while (++cpt < 13)
	{
		if (nb >= bin)
		{
			str[cpt] = '1';
			nb = nb - bin;
			bin = (bin % 2) + (bin / 2);
		}
		else
		{
			str[cpt] = '0';
			bin = (bin % 2) + (bin / 2);
		}
	}
	return (ft_itob2(str));
}
