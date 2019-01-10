/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:43:52 by bchanot           #+#    #+#             */
/*   Updated: 2015/11/28 21:43:59 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cpt;
	size_t	dest_end;

	cpt = 0;
	while (dst[cpt] && cpt < size)
		cpt++;
	dest_end = cpt;
	while (src[cpt - dest_end] && cpt < size - 1)
	{
		dst[cpt] = src[cpt - dest_end];
		cpt++;
	}
	if (cpt < size)
		dst[cpt] = '\0';
	return (dest_end + ft_strlen(src));
}
