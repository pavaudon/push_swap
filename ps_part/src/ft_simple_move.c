/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicorn <unicorn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:51:35 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/17 18:17:10 by unicorn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackb_sort(t_data *data)
{
	t_stack *tmp;

	if (!data->head_b)
		return (1);
	tmp = data->head_b;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
/*
void	ft_two_three(t_data *data)
{
	if (ft_stack_sort(data->head_a) || data->size[0] > 3)
		return ;
	if (data->size[0] == 2)
	{
		ft_s_command(data, 'a');
		ft_new_command(data, SA);
	}
	if (data->size[0] == 3)
		ft_sort_three(data, which);
}

void	ft_max_first(t_data *data)
{
	if (data->head_a->value == data->max[0])
	{
		ft_ra_command(data, 0);
		ft_new_command(data, RA);
	}
}

void	ft_min_end(t_data *data)
{
	t_stack *tmp;

	tmp = data->head_a;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->value == data->min[2])
	{
		ft_rr_command(data, 0);
		ft_new_command(data, RRA);
	}
}*/
