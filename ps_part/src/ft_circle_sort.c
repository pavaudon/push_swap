/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:27:17 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/11 18:07:43 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_circle_sort_2(t_data *data, int value, int *sort)
{
	t_stack *tmp;

	tmp = data->head_a;
	*sort += 1;
	while (tmp && tmp->value != value)
	{
		if (*sort != tmp->final_pos)
			return (0);
		tmp = tmp->next;
		*sort += 1;
	}
	return (1);
}

int		ft_is_circle_sort(t_data *data)
{
	t_stack *tmp;
	int		sort;
	int		first;

	sort = 0;
	tmp = data->head_a;
	if (!tmp)
		return (0);
	ft_find_pos(data, 0, 0);
	while (tmp && tmp->value != data->min[0])
		tmp = tmp->next;
	first = tmp->actual_pos;
	while (tmp)
	{
		if (tmp->actual_pos != first &&
		(tmp->actual_pos - first + 1) != tmp->final_pos)
			return (0);
		sort++;
		tmp = tmp->next;
	}
	if (!(ft_is_circle_sort_2(data, data->min[0], &sort)))
		return (0);
	return ((first <= (data->size[0] / 2)) ? 2 : 1);
}

int		ft_circle_sort(t_data *data)
{
	int		res;

	ft_find_pos(data, 0, 0);
	res = ft_is_circle_sort(data);
	if (!res)
		return (0);
	while (data->head_a->value != data->min[0])
	{
		if (res == 1)
			ft_apply_command(data, 0, RA);
		else
			ft_apply_command(data, 0, RRA);
	}
	ft_print_stack(data, 'a', 0);
	return (1);
}
