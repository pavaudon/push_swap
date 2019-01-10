/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:22:02 by bchanot           #+#    #+#             */
/*   Updated: 2015/11/28 23:44:12 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		cpt;

	cpt = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len++;
	while ((cpt < len) && (s[cpt] == ' ' || s[cpt] == '\n' || s[cpt] == '\t'))
		cpt++;
	len -= cpt;
	str = ft_strsub((char *)s, cpt, len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}
