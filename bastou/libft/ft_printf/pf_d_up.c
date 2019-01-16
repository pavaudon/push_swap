/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:52:31 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/29 03:40:25 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_width_d(long long int nb, t_inf inf, int len)
{
	if (nb < 0)
		if (len < inf.width - (inf.prec >= ft_nbrlonglen(nb) ?
								inf.prec + 1 : ft_nbrlonglen(nb)))
			return (1);
	if (nb >= 0)
		if (len < inf.width - (inf.prec >= ft_nbrlonglen(nb) ?
								inf.prec : ft_nbrlonglen(nb)))
			return (1);
	return (0);
}

static int	pf_d_up2(long long int nb, int len, int min, t_inf inf)
{
	int cpt;

	cpt = -1;
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_d(nb, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 1 && inf.prec == 0 ? '0' : ' ');
	if (inf.plus && nb >= 0 && !min && inf.prec >= 0 && inf.done == 0)
		ft_putchar('+');
	else if (inf.space == 1 && nb >= 0 && !min && inf.done == 0)
		ft_putchar(' ');
	if (nb < 0 && nb != -9223372036854775807 - 1 && len++ >= 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (++cpt < inf.prec - ft_nbrlonglen(nb) && len++ >= 0)
		ft_putchar('0');
	ft_putnbrlong(nb);
	len += ft_nbrlonglen(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}

int			pf_d_up(va_list ap, t_inf inf)
{
	long long int	nb;
	int				len;
	int				min;

	nb = va_arg(ap, long long int);
	min = 0;
	len = ((inf.space == 1 || inf.plus == 1) && nb >= 0) ? 1 : 0;
	if (inf.zero == 1 && nb < 0 && inf.prec == 0 &&
		nb != -9223372036854775807 - 1 && len++ >= 0 && ++min == 1)
	{
		ft_putchar('-');
		nb = -nb;
	}
	pf_do_if(&inf, nb, min);
	return (pf_d_up2(nb, len, min, inf));
}
