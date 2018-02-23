/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:52:01 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/05 13:52:04 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sign(intmax_t *nb)
{
	if (*nb < 0)
	{
		*nb = -(*nb);
		return (1);
	}
	return (0);
}

char			*ft_intmaxtoa_base(intmax_t n, int base)
{
	char	*str;
	int		len;

	len = ft_max_base_len(n, base);
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	if (sign(&n))
		str[0] = '-';
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
