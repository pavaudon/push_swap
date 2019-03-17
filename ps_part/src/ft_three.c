/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicorn <unicorn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:48:01 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/17 18:14:39 by unicorn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort_three(t_data *data)
{
	t_stack *tmp;
	int		again;

	again = 0;
	if (data->size[0] != 3)
		return (0);
	while (!again)
	{
		tmp = data->head_a;
		ft_find_pos(data, 0, 0);
		if (tmp->final_p == 3 && tmp->next->final_p == 1)
			ft_apply_command(data, 0, RA);
		else if ((tmp->next->final_p == 3 && tmp->final_p == 1) ||
		(tmp->final_p == 3 && tmp->next->final_p == 2) ||
		(tmp->final_p == 2 && tmp->next->final_p == 1))
			ft_apply_command(data, 0, SA);
		else if (tmp->next->final_p == 3 && tmp->final_p == 2)
			ft_apply_command(data, 0, RRA);
		if (ft_stack_sort(data->head_a))
			again++;
	}
	return (1);
}
