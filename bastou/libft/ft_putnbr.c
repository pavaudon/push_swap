/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:54:21 by bchanot           #+#    #+#             */
/*   Updated: 2016/06/16 15:43:06 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	long nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putnbr_fd((nbr % 10), fd);
	}
	else
		ft_putchar_fd((nbr + 48), fd);
}

void	ft_putnbr(long int n)
{
	return (ft_putnbr_fd(n, 1));
}

void	ft_putnbrlong(long long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == (-9223372036854775807 - 1))
		{
			ft_putstr("9223372036854775808");
			return ;
		}
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(48 + nb);
	else
	{
		ft_putnbrlong(nb / 10);
		ft_putnbrlong(nb % 10);
	}
}
