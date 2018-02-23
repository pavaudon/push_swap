/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:52:50 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/05 13:52:51 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uintmaxtoa_base(uintmax_t n, int base)
{
	char		*str;
	int			len;

	len = ft_umax_base_len(n, base);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	while (len--)
	{
		if ((n % base) >= 10)
			str[len] = (n % base) - 10 + 'A';
		else
			str[len] = n % base + '0';
		n = n / base;
	}
	return (str);
}
