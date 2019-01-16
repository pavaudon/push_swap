/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:17:43 by bchanot           #+#    #+#             */
/*   Updated: 2016/03/28 21:42:33 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_width_b(char *str, t_inf inf, int len, int nb)
{
	int i;

	i = nb == 0 && inf.prec == -1 ? 0 : (int)ft_strlen(str);
	if (inf.prec > i)
	{
		if (len < inf.width - inf.prec)
			return (1);
	}
	else if (len < inf.width - i)
		return (1);
	return (0);
}

static int	pf_b2(int nb, char *str, t_inf inf, int len)
{
	if (nb == 0 && inf.prec == -1)
		len += 0;
	else
		len += pf_putstr(str);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	return (len);
}

int			pf_b(va_list ap, t_inf inf)
{
	char	*str;
	int		len;
	int		nb;
	int		cpt;

	nb = va_arg(ap, int);
	str = ft_itob(nb);
	len = 0;
	if (inf.zero && inf.prec != 0)
		inf.zero = 0;
	if (inf.width > 0 && !inf.min && !inf.zero && inf.width > inf.prec)
		while (pf_width_b(str, inf, len, nb) && len++ >= 0)
			ft_putchar(' ');
	cpt = -1;
	if (inf.prec > 0)
		while (++cpt < inf.prec - ((int)ft_strlen(str)) && len++ >= 0)
			ft_putchar('0');
	cpt = -1;
	if (inf.width && inf.zero && !inf.min)
		while (++cpt < inf.width - ((int)ft_strlen(str)) && len++ >= 0)
			ft_putchar('0');
	return (pf_b2(nb, str, inf, len));
}
