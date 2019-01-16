/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 19:02:39 by bchanot           #+#    #+#             */
/*   Updated: 2016/06/15 19:12:13 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	ft_putchar('\n');
}

void	ft_putendl(const char *s)
{
	return (ft_putendl_fd(s, 1));
}
