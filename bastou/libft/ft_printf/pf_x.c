/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:56:52 by bchanot           #+#    #+#             */
/*   Updated: 2016/06/13 21:57:58 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_width_xl(long long unsigned int nb, t_inf *inf, int len)
{
	int i;

	i = nb == 0 && inf->prec == -1 && inf->width ? 0 : pf_hexulen(nb);
	if (inf->prec > pf_hexulen(nb))
	{
		if (len < inf->width - (inf->prec + inf->di * 2))
			return (1);
	}
	else if (len < inf->width - (pf_hexulen(nb) + inf->di * 2))
		return (1);
	return (0);
}

static int	pf_width_x(unsigned int nb, t_inf inf, int len)
{
	int i;

	i = nb == 0 && inf.prec == -1 ? 0 : pf_hexlen(nb);
	if (inf.prec > i)
	{
		if (len < inf.width - (inf.prec + inf.di * 2))
			return (1);
	}
	else if (len < inf.width - (i + inf.di * 2))
		return (1);
	return (0);
}

static int	pf_xlong(va_list ap, t_inf *inf)
{
	long long unsigned int	nb;
	int						len;
	int						cpt;

	nb = va_arg(ap, long long unsigned int);
	len = 0;
	if (inf->di == 1 && nb != 0 && inf->zero && !inf->prec)
	{
		inf->di = 0;
		len += pf_putstr("0x");
	}
	if (inf->width > 0 && inf->min == 0)
		while (pf_width_xl(nb, inf, len) && len++ >= 0)
			ft_putchar(inf->zero && !inf->prec ? '0' : ' ');
	if (inf->di == 1 && nb != 0)
		len += pf_putstr("0x");
	cpt = -1;
	while (++cpt < inf->prec - pf_hexulen(nb) && len++ >= 0)
		ft_putchar('0');
	return (pf_xlong2(len, inf, nb));
}

static int	pf_x2(unsigned int nb, t_inf inf, int len)
{
	len += pf_puthex(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}

int			pf_x(va_list ap, t_inf inf)
{
	unsigned int	nb;
	int				len;
	int				cpt;

	if (inf.z || inf.l || inf.ll || inf.j)
		return (pf_xlong(ap, &inf));
	nb = inf.hh ? (unsigned char)va_arg(ap, unsigned int) :
		va_arg(ap, unsigned int);
	len = 0;
	if (inf.di == 1 && nb != 0 && inf.zero && !inf.prec)
	{
		inf.di = 0;
		len += pf_putstr("0x");
	}
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_x(nb, inf, len) && len++ >= 0)
			ft_putchar(inf.zero && !inf.prec ? '0' : ' ');
	if (inf.di == 1 && nb != 0)
		len += pf_putstr("0x");
	cpt = -1;
	while (++cpt < inf.prec - pf_hexlen(nb) && len++ >= 0)
		ft_putchar('0');
	return (pf_x2(nb, inf, len));
}
