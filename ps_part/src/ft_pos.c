/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:35:38 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/12 16:18:01 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//nombre de move a faire pour etre a la bonne place (a enlever?)
void	ft_move_pos(t_data *data, char which)	//int both?
{
	t_stack *tmp;

	tmp = (which == 'b') ? data->head_b : data->head_a;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp->move_pos = tmp->actual_pos - tmp->final_pos;
		tmp = tmp->next;
	}
}
//nombre de bad positions a utiliser apres pour reduire le nombre de commandes et pour ft_five a faire
int		ft_bad_pos(t_data *data, char which)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = (which == 'b') ? data->head_a : data->head_a;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		if (tmp->actual_pos != tmp->final_pos)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int		ft_final_pos(t_data *data, int value, int which)
{
	t_stack *tmp;
	int		pos;

	pos = data->size[which];
	ft_min_max(data, which);
	if (value == data->min[which])
		return ((which) ? pos : 1);
	if (value == data->max[which])
		return ((which) ? 1 : pos);
	tmp = (which) ? data->head_b : data->head_a;
	if (!tmp)
		return (0);
	while (tmp)
	{
	//	if (!which)
	//	{
			pos -= (value < tmp->value) ? 1 : 0;
	//	}
	//	else if (which)
	//		pos -= (value > tmp->value) ? 1 : 0;
		tmp = tmp->next;
	}
	return (pos);
}
//only actual_pos
void	ft_actual_pos(t_data *data, int which, int both)
{
	t_stack *tmp;
	int		i;

	tmp = (which == 'a') ? data->head_a : data->head_b;
	if (!tmp)
	{
		if (both && !which)
			ft_actual_pos(data, 1, 0);
		return ;
	}
	i = 0;
	while (tmp)
	{
		tmp->actual_pos = ++i;
		tmp = tmp->next;
	}
	if (both && !which)
		ft_actual_pos(data, 1, 0);
}
//maj de actual_pos et appel de final_pos
void	ft_find_pos(t_data *data, int which, int both)
{
	t_stack	*tmp;
	int		i;

	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
	{
		if (both && !which)
			ft_find_pos(data, 1, 0);
		return ;
	}
	i = 0;
	while (tmp)
	{
		tmp->final_pos = ft_final_pos(data, tmp->value, which);
		tmp->actual_pos = ++i;
		tmp = tmp->next;
	}
	if (both && !which)
		ft_find_pos(data, 1, 0);
}