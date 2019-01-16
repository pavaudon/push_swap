/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:58:26 by bchanot           #+#    #+#             */
/*   Updated: 2016/03/19 03:42:30 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_c(va_list ap, t_inf inf)
{
	int	nb;
	int	len;

	len = 1;
	if (inf.l)
		return (pf_c_up(ap, inf));
	nb = va_arg(ap, int);
	if (inf.width > 0 && inf.min == 0)
		while (len++ < inf.width)
			ft_putchar(inf.zero == 0 ? ' ' : '0');
	ft_putchar(nb);
	if (inf.width > 0 && inf.min == 1)
		while (len++ < inf.width)
			ft_putchar(' ');
	return (inf.width > 0 ? inf.width : 1);
}
