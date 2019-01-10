/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:31:34 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/07 13:09:31 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s_dst;
	char	*s_src;

	if (dst == src && !len)
		return (NULL);
	s_dst = (char *)dst;
	s_src = (char *)src;
	if (s_dst > s_src)
	{
		while (len--)
			s_dst[len] = s_src[len];
	}
	else
		dst = ft_memcpy(dst, (void *)src, len);
	return (dst);
}
