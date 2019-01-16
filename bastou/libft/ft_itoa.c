/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:33:13 by bchanot           #+#    #+#             */
/*   Updated: 2016/05/23 15:36:03 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoa(long long int n)
{
	int				size;
	char			*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(n);
	if (!(str = (char *)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[size] = '\0';
	while (n >= 10)
	{
		str[size - 1] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	str[size - 1] = n + 48;
	return (str);
}
