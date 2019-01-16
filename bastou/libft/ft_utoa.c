/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 19:54:05 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/15 21:31:00 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_utoa(long long unsigned int nb)
{
	long long unsigned int	x;
	char					*str;
	int						cpt;

	x = nb;
	cpt = 0;
	while (x > 10)
	{
		x /= 10;
		cpt++;
	}
	str = (char *)malloc(sizeof(char *) * cpt + 1);
	if (str)
	{
		str[cpt + 1] = '\0';
		while (cpt >= 0)
		{
			x = nb % 10;
			str[cpt] = 48 + x;
			nb /= 10;
			cpt--;
		}
	}
	return (str);
}
