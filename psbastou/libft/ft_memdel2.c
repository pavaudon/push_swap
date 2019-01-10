/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 16:59:53 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/17 09:59:31 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_memdel2(void ***ap)
{
	int		i;

	if (ap != NULL && *ap != NULL)
	{
		i = -1;
		while ((*ap)[++i])
			ft_memdel((void **)&(*ap)[i]);
		free(*ap);
		*ap = NULL;
	}
}
