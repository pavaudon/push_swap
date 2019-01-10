/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:06:29 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/23 14:43:43 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			cpt;

	cpt = 0;
	if (s && n)
	{
		str = (unsigned char *)s;
		while (cpt < n)
		{
			if (*str == (unsigned char)c)
				return ((void *)str);
			cpt++;
			str++;
		}
	}
	return (NULL);
}
