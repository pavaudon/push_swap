/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:41:28 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/01 01:38:22 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	cpt;
	int cpt2;
	int size;

	cpt = 0;
	cpt2 = 0;
	size = ft_strlen(s2);
	if (size == 0)
		return ((char *)s1);
	while (s1[cpt])
	{
		while (s2[cpt2] == s1[cpt + cpt2])
		{
			if (cpt2 == size - 1)
				return ((char *)&s1[cpt]);
			cpt2++;
		}
		cpt2 = 0;
		cpt++;
	}
	return (NULL);
}
