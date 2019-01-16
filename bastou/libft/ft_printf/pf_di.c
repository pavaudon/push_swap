/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:52:57 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/11 21:35:08 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		pf_do_if(t_inf *inf, long long int nb, int min)
{
	if (inf->plus && inf->prec == -1 && nb > 0 && inf->width && inf->zero)
	{
		inf->zero = 0;
		inf->prec = 0;
	}
	if (inf->space && inf->plus)
		inf->space = 0;
	if (inf->zero == 1 && (inf->plus || inf->space) && nb >= 0 &&
		min == 0 && inf->prec <= 0)
	{
		ft_putchar(inf->space ? ' ' : '+');
		inf->done = 1;
	}
}

static int	pf_width_di(long int nb, t_inf inf, int len)
{
	int i;

	i = nb == 0 && inf.prec == -1 ? 0 : ft_nbrlen(nb);
	if (nb < 0)
	{
		if (len < inf.width - (inf.prec >= i ? inf.prec + 1 : i))
			return (1);
	}
	else if (len < inf.width - (inf.prec >= i ? inf.prec : i))
		return (1);
	return (0);
}

static int	pf_di2(long int nb, int len, int min, t_inf inf)
{
	int cpt;

	cpt = -1;
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_di(nb, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 1 && inf.prec == 0 ? '0' : ' ');
	if (inf.plus && nb >= 0 && !min && inf.prec >= 0 && inf.done == 0)
		ft_putchar('+');
	else if (inf.space == 1 && nb >= 0 && !min && inf.done == 0)
		ft_putchar(' ');
	if (nb < 0 && len++ >= 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (++cpt < inf.prec - ft_nbrlen(nb) && len++ >= 0)
		ft_putchar('0');
	ft_putnbr(nb);
	len += ft_nbrlen(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}

int			pf_di(va_list ap, t_inf inf)
{
	long int	nb;
	int			len;
	int			min;

	if (inf.l || inf.ll || inf.z || inf.j)
		return (pf_d_up(ap, inf));
	if (inf.hh)
		nb = (char)va_arg(ap, int);
	else
		nb = inf.h ? (short)va_arg(ap, int) : va_arg(ap, int);
	min = 0;
	len = (inf.plus || inf.space) && nb >= 0 ? 1 : 0;
	if (inf.zero == 1 && nb < 0 && inf.prec == 0)
	{
		ft_putchar('-');
		nb = -nb;
		min = 1;
		len++;
	}
	pf_do_if(&inf, nb, min);
	return (pf_di2(nb, len, min, inf));
}
