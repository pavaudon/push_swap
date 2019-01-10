/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:05:01 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/23 14:35:38 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *c_dst;
	char *c_src;

	if (dst == NULL || src == NULL)
		return (NULL);
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (n == 0 || dst == src)
		return ((void *)c_dst);
	while (--n)
	{
		*c_dst = *c_src;
		c_dst++;
		c_src++;
	}
	*c_dst = *c_src;
	return (dst);
}
