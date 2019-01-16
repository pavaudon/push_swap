/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:54:45 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/01 01:15:23 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	cpt;

	cpt = 0;
	if (dst && src && n)
	{
		while (cpt < n)
		{
			*((char *)dst + cpt) = *((char *)src + cpt);
			if (*((char *)src + cpt) == (char)c)
			{
				return ((char *)dst + cpt + 1);
			}
			cpt++;
		}
	}
	return (NULL);
}
