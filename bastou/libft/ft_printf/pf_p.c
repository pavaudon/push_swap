/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:51:30 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/29 04:03:02 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int	pf_width_p(char *str, t_inf inf, int len, void *p)
{
	int i;

	i = p == (void *)0 && inf.prec == -1 ? 0 : (int)ft_strlen(str);
	if (inf.prec > i)
	{
		if (len < inf.width - inf.prec)
			return (1);
	}
	else if (len < inf.width - i)
		return (1);
	return (0);
}

static char	get_digit(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

static char	*ft_ptoa(void *p)
{
	unsigned long	tmpn;
	unsigned long	n;
	int				len;
	char			*str;

	n = (unsigned long)p;
	tmpn = (unsigned long)p;
	len = 2;
	while (tmpn /= 16)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = get_digit(n % 16);
		n = n / 16;
	}
	return (str);
}

static int	pf_p2(char *str, t_inf inf, int len)
{
	len += pf_putstr(str);
	if (inf.width > 0 && inf.min == 1)
		while (len < inf.width && len++ >= 0)
			ft_putchar(' ');
	if (str)
		free(str);
	return (len);
}

int			pf_p(va_list ap, t_inf inf)
{
	char	*str;
	int		len;
	void	*p;
	int		cpt;

	p = va_arg(ap, void*);
	str = ft_ptoa(p);
	len = 2;
	if (inf.zero && inf.prec != 0)
		inf.zero = 0;
	if (inf.width > 0 && !inf.min && !inf.zero && inf.width > inf.prec)
		while (pf_width_p(str, inf, len, p) && len++ >= 0)
			ft_putchar(' ');
	pf_putstr("0x");
	cpt = -1;
	if (inf.prec > 0)
		while (++cpt < inf.prec - ((int)ft_strlen(str)) && len++ >= 0)
			ft_putchar('0');
	cpt = -1;
	if (inf.width && inf.zero && !inf.min)
		while (++cpt < inf.width - ((int)ft_strlen(str) + 2) && len++ >= 0)
			ft_putchar('0');
	return (pf_p2(str, inf, len));
}
