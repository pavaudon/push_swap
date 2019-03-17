/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicorn <unicorn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:46:29 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/17 18:18:16 by unicorn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_help_sort(t_data *data)
{
	t_stack *tmp;
	int		help;

	tmp = data->head_a;
	help = 0;
	while (tmp)
	{
		if (++help != tmp->circle_pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_help_sort(t_data *data)
{
	t_stack *tmp;
	int		again;

	again = 0;
	ft_min_max(data, 0);
	ft_circle_pos(data, ft_new_first(data));
	while (!again)
	{
		tmp = data->head_a;
		if (tmp->circle_pos == 3 && tmp->next->circle_pos == 1)
			ft_apply_command(data, 0, RA);
		else if ((tmp->next->circle_pos == 3 && tmp->circle_pos == 1) ||
		(tmp->circle_pos == 3 && tmp->next->circle_pos == 2) ||
		(tmp->circle_pos == 2 && tmp->next->circle_pos == 1))
			ft_apply_command(data, 0, SA);
		else if (tmp->next->circle_pos == 3 && tmp->circle_pos == 2)
			ft_apply_command(data, 0, RRA);
		if (ft_is_help_sort(data))
			again++;
	}
}

int		ft_hentai_sort(t_data *data)
{
	ft_apply_command(data, 0, PA);
	if (!data->size[1] && (ft_circle_sort(data) || ft_only_swap(data)))
		return (1);
	ft_only_swap(data);
	if (data->head_a->value == data->max[2] &&
	data->head_a->next->final_p == data->size[2] - 1)
		ft_apply_command(data, 0, SA);
	if (data->head_a->value != data->max[2] && data->head_b->final_p != 4)
	{
		ft_only_swap(data);
		ft_circle_sort(data);
	}
	if (data->max[0] == data->max[2] && data->head_b->final_p == 4)
		ft_apply_command(data, 0, RRA);
	if (data->head_a->value == data->max[2] && data->head_b->final_p != 4)
		ft_apply_command(data, 0, RA);
	if (!(data->size[1]) && ft_stack_sort(data->head_a))
		return (1);
	ft_apply_command(data, 1, PA);
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	return (0);
}

int		ft_four_five_sort(t_data *data)
{
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	while (data->size[0] > 3)
	{
		if ((data->size[2] == 5 && data->head_a->final_p == 3)
		|| (data->size[2] == 4 && data->head_a->final_p == 2))
			ft_apply_command(data, 0, RA);
		ft_apply_command(data, 0, PB);
	}
	ft_min_max(data, 1);
	if (data->size[1] == 2
		&& (data->head_b->value == data->max[2] && data->head_b->final_p != 4)
		&& (data->head_b->value < data->head_b->next->value))
		ft_apply_command(data, 1, SB);
	if ((data->size[1] == 2
		&& ((data->head_b->final_p == 2 && data->head_b->next->final_p != 1)
		|| (data->head_b->final_p == 4 && data->head_b->next->final_p == 5)))
		|| (data->size[1] == 1 && (data->max[1] == data->max[2])))
		ft_sort_three(data);
	else
		ft_help_sort(data);
	ft_hentai_sort(data);
	return (1);
}
