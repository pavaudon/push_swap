/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:25 by bchanot           #+#    #+#             */
/*   Updated: 2015/11/28 20:50:25 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	cpt;

	cpt = 0;
	while (cpt < n && src[cpt])
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	while (cpt < n)
	{
		dst[cpt] = '\0';
		cpt++;
	}
	return (dst);
}
