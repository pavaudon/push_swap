/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:48:01 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/12 18:50:40 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**
**  1 2 3
**
**  3 2 1 SA RRA	OK
**  3 1 2 RA		OK
**  2 1 3 SA		OK
**  2 3 1 RRA		OK
**  1 3 2 SA RA		OK
**
*/
 
//tri d'une taille de 3 pour B (du plus grand au plus petit)
int		ft_sort_threeb(t_data *data, int which)
{
	t_stack *tmp;
	int		again;

	again = 0;
	if (data->size[1] != 3)
		return (0);
	tmp = data->head_b;
	while (!again)
	{
		tmp = data->head_b;
		ft_find_pos(data, 1, 0);
		if ((tmp->final_pos == 1 && tmp->next->final_pos == 3) ||
		(tmp->final_pos == 2 && tmp->next->final_pos == 1) ||
		(tmp->final_pos == 3 && tmp->next->final_pos == 2))
			ft_apply_command(data, which, SB);
		else if (tmp->next->final_pos == 3 && tmp->final_pos == 2)
			ft_apply_command(data, which, RRB);
		else if (tmp->final_pos == 3 && tmp->next->final_pos == 1)
			ft_apply_command(data, which, RB);
		if (ft_stackb_sort(data))
			again++;
	}
	return (1);
}
//tri d'une taille de 3 pour A (du plus petit au plus grand)
int		ft_sort_three(t_data *data, int which, int both)
{
	t_stack *tmp;
	int		again;

	again = 0;
	if (data->size[which] != 3)
		return (0);
	if (which && !both)
		return (ft_sort_threeb(data, which));
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
	ft_print_stack(data, 'a' + which, 0);
	if (!which && both && data->size[1] == 3)
		return (ft_sort_threeb(data, which));
	return (1);
}
