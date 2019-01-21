/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:35:38 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/21 17:15:55 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_pos(t_data *data, char which)	//int both?
{
	t_stack *tmp;

	tmp = (which == 'b') ? data->head_b : data->head_a;
	while (tmp)
	{
		tmp->move_pos = tmp->actual_pos - tmp->final_pos;
		tmp = tmp->next;
	}
}

int		ft_bad_pos(t_data *data, char which)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = (which == 'b') ? data->head_a : data->head_a;
	while (tmp)
	{
		if (tmp->actual_pos != tmp->final_pos)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int		ft_final_pos(t_data *data, int value, int which)
{
	t_stack *tmp;
	int		pos;

	pos = data->size[0];
	if (value == data->min[0])
		return (1);
	if (value == data->max[0])
		return (pos);
	tmp = (which) ? data->head_b : data->head_a;
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

	tmp = (which == 'a') ? data->head_a : data->head_b;
	if (!tmp)
	{
		if (both && !which)
			ft_find_pos(data, 1, 0);
		return ;
	}
	i = 0;
	while (++i <= data->size[0])
	{
		tmp->final_pos = ft_final_pos(data, tmp->value, which);
		tmp->actual_pos = i;
		tmp = tmp->next;
	}
	if (both && !which)
		ft_find_pos(data, 1, 0);
}
