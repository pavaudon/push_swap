/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:53:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/22 16:04:47 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_path(t_data *data)
{
	t_stack *tmp;
	int		r;
	int		rr;

	r = 0;
	rr = 1;
	tmp = data->head_a;
	while (tmp && tmp->mark)
	{
		tmp = tmp->next;
		r++;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (tmp && tmp->prev && tmp->mark)
	{
		tmp = tmp->prev;
		rr++;
	}
	return ((r < rr) ? RA : RRA);
}

void	go_to_unmark(t_data *data)
{
	int		up;
	int		down;
	t_stack	*tmp_up;
	t_stack	*tmp_down;

	down = 0;
	up = 0;
	tmp_down = data->head_a;
	while (tmp_down && tmp_down->mark && ++down)
		tmp_down = tmp_down->next;
	tmp_up = tmp_down ? tmp_down : data->head_a;
	while (tmp_up && tmp_up->next)
		tmp_up = tmp_up->next;
	while (tmp_up && tmp_up->mark && ++up)
		tmp_up = tmp_up->prev;
	up++;
	if (down < up)
		up = -down;
	while (up != 0)
	{
		ft_apply_command(data, 0, up > 0 ? RRA : RA);
		up += (up < 0) ? 1 : -1;
	}
}

void	ft_get_unmark(t_data *data, int unmarks)
{
	t_stack *tmp;

	while ((data->size[1] < (data->size[2] / 2)) && unmarks)			//changement de pa pour test
	{
		tmp = data->head_a;
		if (tmp->mark == 0)
		{
			ft_apply_command(data, 0, PB);
			unmarks--;
		}
		else
			go_to_unmark(data);
	}
}

int		ft_bl_start(t_data *data)
{
	while (data->marks < data->size[2])
	{
		while (data->size[1] < (data->size[2] / 2)
			&& ((data->marks + data->size[1]) < data->size[2]))			//changement de pa pour test
			ft_get_unmark(data, data->size[2] - data->marks);
		push_opti(data);
		if (!(data->size[1]) && (ft_circle_sort(data) || ft_only_swap(data)))
			return (1);
	}
	return (1);
}

void	ft_check_min_max(t_data *data)
{
	t_stack *min;
	t_stack	*max;
	t_stack	*tmp;
	char	command;

	min = get_link(data, MIN_VAL);
	max = get_link(data, MAX_VAL);
	tmp = data->head_a;
	command = (max->actual_pos > (data->size[2] / 2)) ? RRA : RA;
	if ((min->actual_pos == max->actual_pos + 1)
		|| (min->actual_pos == data->size[0] && max->actual_pos == 1))
	{
		while (tmp && tmp->value != max->value)
		{
			ft_apply_command(data, 0, command);
			tmp = data->head_a;
		}
	}
}

int		main_big_list(t_data *data)
{
	t_stack *tmp;

	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	ft_check_min_max(data);
	ft_find_pos(data, 0, 0);
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->value == data->min[2] || tmp->value == data->max[2])
			tmp->mark++;
		tmp = tmp->next;
	}
	data->marks = 2;
	premark(data);
	return (ft_bl_start(data));
}
