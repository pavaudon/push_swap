/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtodst_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:24:52 by pavaudon          #+#    #+#             */
/*   Updated: 2018/02/17 18:25:02 by pavaudon         ###   ########.fr       */
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

char			*ft_intmaxtodst_base(intmax_t n, char *dst, int base)
{
	int		len;

	len = ft_max_base_len(n, base);
	if (n < -9223372036854775807)
		return (ft_strcpy(dst, "-9223372036854775808"));
	if (n == 0)
		return (ft_strcpy(dst, "0"));
	if (sign(&n))
		dst[0] = '-';
	while (len--)
	{
		if ((n % base) >= 10)
			dst[len] = (n % base) - 10 + 'A';
		else
			dst[len] = n % base + '0';
		n = n / base;
	}
	return (dst);
}
