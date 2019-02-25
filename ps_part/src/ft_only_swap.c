/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:30:56 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/25 15:34:13 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	faire un only_swap_first :
**		_ only SA?
**		# donner un tmp de la liste, swap et si sort_list, faire SA sur la liste
*/

/*
**	faire un only_swap_end :
**		# faire stack_sort avec une taille jusqu'a size - 3 ?
**		# OU si A[end] == max -1 et A[end - 1] == max
**				commandes sur un tmp si sort sur A ou return 0
**			_ rra rra sa ra ra
*/

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
	if ((tmp->final_pos == 2 && tmp->next->final_pos == 1) &&
	ft_only_swap_first(data))
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->final_pos == data->size[0] - 1 &&
	tmp->prev->final_pos == data->size[0]) && ft_only_swap_end(data))
		return (1);
	return (0);
}
