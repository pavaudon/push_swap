/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:46:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/08 15:31:48 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*get_link(t_data *data, int where)
{
	t_stack *tmp;
	int		comp;

	comp = 0;
	tmp = data->head_a;
	if (where > 0)
	{
		comp = (where == 1) ? data->min[0] : data->max[0];
		while (tmp && tmp->value != comp)
			tmp = tmp->next;
	}
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
	}
	return (tmp);
}

int			rev_count(t_data *data, t_stack *check)
{
	int		m;
	int		i;
	int		max;
	t_stack	*tmp_a;

	i = 0;
	m = 0;
	tmp_a = get_link(data, MAX_VAL);
	if (check == tmp_a || check->wgt >= 0)
		return (check == tmp_a ? 0 : check->wgt);
	max = data->max[0];
	while (tmp_a != check)
	{
		if (tmp_a->value > check->value
			&& (tmp_a->value < max || tmp_a->wgt > m) && ++i)
		{
			tmp_a->wgt = (tmp_a->wgt < 0) ? i : tmp_a->wgt;
			if (m < tmp_a->wgt && (check->nxtw = tmp_a))
				m = tmp_a->wgt;
			max = tmp_a->value;
		}
		if (!(tmp_a = tmp_a->prev))
			tmp_a = get_link(data, LAST_VAL);
	}
	return (m + 1);
}

void		premark(t_data *data)
{
	t_stack	*tmp_a;

	tmp_a = get_link(data, MAX_VAL);
	tmp_a->mark = 1;
	while (tmp_a->value != data->min[0])
	{
		tmp_a->wgt = (tmp_a->value == data->max[0]) ? 0
		: rev_count(data, tmp_a);
		if (!(tmp_a = tmp_a->prev))
			tmp_a = get_link(data, LAST_VAL);
	}
	tmp_a->wgt = rev_count(data, tmp_a);
	tmp_a = get_link(data, MIN_VAL);
	while (tmp_a)
	{
		tmp_a->mark = 1;
		tmp_a = tmp_a->nxtw;
	}
}
