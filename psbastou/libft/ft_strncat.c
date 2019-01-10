/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:30:39 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/04 01:36:49 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	cpt;
	size_t	cpt2;

	cpt = ft_strlen(s1);
	cpt2 = 0;
	while (cpt2 < n && s2[cpt2])
	{
		s1[cpt] = s2[cpt2];
		cpt++;
		cpt2++;
	}
	s1[cpt] = '\0';
	return (s1);
}
