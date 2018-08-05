/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:17:03 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 11:17:10 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_init_list(t_stack *stack)
{
	stack->prev = NULL;
	stack->next = NULL;
	stack->value = 0;
}

t_data		*ft_data_fill(char **argv, int argc, t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
		return (NULL);
	if (!(stack_a = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	ft_init_list(stack_a);
	if (!(stack_a = ft_stack_fill(argv, argc, stack_a)))
		return (NULL);
	ft_min_max(data, 0);
	ft_size(data, 0);
	if (!(stack_b = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	ft_init_list(stack_b);
	return (data);
}

t_stack		*ft_stack_fill(char **argv, int argc, t_stack *stack)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			j = -1;
			if (!(tmp = ft_strsplit(argv[i], ' ')))
				return (NULL);
			while (tmp[++j])
			{
				if (!(ft_addbackstack(stack, ft_atoi(tmp[j]))))
					return (NULL);
			}
		}
		else
		{
			if (!ft_addbackstack(stack, ft_atoi(argv[i])))
				return (NULL);
		}
	}
	return (stack);
}

void		ft_size(t_data *data, int which) //0 == all		1 == a		2 == b
{
	t_stack *tmp;

	tmp = (which == 2) ? data->stack_b : data->stack_a;
	ft_bzero(data->size, 3);
	while (tmp->next)
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

	tmp = (which == 2) ? data->stack_b : data->stack_a;
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
