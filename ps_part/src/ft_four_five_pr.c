/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five_pr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:42:23 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/13 19:43:27 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_help_c_p(t_data *data, int f_first, int *fp)
{
	t_stack	*tmp;
	int		help;

	tmp = data->head_a;
	help = 0;
	while (tmp)
	{
		if (tmp->final_pos != f_first)
			fp[help++] = tmp->final_pos;
		tmp = tmp->next;
	}
}

void	ft_circle_pos(t_data *data, int f_first)
{
	t_stack *tmp;
	int		help;
	int		fp[2];
	int		subst;

	ft_help_c_p(data, f_first, fp);
	help = 2;
	subst = (fp[0] > fp[1]) ? 1 : 0;
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->final_pos != f_first)
		{
			if (subst && ((f_first > fp[0]) || (f_first < fp[1])))
				tmp->circle_pos = (help == 2) ? 3 : 2;
			else if (!subst && ((f_first > fp[1]) || (f_first < fp[0])))
				tmp->circle_pos = (help == 2) ? 2 : 3;
			help--;
		}
		else
			tmp->circle_pos = 1;
		tmp = tmp->next;
	}
}

int		ft_new_first(t_data *data)
{
	t_stack *tmp;
	int		search;
	int		follow;

	tmp = data->head_a;
	if (data->head_b->final_pos == data->max[2] - 1 &&
	data->max[0] == data->max[2])
		return (data->max[0]);
	if ((data->head_b->value == data->max[2]) ||
	(data->head_b->value == data->min[2] + 1))
		return (data->min[0]);
	search = (data->head_b->final_pos <= 3) ? 1 : -1;
	follow = (data->size[1] == 2)
	? data->head_b->final_pos - data->head_b->next->final_pos : 0;
	search += (follow != 1 && follow != -1) ? 0 : search;
	while (tmp)
	{
		if (tmp->final_pos - search == data->head_b->final_pos)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (tmp->final_pos);
}
