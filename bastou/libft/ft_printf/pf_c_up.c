/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:59:11 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/11 21:35:38 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <wchar.h>
#include <stdlib.h>

static int	pf_width_c_up(char *str, t_inf inf, int len)
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

static int	pf_c_up2(t_inf inf, char *str, int len)
{
	if (inf.prec > 0 && inf.prec < (int)ft_strlen(str))
		len += pf_putnstr(str, inf.prec);
	else
		len += pf_putstr(str);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	if (str)
		free(str);
	return (len);
}

int			pf_c_up(va_list ap, t_inf inf)
{
	wchar_t c;
	char	*str;
	int		len;

	len = inf.prec == -1 ? 1 : 0;
	c = va_arg(ap, wchar_t);
	str = ft_widechar(c);
	if (c == 0)
		return (1);
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_c_up(str, inf, len) && len++ >= 0)
			ft_putchar(inf.zero == 0 ? ' ' : '0');
	if (inf.prec == -1 && c != 0)
		return (len - 1);
	return (pf_c_up2(inf, str, len));
}
