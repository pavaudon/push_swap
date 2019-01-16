/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:14:07 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/01 01:18:00 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			cpt;

	if (!s1 && !s2 && !n)
		return (0);
	cpt = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (cpt < n)
	{
		if (ptr1[cpt] != ptr2[cpt])
			return (ptr1[cpt] - ptr2[cpt]);
		cpt++;
	}
	return (0);
}
