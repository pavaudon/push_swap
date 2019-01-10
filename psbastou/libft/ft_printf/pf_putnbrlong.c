/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbrlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 16:21:57 by bchanot           #+#    #+#             */
/*   Updated: 2016/04/12 02:10:56 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int	pf_putuhex(long long unsigned int n)
{
	char *hex;

	hex = NULL;
	if (n >= 16)
		return (pf_putuhex(n / 16) + pf_putuhex(n % 16));
	else
	{
		hex = ft_strdup("0123456789abcdef");
		ft_putchar(hex[n]);
		free(hex);
		return (1);
	}
}

int	pf_putuoctal(long long unsigned int n)
{
	if (n >= 8)
		return (pf_putuoctal(n / 8) + pf_putuhex(n % 8));
	else
	{
		ft_putchar(n + 48);
		return (1);
	}
}

int	pf_putuhexm(long long unsigned int n)
{
	char *hex;

	hex = NULL;
	if (n >= 16)
		return (pf_putuhexm(n / 16) + pf_putuhexm(n % 16));
	else
	{
		hex = ft_strdup("0123456789ABCDEF");
		ft_putchar(hex[n]);
		free(hex);
		return (1);
	}
}

int	pf_putunbrlong(long long unsigned int n)
{
	if (n >= 10)
		return (pf_putunbrlong(n / 10) + pf_putunbrlong(n % 10));
	ft_putchar(48 + n);
	return (1);
}
