/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_good_place.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:28:49 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/28 21:43:33 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			rev_count(t_data *data, t_stack *check)
{
	int		m;
	int		i;
	int		lv;
	t_stack	*tmp_a;

	i = 1;
	m = 0;
	if (check == data->max || check->wgt >= 0)	//data->max == *max
		return (check == data->max ? 0 : check->wgt);
	lv = data->max->v;		//*max value
	tmp_a = data->max->prev;	//*max prev
	while (tmp_a != check)
	{
		if (tmp_a->v > check->v && (tmp_a->v < lv || tmp_a->wgt > m))
		{
			if (tmp_a->wgt < 0)
				tmp_a->wgt = i;			//a ajotuer dans .h
			if (m < tmp_a->wgt && (check->nxtw = tmp_a))
				m = tmp_a->wgt;
			lv = tmp_a->v;
			i++;
		}
		tmp_a = tmp_a->prev;
	}
	return (m + 1);
}

void		premark(t_data *data)
{
	t_stack	*tmp_a;

	data->max->wgt = 0;	//*max wgt
	data->max->mark = 1;	//*max mark
	tmp_a = data->max->prev;	//*max prev
	tmp_a = data->head_a;
	while (tmp_a)
		tmp->next;
	while (tmp_a != data->min[0])
	{
		tmp_a->wgt = rev_count(data, tmp_a);
		tmp_a = tmp_a->prev;
	}
	tmp_a->wgt = rev_count(data, tmp_a);
	tmp_a = data->min; //*min
	while (tmp_a)
	{
		tmp_a->mark = 1;
		tmp_a = tmp_a->nxtw;		//a ajouter dans .h
	}
}
