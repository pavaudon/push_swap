/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:31:59 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/23 14:29:31 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	char			*src;
	unsigned int	cpt;

	src = (char*)s;
	if (src && f)
	{
		if (!(dst = ft_strnew(ft_strlen(s))))
			return (NULL);
		cpt = 0;
		while (src[cpt])
		{
			dst[cpt] = (*f)(cpt, src[cpt]);
			cpt++;
		}
		return (dst);
	}
	return (NULL);
}
