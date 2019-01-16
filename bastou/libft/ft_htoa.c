/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 19:54:05 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/15 21:41:51 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	valuehex(int x)
{
	if (x >= 0 && x <= 9)
		return (48 + x);
	else if (x >= 10 && x <= 15)
	{
		x = x - 10;
		return (97 + x);
	}
	return (0);
}

char		*ft_htoa(long long unsigned int nb)
{
	long long unsigned int	x;
	char					*str;
	int						cpt;

	x = nb;
	cpt = 0;
	while (x > 16)
	{
		x /= 16;
		cpt++;
	}
	str = (char *)malloc(sizeof(char *) * cpt + 1);
	if (str)
	{
		str[cpt + 1] = '\0';
		while (cpt >= 0)
		{
			x = nb % 16;
			str[cpt] = valuehex(x);
			nb /= 16;
			cpt--;
		}
	}
	return (str);
}
