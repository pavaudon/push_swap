/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:52:02 by pavaudon          #+#    #+#             */
/*   Updated: 2017/11/17 14:57:28 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	size;
	char	*dst;

	if (n == 0)
		return (ft_strdup(""));
	if (ft_strlen(s1) >= n)
		size = n + 1;
	else
		size = ft_strlen(s1) + 1;
	i = 0;
	if (!(dst = (char*)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	while (s1[i] && i < n)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
