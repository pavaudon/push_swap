/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:55:02 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/11 21:34:13 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			pf_width_o(unsigned int nb, t_inf inf, int len)
{
	if (inf.prec > pf_octlen(nb, inf))
	{
		if (len < inf.width - (inf.prec + inf.di))
			return (1);
	}
	else if (len < inf.width - (pf_octlen(nb, inf) + inf.di))
		return (1);
	return (0);
}

static unsigned int	pf_check_h(va_list ap, t_inf inf)
{
	unsigned int nb;

	if (inf.hh)
		nb = (unsigned char)va_arg(ap, unsigned int);
	else if (inf.h)
		nb = (unsigned short)va_arg(ap, unsigned int);
	else
		nb = va_arg(ap, unsigned int);
	return (nb);
}

int					pf_o(va_list ap, t_inf inf)
{
	unsigned int	nb;
	int				len;
	int				cpt;

	if (inf.z || inf.l || inf.ll || inf.j)
		return (pf_o_up(ap, inf));
	nb = pf_check_h(ap, inf);
	len = 0;
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_o(nb, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 1 && inf.prec == 0 ? '0' : ' ');
	cpt = -1;
	if (inf.di && (nb != 0 || (nb == 0 && inf.prec > 0)) && len++ >= 0)
		ft_putchar('0');
	while (++cpt < inf.prec - pf_octlen(nb, inf) - inf.di && len++ >= 0)
		ft_putchar('0');
	len += pf_putoctal(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}
