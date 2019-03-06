/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:35:38 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/06 19:33:58 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_final_pos(t_data *data, int value, int which)
{
	t_stack *tmp;
	int		pos;

	pos = data->size[which];
	ft_min_max(data, which);
	if (value == data->min[which])
		return ((which) ? pos : 1);
	if (value == data->max[which])
		return ((which) ? 1 : pos);
	tmp = (which) ? data->head_b : data->head_a;
	if (!tmp)
		return (0);
	while (tmp)
	{
		pos -= (value < tmp->value) ? 1 : 0;
		tmp = tmp->next;
	}
	return (pos);
}

void	ft_actual_pos(t_data *data, int which, int both)
{
	t_stack *tmp;
	int		i;

	tmp = (which == 'a') ? data->head_a : data->head_b;
	if (!tmp)
	{
		if (both && !which)
			ft_actual_pos(data, 1, 0);
		return ;
	}
	i = 0;
	while (tmp)
	{
		tmp->actual_pos = ++i;
		tmp = tmp->next;
	}
	if (both && !which)
		ft_actual_pos(data, 1, 0);
}

void	ft_find_pos(t_data *data, int which, int both)
{
	t_stack	*tmp;
	int		i;

	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
	{
		if (both && !which)
			ft_find_pos(data, 1, 0);
		return ;
	}
	i = 0;
	while (tmp)
	{
		tmp->final_pos = ft_final_pos(data, tmp->value, which);
		tmp->actual_pos = ++i;
		tmp = tmp->next;
	}
	if (both && !which)
		ft_find_pos(data, 1, 0);
}
