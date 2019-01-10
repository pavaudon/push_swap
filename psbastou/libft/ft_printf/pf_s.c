/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:48:47 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/29 03:44:48 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_width_s(char *str, t_inf inf, int len)
{
	if (inf.prec < (int)ft_strlen(str) && inf.prec != 0)
	{
		if (len < inf.width - inf.prec)
			return (1);
	}
	else if (len < inf.width - (int)ft_strlen(str))
		return (1);
	return (0);
}

int	pf_s(va_list ap, t_inf inf)
{
	char	*str;
	int		len;

	len = inf.prec == -1 ? 1 : 0;
	if (inf.l)
		return (pf_s_up(ap, inf));
	if ((str = va_arg(ap, char *)) == NULL)
		str = "(null)";
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_s(str, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 0 ? ' ' : '0');
	if (inf.prec > 0 && inf.prec < (int)ft_strlen(str))
		len += pf_putnstr(str, inf.prec);
	else
		len += pf_putstr(str);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}
