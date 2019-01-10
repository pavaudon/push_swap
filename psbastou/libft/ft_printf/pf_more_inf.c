/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_more_inf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 02:39:52 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/20 10:56:10 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			pf_wrong_conv(char **str, const char **format, t_inf inf, int *len)
{
	int cpt;

	cpt = 0;
	if (**str == '\0')
	{
		*format = *str;
		return (1);
	}
	if (inf.width > 0 && inf.min == 0)
		while (++cpt < inf.width)
		{
			ft_putchar(inf.zero == 1 ? '0' : ' ');
			*len += 1;
		}
	ft_putchar(**str);
	if (inf.width > 0 && inf.min == 1)
		while (++cpt < inf.width)
		{
			ft_putchar(' ');
			*len += 1;
		}
	*format = *str + 1;
	*len += 1;
	return (0);
}

int			pf_more_flag(char **s, t_inf *inf)
{
	if (**s == 'j')
		inf->j = 1;
	if (**s == 'z')
		inf->z = 1;
	if (**s == 'l')
	{
		*s += 1;
		if (**s == 'l')
			inf->ll = 1;
		else
			return (inf->l = 1);
	}
	if (**s == 'h')
	{
		*s += 1;
		if (**s == 'h')
			inf->hh = 1;
		else
			return (inf->h = 1);
	}
	return (0);
}

void		take_prec(char **s, t_inf *inf, va_list ap, int cpt)
{
	inf->prec = 0;
	*s += 1;
	if (**s == '*' && cpt++ >= 0)
	{
		inf->prec = va_arg(ap, int);
		if (inf->prec < 0)
			inf->prec = -1;
		*s += 1;
	}
	else
	{
		while (ft_isdigit(**s) && cpt++ >= 0)
		{
			inf->prec = inf->prec * 10 + **s - '0';
			*s += 1;
		}
	}
	if (cpt == 0 || inf->prec == 0)
		inf->prec = -1;
	else if (inf->prec == -1)
		inf->prec = 0;
}

static int	pf_more_color_please(char tmp[8])
{
	if (ft_strstr(tmp, "red"))
		ft_putstr(RED);
	else if (ft_strstr(tmp, "black"))
		ft_putstr(BLACK);
	else if (ft_strstr(tmp, "green"))
		ft_putstr(GREEN);
	else if (ft_strstr(tmp, "yellow"))
		ft_putstr(YELLOW);
	else if (ft_strstr(tmp, "blue"))
		ft_putstr(BLUE);
	else if (ft_strstr(tmp, "purple"))
		ft_putstr(PURPLE);
	else if (ft_strstr(tmp, "cyan"))
		ft_putstr(CYAN);
	else if (ft_strstr(tmp, "grey"))
		ft_putstr(GREY);
	else if (ft_strstr(tmp, "eoc"))
		ft_putstr(EOC);
	else
		return (0);
	return (1);
}

int			pf_take_color(char **str, const char **format, int *len)
{
	int		cpt;
	char	tmp[8];

	cpt = 0;
	tmp[7] = '\0';
	*len += pf_print_part(*format, *str);
	*str += 1;
	while (**str != '}' && cpt < 7)
	{
		tmp[cpt] = **str;
		*str += 1;
		cpt++;
	}
	*str += 1;
	if (!pf_more_color_please(tmp))
	{
		*str -= cpt + 2;
		*format = *str;
		return (0);
	}
	*format = *str;
	return (1);
}
