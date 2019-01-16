/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:09:42 by bchanot           #+#    #+#             */
/*   Updated: 2016/07/22 23:59:06 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char	*ft_set_str(char *str)
{
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n' && str[1] != '\0')
		return (ft_strdup(++str));
	else
		return (NULL);
}

static void	ft_add(char **line, char *rest)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	if (*line)
	{
		tmp = ft_strdup(*line);
		free(*line);
		len = ft_strlen(tmp) + ft_strlen(rest);
		*line = (char *)malloc(sizeof(char) * (len + 1));
		ft_strcpy(*line, tmp);
		free(tmp);
		while ((*line)[i])
			i++;
	}
	else
	{
		len = ft_strlen(rest);
		*line = (char *)malloc(sizeof(char) * (len + 1));
	}
	while (*rest != '\0' && *rest != '\n')
		(*line)[i++] = *rest++;
	(*line)[i] = '\0';
}

static int	ft_take_rest(char **line, char **rest)
{
	char *buf;

	if (*rest && ft_strchr(*rest, '\n'))
	{
		ft_add(line, *rest);
		buf = *rest;
		*rest = ft_set_str(buf);
		free(buf);
		return (1);
	}
	else if (*rest && !ft_strchr(*rest, '\n'))
	{
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (0);
}

static int	ft_check(char **line, char **rest, int const fd)
{
	if (line)
		*line = NULL;
	else
		return (-1);
	if (BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (ft_take_rest(line, rest))
		return (1);
	return (0);
}

int			ft_get_next_line(int const fd, char **line)
{
	int			check;
	int			res;
	char		*str;
	static char *rest;

	check = ft_check(line, &rest, fd);
	if (check != 0)
		return (check);
	str = ft_strnew(BUFF_SIZE);
	while ((res = read(fd, str, BUFF_SIZE)) > 0 && !ft_strchr(str, '\n'))
	{
		ft_add(line, str);
		ft_bzero(str, BUFF_SIZE + 1);
	}
	if (res > 0)
	{
		str[res] = '\0';
		ft_add(line, str);
		rest = ft_set_str(str);
	}
	free(str);
	res = (res > 1) ? 1 : res;
	return ((res == 0 && *line != NULL) ? 1 : res);
}
