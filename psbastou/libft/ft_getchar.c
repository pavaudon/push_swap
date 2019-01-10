/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 18:46:16 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/20 11:16:30 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_getchar_fd(int fd)
{
	char	c;

	if (read(fd, &c, 1) != 1)
		return (-1);
	return ((int)c);
}

int	ft_getchar(void)
{
	return (ft_getchar_fd(0));
}
