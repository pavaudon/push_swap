/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/08 15:27:24 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_size(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (which == 1) ? data->head_b : data->head_a;
	while (tmp)
	{
		data->size[which] += 1;
		tmp = tmp->next;
	}
	if (which == 2)
		data->size[0] = data->size[2];
}

int			ft_spe_fill(t_data *data, char *str)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if (!(ft_add_back(&data->head_a, ft_atoi(&str[i]))))
			return (0);
		if (str[i] == '-')
			i++;
		while (i < len && (ft_isdigit(str[i])))
			i++;
	}
	return (1);
}

int			ft_fill(t_data *data, int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!(ft_spe_fill(data, argv[i])))
				return (0);
		}
		else
		{
			if (!(ft_add_back(&data->head_a, ft_atoi(argv[i]))))
				return (0);
		}
	}
	return (1);
}

int			ft_stack_fill(t_data *data, int argc, char **argv)
{
	data->head_a = NULL;
	if (!(ft_fill(data, argc, argv)))
		return (0);
	data->head_b = NULL;
	ft_size(data, 2);
	return (1);
}
