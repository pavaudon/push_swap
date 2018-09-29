/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 11:25:12 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/25 11:25:13 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  ft_init_stack(t_stack *stack)
{
  stack->prev = NULL;
	stack->next = NULL;
	stack->value = 0;
}

t_data  *ft_data_fill(t_data *data)
{
	if (!(data->stack_a = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	ft_init_stack(data->stack_a);
	if (!(data->stack_a = ft_stack_fill(data->stack_a, data)))
		return (NULL);
	ft_min_max(data, 0);
	ft_size(data, 0);
	if (!(data->stack_b = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	ft_init_stack(data->stack_b);
	return (data);
}

t_stack		*ft_stack_fill(t_stack *stack_a, t_data *data)
{
	int i;

	i = -1;
	while (++i < data->nb_value)
	{
		if (!ft_addbackstack(stack_a, data->check[i], i))
			return (NULL);
	}
	return (stack_a);
}

void		ft_size(t_data *data, int which) //0 == all		1 == a		2 == b
{
	t_stack *tmp;

	tmp = (which == 2) ? data->stack_b : data->stack_a;
	ft_bzero(data->size, 3);
	while (tmp)
	{
		data->size[which] += 1;
		tmp = tmp->next;
	}
	if (!which)
		data->size[1] = data->size[0];
}

void		ft_min_max(t_data *data, int which)
{
	t_stack *tmp;

	tmp = data->stack_a;
	data->min[which] = tmp->value;
	data->max[which] = tmp->value;
	while (tmp->next)
	{
		data->min[which] = (data->min[which] > tmp->value) ? tmp->value :
		data->min[which];
		data->max[which] = (data->max[which] < tmp->value) ? tmp->value :
		data->max[which];
		tmp = tmp->next;
	}
	if (!which)
	{
		data->min[1] = data->min[0];
		data->max[1] = data->max[0];
	}
}
