/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 03:06:18 by bchanot           #+#    #+#             */
/*   Updated: 2016/09/29 18:08:14 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char const *s1, char const c)
{
	char	*str;
	int		cpt;

	if (!s1 || !c)
		return (NULL);
	str = NULL;
	if (!(str = ft_strnew(ft_strlen(s1) + 1)))
		return (NULL);
	ft_strcpy(str, s1);
	cpt = ft_strlen(str);
	str[cpt] = c;
	str[cpt + 1] = '\0';
	return (str);
}
