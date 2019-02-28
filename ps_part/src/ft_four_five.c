/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:46:29 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/28 19:53:55 by pavaudon         ###   ########.fr       */
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
	ft_apply_command(data, 1, PB);
	if (!data->size[1] && (ft_circle_sort(data) || ft_only_swap(data)))
		return (1);
	ft_only_swap(data);
	if (data->head_a->value == data->max[2] &&
	data->head_a->next->final_pos == data->size[2] - 1)
		ft_apply_command(data, 0, SA);
	if (data->head_a->value != data->max[2] &&
	data->size[1] && data->head_b->final_pos != 4)
	{
		ft_only_swap(data);
		ft_circle_sort(data);
	}
	if (data->size[1] && data->max[0] == data->max[2] &&
	data->head_b->final_pos == 4)
		ft_apply_command(data, 0, RRA);
	if (data->size[1] && data->head_a->value == data->max[2] &&
	data->head_b->final_pos != 4)
		ft_apply_command(data, 0, RA);
	if (!(data->size[1]) && ft_stack_sort(data->head_a))
		return (1);
	ft_apply_command(data, 1, PB);
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	return (0);
}

int		ft_four_five_sort(t_data *data)
{
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	while (data->size[0] != 3)
	{
		if (data->size[2] == 5 && data->head_a->final_pos == 3)
			ft_apply_command(data, 0, RA);
		ft_apply_command(data, 0, PA);
	}
	ft_min_max(data, 1);
	if (data->size[1] == 2 &&
	(data->head_b->value == data->max[2] && data->head_b->final_pos != 4)
	&& (data->head_b->value < data->head_b->next->value))
		ft_apply_command(data, 1, SB);
	if ((data->size[1] == 2 &&
	((data->head_b->final_pos == 2 && data->head_b->next->final_pos != 1) ||
	(data->head_b->final_pos == 4 && data->head_b->next->final_pos == 5)))
	|| (data->size[1] == 1 && (data->max[1] == data->max[2])))
		ft_sort_three(data, 0);
	else
		ft_help_sort(data);
	ft_hentai_sort(data);
	return (1);
}
