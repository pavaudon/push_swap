/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cptchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:16:22 by bchanot           #+#    #+#             */
/*   Updated: 2016/02/08 16:22:26 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cptchar(char *str, char c)
{
	size_t	cpt;
	int		i;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cpt++;
		i++;
	}
	return (cpt);
}
