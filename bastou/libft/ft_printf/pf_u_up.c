/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 03:07:31 by bchanot           #+#    #+#             */
/*   Updated: 2016/06/13 21:57:43 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_width_u_up(long long unsigned int nb, t_inf inf, int len)
{
	int i;

	i = nb == 0 && inf.prec == -1 ? 0 : ft_nbrlgulen(nb);
	if (inf.prec > ft_nbrlgulen(nb))
	{
		if (len < inf.width - inf.prec)
			return (1);
	}
	else if (len < inf.width - ft_nbrlgulen(nb))
		return (42);
	return (0);
}

int			pf_u_up(va_list ap, t_inf inf)
{
	long long unsigned int	nb;
	int						len;
	int						cpt;

	nb = va_arg(ap, long long unsigned int);
	len = 0;
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_u_up(nb, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 1 && inf.prec == 0 ? '0' : ' ');
	cpt = -1;
	while (++cpt < inf.prec - ft_nbrlgulen(nb) && len++ >= 0)
		ft_putchar('0');
	len += pf_putunbrlong(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}
