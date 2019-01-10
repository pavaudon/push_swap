/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 20:07:34 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/20 11:16:18 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_itoo(long long unsigned int nb)
{
	long long int oct;
	long long int mult;

	oct = 0;
	mult = 1;
	while ((nb / 8) > 0)
	{
		oct += mult * (nb - 8 * (nb / 8));
		nb = nb / 8;
		mult = mult * 10;
	}
	oct += mult * nb;
	return (oct);
}
