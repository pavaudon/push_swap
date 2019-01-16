/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:48:12 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/29 04:00:05 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_percent(va_list ap, t_inf inf)
{
	int	len;

	len = 1;
	(void)ap;
	if (inf.width > 0 && inf.min == 0)
		while (len++ < inf.width)
			ft_putchar(inf.zero == 0 ? ' ' : '0');
	ft_putchar('%');
	if (inf.width > 0 && inf.min == 1)
		while (len++ < inf.width)
			ft_putchar(' ');
	return (inf.width > 0 ? inf.width : 1);
}
