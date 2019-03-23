/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_four_five_pr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:55:32 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/23 16:13:57 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_help_c_p(t_data *data, int f_first, int *fp)
{
	t_stack	*tmp;
	int		i;

	tmp = data->head_a;
	i = 0;
	while (tmp)
	{
		if (tmp->value != f_first)
			fp[i++] = tmp->final_p;
		tmp = tmp->next;
	}
}

void	ft_circle_pos(t_data *data, int f_first)
{
	t_stack *tmp;
	int		*fp;

	if (!(fp = (int*)ft_memalloc(sizeof(int) * 2)))
		return ;
	ft_help_c_p(data, f_first, fp);
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->final_p == fp[0])
			tmp->circle_pos = (fp[0] > fp[1]) ? 3 : 2;
		else if (tmp->final_p == fp[1])
			tmp->circle_pos = (fp[0] > fp[1]) ? 2 : 3;
		else
			tmp->circle_pos = 1;
		tmp = tmp->next;
	}
	free(fp);
}

int		ft_new_first(t_data *data)
{
	t_stack *tmp;
	int		search;
	int		follow;

	tmp = data->head_a;
	if (data->head_b->final_p == data->size[2] - 1
		&& data->max[0] == data->max[2])
		return (data->max[0]);
	if ((data->head_b->value == data->max[2])
		|| (data->head_b->value == data->min[2]))
		return (data->min[0]);
	search = (data->head_b->final_p <= 3) ? 1 : -1;
	follow = (data->size[1] == 2)
	? data->head_b->final_p - data->head_b->next->final_p : 0;
	search += (follow && (follow != 1 && follow != -1)) ? follow : 0;
	while (tmp)
	{
		if (tmp->final_p - search == data->head_b->final_p)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (tmp->value);
}
