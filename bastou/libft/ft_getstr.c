/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 18:51:15 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/03 16:07:01 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_getstr_fd(int fd, char x)
{
	char c;
	char *str;
	char *tmp;

	str = ft_strnew(1);
	ft_bzero(str, 1);
	while (read(fd, &c, 1) != 0)
	{
		if (c == x)
			break ;
		else
		{
			tmp = ft_charjoin(str, c);
			free(str);
			str = ft_strdup(tmp);
			free(tmp);
		}
	}
	tmp = ft_strjoin(str, "\0");
	free(str);
	return (tmp);
}

char	*ft_getstr(char x)
{
	return (ft_getstr_fd(0, x));
}
