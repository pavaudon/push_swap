/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:02:58 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/07 15:28:05 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int cpt;

	cpt = 0;
	if (s && f)
	{
		while (s[cpt])
		{
			(*f)(cpt, &s[cpt]);
			cpt++;
		}
	}
}
