/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:46:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/23 20:01:04 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	i = 0;
	if (!s)
		return (NULL);
	tmp_s = (char*)s;
	while (tmp_s[i])
	{
		if (tmp_s[i] == c)
			return (&tmp_s[i]);
		i++;
	}
	if (tmp_s[i] == c)
		return (&tmp_s[i]);
	return (NULL);
}
