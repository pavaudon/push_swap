/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:45:37 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/23 14:21:29 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *t;

	t = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		t[len] = (unsigned char)c;
	}
	b = (void *)t;
	return (b);
}
