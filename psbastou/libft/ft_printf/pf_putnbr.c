/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:08:12 by bchanot           #+#    #+#             */
/*   Updated: 2016/04/25 00:37:31 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int	pf_puthex(unsigned int n)
{
	char *hex;

	hex = NULL;
	if (n >= 16)
		return (pf_puthex(n / 16) + pf_puthex(n % 16));
	else
	{
		hex = ft_strdup("0123456789abcdef");
		ft_putchar(hex[n]);
		if (hex)
			free(hex);
		return (1);
	}
}

int	pf_putoctal(unsigned int n)
{
	if (n >= 8)
		return (pf_putoctal(n / 8) + pf_puthex(n % 8));
	else
	{
		ft_putchar(n + 48);
		return (1);
	}
}

int	pf_puthexm(unsigned int n)
{
	char *hex;

	hex = NULL;
	if (n >= 16)
		return (pf_puthexm(n / 16) + pf_puthexm(n % 16));
	else
	{
		hex = ft_strdup("0123456789ABCDEF");
		ft_putchar(hex[n]);
		if (hex)
			free(hex);
		return (1);
	}
}

int	pf_putunbr(unsigned int n)
{
	if (n >= 10)
		return (pf_putunbr(n / 10) + pf_putunbr(n % 10));
	ft_putchar(48 + n);
	return (1);
}
