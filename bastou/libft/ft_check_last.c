/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 03:46:31 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/29 03:52:47 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_last(char *src, int c, char *str)
{
	int cpt;

	cpt = 0;
	while (src[cpt + c])
		cpt++;
	if (ft_strcmp(&src[cpt], str) == 0)
		return (1);
	return (0);
}
