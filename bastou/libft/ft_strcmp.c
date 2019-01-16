/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:52:55 by bchanot           #+#    #+#             */
/*   Updated: 2015/11/29 16:42:38 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int cpt;

	cpt = 0;
	while (s1[cpt] == s2[cpt] && s1[cpt] && s2[cpt])
		cpt++;
	return ((unsigned char)s1[cpt] - (unsigned char)s2[cpt]);
}
