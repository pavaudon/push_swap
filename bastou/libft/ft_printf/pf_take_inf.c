/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_take_inf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 00:23:20 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/21 04:20:17 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	g_type[] = {
	'%', 's', 'S', 'p', 'd', 'D', 'i', 'o', 'O', 'u', 'U',
	'x', 'X', 'c', 'C', 'b', 0};

static void	take_flag(char **s, t_inf *inf)
{
	while (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ' \
		|| **s == 'l' || **s == 'h' || **s == 'j' || **s == 'z')
	{
		if (**s == '+')
			inf->plus = 1;
		if (**s == '0')
			inf->zero = 1;
		if (**s == '#')
			inf->di = 1;
		if (**s == ' ')
			inf->space = 1;
		if (**s == '-')
			inf->min = 1;
		if (!pf_more_flag(s, inf))
			*s += 1;
		inf->flag++;
	}
}

static int	take_width(char **s, t_inf *inf, va_list ap)
{
	if (**s == '*')
	{
		inf->width = va_arg(ap, int);
		if (inf->width < 0)
		{
			inf->min = 1;
			inf->width = -inf->width;
		}
		*s += 1;
	}
	else if (**s >= '0' && **s <= '9')
	{
		inf->width = 0;
		while (ft_isdigit(**s))
		{
			inf->width = inf->width * 10 + **s - '0';
			*s += 1;
		}
	}
	return (1);
}

static int	take_type(char *s, t_inf *inf)
{
	int		i;

	i = -1;
	while (g_type[++i])
	{
		if (g_type[i] == *s)
		{
			inf->type = i;
			return (1);
		}
	}
	inf->type = -1;
	return (0);
}

t_inf		pf_take_inf(char **s, va_list ap)
{
	t_inf	inf;

	ft_bzero(&inf, sizeof(inf));
	take_flag(s, &inf);
	if (**s == '*' || (ft_isdigit(**s) && **s != '0'))
		take_width(s, &inf, ap);
	if (**s == '.')
		take_prec(s, &inf, ap, 0);
	if (take_type(*s, &inf))
		*s += 1;
	return (inf);
}
