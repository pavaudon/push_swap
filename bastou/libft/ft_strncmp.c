/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:03:07 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/01 13:33:09 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cpt;

	cpt = 0;
	while (s1[cpt] == s2[cpt] && s1[cpt] && s2[cpt] && cpt < n)
		cpt++;
	if (cpt == n)
		return (0);
	return ((unsigned char)s1[cpt] - (unsigned char)s2[cpt]);
}
