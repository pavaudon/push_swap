/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:50:12 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/11 21:26:03 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <wchar.h>
#include <stdlib.h>

int			pf_s_up(va_list ap, t_inf inf)
{
	wchar_t *s;
	char	*str;
	int		len;

	len = inf.prec == -1 ? 1 : 0;
	if ((s = va_arg(ap, wchar_t *)) == NULL)
		str = ft_strdup("null");
	else
		str = ft_widestr(s);
	if (inf.width > 0 && inf.min == 0)
		while (pf_width_s(str, inf, len) && len++ >= 0)
			ft_putchar(inf.zero ? '0' : ' ');
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
