/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_opti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:41:49 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/27 20:42:33 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		move_top(t_stack *to_move, t_stack *head)
{
	int		move;
	int		size;
	t_stack	*tmp;

	move = 0;
	size = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp == to_move)
			move = size;
		size++;
		tmp = tmp->next;
	}
	if (move >= size / 2)
		move = -(size - move);
	return (move);
}

int		ft_abs(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

t_stack	*go_min_max(t_data *data, int min_max)
{
	t_stack *tmp;

	tmp = data->head_a;
	while (tmp)
	{
		if (min_max && tmp->value == data->max[0])
			return (tmp);
		if (!min_max && tmp->value == data->min[0])
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int		move_to_limit(t_data *data, int nb)
{
	t_stack		*limit_low;
	t_stack		*limit_up;
	t_stack		*tmp;
	int			low;
	int			up;

	limit_up = go_min_max(data, 1);
	limit_low = go_min_max(data, 0);
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->mark)
		{
			if (tmp->value > nb && tmp->value < limit_up->value)
				limit_up = tmp;
			if (tmp->value < nb && tmp->value > limit_low->value)
				limit_low = tmp;
		}
		tmp = tmp->next;
	}
	low = move_top(limit_low, data->head_a) + 1;
	up = move_top(limit_up, data->head_a);
	return (ft_abs(up) < ft_abs(low) ? up : low);
}

void	get_move_count(t_data *data)
{
	t_stack *tmp;

	tmp = data->head_b;
	while (tmp)
	{
		tmp->mvb = move_top(tmp, data->head_b);
		tmp->mva = move_to_limit(data, tmp->value);
		tmp->mv_count = ft_abs(tmp->mvb) + ft_abs(tmp->mva);
		tmp = tmp->next;
	}
}

void	push_opti(t_data *data)
{
	t_stack	*move;
	t_stack	*tmp;

	while ((move = data->head_b) != NULL)
	{
		get_move_count(data);
		tmp = (data->size[1] > 1) ? data->head_b->next : NULL;
		while (tmp)
		{
			if (move->mv_count > tmp->mv_count)
				move = tmp;
			tmp = tmp->next;
		}
		while (move->mvb > 0 && move->mvb--)
			ft_apply_command(data, 1, RB);
		while (move->mvb < 0 && move->mvb++)
			ft_apply_command(data, 1, RRB);
		while (move->mva > 0 && move->mva--)
			ft_apply_command(data, 0, RA);
		while (move->mva < 0 && move->mva++)
			ft_apply_command(data, 0, RRA);
		move->mark = 1;
		data->marks += 1;
		ft_apply_command(data, 1, PB);
	}
}
