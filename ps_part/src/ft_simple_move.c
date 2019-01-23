/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:51:35 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/23 20:01:20 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//verification de stack B (du plus grand au plus petit)
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
//tri d'une taille de 2 et appel de sort_three
void	ft_two_three(t_data *data, int which, int both)
{
	if ((!which && ft_stack_sort(data->head_a))
	|| (which && ft_stackb_sort(data)))
		return ;
	if (data->size[which] > 3)
	{
		if (both && !which)
			ft_two_three(data, 1, 0);
		return ;
	}
	if (data->size[which] == 2)
	{
		ft_s_command(data, 'a' + which);
		ft_new_command(data, SA + which);
	}
	if (data->size[which] == 3)
		ft_sort_three(data, which, 0);
	if (both && !which)
		ft_two_three(data, 1, 0);
}
//si max en A[0]
void	ft_max_first(t_data *data, int which)
{
	if (!which && data->head_a->value == data->max[which])
	{
		ft_ra_command(data, which);
		ft_new_command(data, RA);
	}
}
//si min en A[end]
void	ft_min_end(t_data *data, int which)
{
	t_stack *tmp;

	tmp = data->head_a;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->value == data->min[2])
	{
		ft_rr_command(data, which);
		ft_new_command(data, (which) ? RRB : RRA);
	}
}
