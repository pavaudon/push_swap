/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:35:38 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/15 15:50:05 by pavaudon         ###   ########.fr       */
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
		if (data->actual_pos != data->final_pos)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int		ft_final_pos(t_data *data, int value)
{
	t_stack *tmp;
	int		pos;

	pos = data->size[0];
	if (value == data->min[0])
		return (1);
	if (value == data->max[0])
		return (pos);
	tmp = data->head_a;
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
	i = 0;
	while (tmp)
	{
		tmp->actual_pos = ++i;
		tmp = tmp->next;
	}
}

void	ft_find_pos(t_data *data)
{
	t_stack	*tmp;
	int		i;

	tmp = data->head_a;
	i = 0;
	while (++i <= data->size[0])
	{
		tmp->final_pos = ft_find_pos(data, tmp->value);
		tmp->actual_pos = i;
		tmp = tmp->next;
	}
}
