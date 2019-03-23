/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:30:56 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/23 14:22:10 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_back_swap(t_data *data)
{
	ft_ra_command(data, 'a');
	ft_ra_command(data, 'a');
	ft_s_command(data, 'a');
	ft_rr_command(data, 'a');
	ft_rr_command(data, 'a');
}

int		ft_only_swap_end(t_data *data)
{
	ft_rr_command(data, 'a');
	ft_rr_command(data, 'a');
	ft_s_command(data, 'a');
	ft_ra_command(data, 'a');
	ft_ra_command(data, 'a');
	if (ft_stack_sort(data->head_a))
	{
		ft_new_command(data, RRA);
		ft_new_command(data, RRA);
		ft_new_command(data, SA);
		ft_new_command(data, RA);
		ft_new_command(data, RA);
		return (1);
	}
	else
		ft_back_swap(data);
	return (0);
}

int		ft_only_swap_first(t_data *data)
{
	ft_s_command(data, 'a');
	if (ft_stack_sort(data->head_a))
		ft_new_command(data, SA);
	else
	{
		ft_s_command(data, 'a');
		return (0);
	}
	return (1);
}

int		ft_only_swap(t_data *data)
{
	t_stack *tmp;

	tmp = data->head_a;
	if (data->size[0] <= 3)
		return (0);
	if ((tmp->final_p == 2 && tmp->next->final_p == 1)
		&& ft_only_swap_first(data))
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->final_p == data->size[0] - 1
		&& tmp->prev->final_p == data->size[0]) && ft_only_swap_end(data))
		return (1);
	return (0);
}
