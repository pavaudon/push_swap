/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:48:01 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/27 19:24:17 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort_three(t_data *data, int which)
{
	t_stack *tmp;
	int		again;

	again = 0;
	if (data->size[which] != 3)
		return (0);
	while (!again)
	{
		tmp = data->head_a;
		ft_find_pos(data, which, 0);
		if (tmp->final_pos == 3 && tmp->next->final_pos == 1)
			ft_apply_command(data, which, RA);
		else if ((tmp->next->final_pos == 3 && tmp->final_pos == 1) ||
		(tmp->final_pos == 3 && tmp->next->final_pos == 2) ||
		(tmp->final_pos == 2 && tmp->next->final_pos == 1))
			ft_apply_command(data, which, SA);
		else if (tmp->next->final_pos == 3 && tmp->final_pos == 2)
			ft_apply_command(data, which, RRA);
		if (ft_stack_sort(data->head_a))
			again++;
	}
	return (1);
}
