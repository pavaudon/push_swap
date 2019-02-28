/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:47:32 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/28 19:21:12 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_g_p(t_data *data, t_stack *check)
{
	t_stack *tmp;
	int		value;
	int		count;

	tmp = check;
	value = tmp->value;
	count = 0;
	while (tmp)
	{
		while (tmp && (tmp->value != data->max[0]))
		{
			if (tmp->value > value && ++count)
				value = tmp->value;
			tmp = tmp->next;
		}
		if (tmp && tmp->value == data->max[0])
		{
			check->cgp = count + 1;
			data->count_g_p = (count > data->count_g_p)
			? count + 1 : data->count_g_p;
			return ;
		}
		tmp = data->head_a;
	}
}

void	ft_mark_g_p(t_data *data)
{
	t_stack *tmp;
	int		value;

	tmp = data->head_a;
	data->marks += data->count_g_p;
	ft_simple_printf("COUNT G P : '%d'\n", data->count_g_p + 2);
	while (tmp && tmp->cgp != data->count_g_p)
		tmp = tmp->next;
	if (!tmp)
		return ;
	tmp->mark = 1;
	value = tmp->value;
	while (tmp)
	{
		while (tmp && tmp->value != data->max[0])
		{
			if (tmp->value > value && ((value = tmp->value) || 1))
				tmp->mark = 1;
			tmp = tmp->next;
		}
		if (tmp && tmp->value == data->max[0])
			return ;
		tmp = data->head_a;
	}
}

void	ft_good_place(t_data *data)
{
	t_stack *tmp;

	ft_simple_printf("GOOD PLACE A FAIRE EN RECURSIF POUR LE MEILLEUR CAS\n");
	data->count_g_p = 0;
	tmp = data->head_a;
	while (tmp && (tmp->value != data->min[0]))
		tmp = tmp->next;
	if (tmp && tmp->final_pos != data->size[0])
		tmp = tmp->next;
	else
		tmp = data->head_a;
	while (tmp)
	{
		while (tmp && tmp->value != data->max[0])
		{
			ft_count_g_p(data, tmp);
			tmp = tmp->next;
		}
		if (tmp && tmp->value == data->max[0])
			tmp = NULL;
		else
			tmp = data->head_a;
	}
	if (data->count_g_p != 0)
		ft_mark_g_p(data);
}
