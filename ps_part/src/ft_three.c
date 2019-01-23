/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:48:01 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/23 14:22:34 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*

1 2 3

3 2 1 SA RRA
3 1 2 RA		OK
2 1 3 SA		OK
2 3 1 RRA		OK
1 3 2 SA RA

*/

/*

3 2 1

3 1 2 SB RB
2 1 3 RRB
2 3 1 SB
1 2 3 SA RRB
1 3 2 RB

*/


void	ft_apply_three(t_data *data, int which, char command)
{
	if (command == PA)
		ft_p_command(data, 'a' + which);
	else if (command == RA && which)
		ft_rb_command(data, 'b');
	else if (command == RA && !which)
		ft_ra_command(data, 'a');
	else if (command == RRA)
		ft_rr_command(data, 'a' + which);
	else
		return ;
	ft_new_command(data, command);
}

int		ft_sort_threeb(t_data *data, int which)
{
	t_stack *tmp;
	int		again;

	again = 0;
	tmp = data->head_b;
	if (data->size[1] != 3)
		return (0);
	while (!again)
	{
		if (tmp->final_pos == 3 && tmp->next->final_pos == 1)
			ft_apply_three(data, which, RB);
		if (tmp->next->final_pos == 1 && tmp->final_pos == 2)
			ft_apply_three(data, which, SB);
		if (tmp->next->next->final_pos == 1 && tmp->final_pos == 2)
			ft_apply_three(data, which, RRB);
		if (ft_stack_sort(tmp))
			again++;
	}
	return (1);
}

int		ft_sort_three(t_data *data, int which, int both)
{
	t_stack *tmp;
	int		again;

	again = 0;
	if (data->size[which] != 3)
		return (0);
	if (which && !both)
		return (ft_sort_threeb(data, which));
	tmp = data->head_a;
	while (!again)
	{
		if (tmp->final_pos == 3 && tmp->next->final_pos == 1)
			ft_apply_three(data, which, RA);
		if (tmp->next->final_pos == 1 && tmp->final_pos == 2)
			ft_apply_three(data, which, SA);
		if (tmp->next->next->final_pos == 1 && tmp->final_pos == 2)
			ft_apply_three(data, which, RRA);
		if (ft_stack_sort(tmp))
			again++;
	}
	if (!which && both && data->size[which] == 3)
		return (ft_sort_threeb(data, which));
	return (1);
}
