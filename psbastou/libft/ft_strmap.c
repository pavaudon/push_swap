/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:07:42 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/07 19:43:14 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	char	*src;
	size_t	cpt;

	src = (char*)s;
	if (src && f)
	{
		dst = ft_strnew(ft_strlen(s));
		if (!dst)
			return (NULL);
		cpt = 0;
		while (src[cpt])
		{
			dst[cpt] = (*f)(src[cpt]);
			cpt++;
		}
		return (dst);
	}
	return (NULL);
}
