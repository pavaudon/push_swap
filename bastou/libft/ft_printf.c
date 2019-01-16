/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 00:22:06 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/20 10:56:33 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

static int	(*g_func[])(va_list, t_inf) = {
	pf_percent, pf_s, pf_s_up, pf_p,
	pf_di, pf_d_up, pf_di, pf_o,
	pf_o_up, pf_u, pf_u_up, pf_x,
	pf_x_up, pf_c, pf_c_up, pf_b};

int			pf_print_part(const char *format, char *str)
{
	int	len;

	len = 0;
	while (format + len != str)
		len++;
	write(1, format, len);
	return (len);
}

static int	ft_format(char **str, va_list ap, t_inf inf)
{
	int		len;

	len = 0;
	if (inf.type == -1)
		return (-2);
	else if (inf.type >= 0)
		len = g_func[inf.type](ap, inf);
	if (len < 0)
		return (-1);
	*str -= 1;
	return (len);
}

static int	pf_printf(const char **format, va_list ap, char **str, int *len)
{
	int		chk;
	t_inf	inf;

	*len += pf_print_part(*format, *str);
	*str += 1;
	inf = pf_take_inf(str, ap);
	if ((chk = ft_format(str, ap, inf)) < 0)
	{
		if (chk == -1)
			return (-1);
		if (pf_wrong_conv(str, format, inf, len))
			return (0);
	}
	else
	{
		*format = *str + 1;
		*len += chk;
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	char		*str;
	int			col;

	len = 0;
	col = 0;
	str = (char *)format;
	va_start(ap, format);
	while (*str)
	{
		if (*str == '{')
			col = pf_take_color(&str, &format, &len);
		if (*str == '%')
			if (pf_printf(&format, ap, &str, &len) == -1)
				return (-1);
		str++;
	}
	va_end(ap);
	len += pf_putstr(format);
	if (col == 1)
		ft_putstr(EOC);
	return (len);
}
