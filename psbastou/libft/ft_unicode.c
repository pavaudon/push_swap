/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 01:44:46 by bchanot           #+#    #+#             */
/*   Updated: 2016/03/15 17:13:04 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <locale.h>

char	*ft_widechar(wchar_t c)
{
	char	str[5];

	ft_bzero(str, 5);
	if (c < 128)
		str[0] = (char)c;
	else if (c < 2048)
	{
		str[0] = (c >> 6) + 192;
		str[1] = (c & 63) + 128;
	}
	else if (c < 65536)
	{
		str[0] = (c >> 12) + 224;
		str[1] = ((c >> 6) & 63) + 128;
		str[2] = (c & 63) + 128;
	}
	else if (c < 1114112)
	{
		str[0] = (c >> 18) + 240;
		str[1] = ((c >> 12) & 63) + 128;
		str[2] = ((c >> 6) & 63) + 128;
		str[3] = (c & 63) + 128;
	}
	return (ft_strdup(str));
}

char	*ft_widestr(wchar_t *src)
{
	char *str;
	char *ante;
	char *post;

	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*src)
	{
		ante = str;
		if (!(post = ft_widechar(*src)))
			return (NULL);
		if (!(str = ft_strjoin(ante, post)))
			return (NULL);
		src++;
		ft_strdel(&ante);
		ft_strdel(&post);
	}
	return (str);
}
