/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_again.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/06 20:01:43 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_min_max(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (which == 1) ? data->head_b : data->head_a;
	if (!tmp)
		return ;
	data->min[which] = tmp->value;
	data->max[which] = tmp->value;
	while (tmp)
	{
		data->min[which] = (data->min[which] > tmp->value) ? tmp->value :
		data->min[which];
		data->max[which] = (data->max[which] < tmp->value) ? tmp->value :
		data->max[which];
		tmp = tmp->next;
	}
	if (which == 2)
	{
		data->min[0] = data->min[2];
		data->max[0] = data->max[2];
	}
}

int			ft_is_again(t_data *data)
{
	t_stack *tmp;
	t_stack *compare;

	tmp = data->head_a;
	if (data->size[0] == 1)
		return (1);
	while (tmp->next)
	{
		compare = tmp->next;
		while (compare)
		{
			if (tmp->value == compare->value)
				return (0);
			compare = compare->next;
		}
		tmp = tmp->next;
	}
	ft_min_max(data, 2);
	return (1);
}
