/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cptnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:36:08 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/23 15:43:27 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long int nb)
{
	int size;

	size = (nb < 0 ? 1 : 0);
	while ((nb = nb / 10))
		size++;
	size++;
	return (size);
}

int		ft_nbrlonglen(long long int nb)
{
	int size;

	size = 0;
	if (nb < 0)
	{
		if (nb == -9223372036854775807 - 1)
			return (20);
		nb = -nb;
		size = ft_nbrlonglen(nb);
		size++;
	}
	else if (nb >= 10)
	{
		size = ft_nbrlonglen(nb / 10);
		size++;
	}
	else
		size++;
	return (size);
}

int		ft_nbrlgulen(long long unsigned int nb)
{
	int size;

	size = 0;
	if (nb >= 10)
	{
		size = ft_nbrlgulen(nb / 10);
		size++;
	}
	else
		size++;
	return (size);
}

int		ft_nbrulen(unsigned int nb)
{
	int size;

	size = 0;
	if (nb >= 10)
	{
		size = ft_nbrulen(nb / 10);
		size++;
	}
	else
		size++;
	return (size);
}
