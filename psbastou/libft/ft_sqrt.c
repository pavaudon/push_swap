/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 22:43:47 by bchanot           #+#    #+#             */
/*   Updated: 2016/01/28 22:46:49 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int cpt;

	cpt = 0;
	if (nb == 0)
		return (0);
	while (cpt * cpt < nb)
		cpt++;
	return (cpt);
}
