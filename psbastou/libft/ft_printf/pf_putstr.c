/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 00:48:09 by bchanot           #+#    #+#             */
/*   Updated: 2016/06/13 21:45:37 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		pf_xlong2(int len, t_inf *inf, unsigned long long nb)
{
	len += pf_putuhex(nb);
	if (inf->width > 0 && inf->min == 1)
		while (len < inf->width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}

int		pf_x_uplong2(int len, t_inf *inf, unsigned long long nb)
{
	len += pf_putuhexm(nb);
	if (inf->width > 0 && inf->min == 1)
		while (len < inf->width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}

int		pf_putstr(const char *str)
{
	int len;

	len = -1;
	while (str[++len])
		ft_putchar(str[len]);
	return (len);
}

int		pf_putnstr(const char *str, int n)
{
	write(1, str, n);
	return (n);
}
