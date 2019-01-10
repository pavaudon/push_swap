/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:55:46 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/11 21:31:21 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_width_o_up(long long unsigned int nb, t_inf inf, int len)
{
	if (inf.prec > pf_octulen(nb, inf))
	{
		if (len < inf.width - (inf.prec + inf.di))
			return (1);
	}
	else if (len < inf.width - (pf_octulen(nb, inf) + inf.di))
		return (1);
	return (0);
}

int			pf_o_up(va_list ap, t_inf inf)
{
	long long unsigned int	nb;
	int						len;
	int						cpt;

	nb = va_arg(ap, long long unsigned int);
	len = 0;
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_o_up(nb, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 1 && inf.prec == 0 ? '0' : ' ');
	if (inf.di && (nb != 0 || (nb == 0 && inf.prec > 0)) && len++ >= 0)
		ft_putchar('0');
	cpt = -1;
	while (++cpt < inf.prec - pf_octulen(nb, inf) - inf.di && len++ >= 0)
		ft_putchar('0');
	len += pf_putuoctal(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}
