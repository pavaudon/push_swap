/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:17:06 by bchanot           #+#    #+#             */
/*   Updated: 2016/06/13 21:54:15 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_hexlen(unsigned int n)
{
	if (n >= 16)
		return (pf_hexlen(n / 16) + pf_hexlen(n % 16));
	else
		return (1);
}

int	pf_octlen(unsigned int n, t_inf inf)
{
	if (n == 0 && !inf.width && inf.prec <= 0)
		return (0);
	if (n >= 8)
		return (pf_octlen(n / 8, inf) + pf_hexlen(n % 8));
	else
		return (1);
}

int	pf_hexulen(long long unsigned int n)
{
	if (n >= 16)
		return (pf_hexulen(n / 16) + pf_hexulen(n % 16));
	else
		return (1);
}

int	pf_octulen(long long unsigned int n, t_inf inf)
{
	if (n == 0 && !inf.width && inf.prec <= 0)
		return (0);
	if (n >= 8)
		return (pf_octulen(n / 8, inf) + pf_hexulen(n % 8));
	else
		return (1);
}
