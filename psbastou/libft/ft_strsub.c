/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:22:34 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/03 16:13:30 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	cpt;

	str = ft_strnew(len);
	if (!s || start > ft_strlen(s) || !str)
		return (NULL);
	cpt = 0;
	while (cpt < len && s[start])
	{
		str[cpt] = s[start];
		cpt++;
		start++;
	}
	str[cpt] = '\0';
	return (str);
}
