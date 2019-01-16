/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:07:30 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/29 16:18:37 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int cpt;
	int nb;
	int neg;

	cpt = 0;
	neg = 0;
	nb = 0;
	while (str[cpt] == ' ' || str[cpt] == '\n' || str[cpt] == '\v' ||
	str[cpt] == '\r' || str[cpt] == '\t' || str[cpt] == '\f')
		cpt++;
	if (str[cpt] == '-')
		neg = 1;
	if (str[cpt] == '+' || str[cpt] == '-')
		cpt++;
	while (str[cpt] >= '0' && str[cpt] <= '9')
	{
		nb *= 10;
		nb += (str[cpt] - 48);
		cpt++;
	}
	return (neg == 1 ? -nb : nb);
}
