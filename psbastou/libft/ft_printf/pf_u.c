/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:55:55 by bchanot           #+#    #+#             */
/*   Updated: 2016/06/13 21:57:29 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_width_u(unsigned int nb, t_inf inf, int len)
{
	int i;

	i = nb == 0 && inf.prec == -1 ? 0 : ft_nbrulen(nb);
	if (inf.prec > ft_nbrulen(nb))
	{
		if (len < inf.width - inf.prec)
			return (1);
	}
	else if (len < inf.width - ft_nbrulen(nb))
		return (1);
	return (0);
}

int			pf_u(va_list ap, t_inf inf)
{
	unsigned int	nb;
	int				len;
	int				cpt;

	if (inf.l || inf.ll || inf.z || inf.j)
		return (pf_u_up(ap, inf));
	if (inf.h || inf.hh)
		nb = inf.hh ? (unsigned char)va_arg(ap, unsigned int) :
			(unsigned short)va_arg(ap, unsigned int);
	else
		nb = va_arg(ap, unsigned int);
	len = 0;
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_u(nb, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 1 && inf.prec == 0 ? '0' : ' ');
	cpt = -1;
	while (++cpt < inf.prec - ft_nbrulen(nb) && len++ >= 0)
		ft_putchar('0');
	len += pf_putunbr(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}
