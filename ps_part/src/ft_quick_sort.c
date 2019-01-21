/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:31:40 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/21 19:46:44 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_pivot_b(t_data *data, int high)
{
	t_stack	*i;
	t_stack	*j;

	i = data->head_a;
	j = data->head_a->next;
	while (j->value <= high)
	{
		if (j->value <= high)
		{
			i = i->next;
			ft_simple_printf("PB\n");
			ft_pb_command(data);
			ft_new_command(data, PB);
		}
		else
		{
			ft_simple_printf("RB\n");
			ft_rb_command(data, 'b');
			ft_new_command(data, RB);
		}
		j = j->next;
	}
	return (i->next->value);
}

int		ft_pivot_a(t_data *data, int high)
{
	t_stack	*i;
	t_stack	*j;

	i = data->head_a;
	j = data->head_a->next;
	ft_simple_printf("PIVOT A TAMERE\t\tj->value : '%d'\thigh : '%d'\n\n\n", j->value, high);
	if (j->value > high)
	{
		ft_simple_printf("RA\n");
		ft_ra_command(data, 'a');
		ft_new_command(data, RA);
		return (i->value);
	}
	while (j->value <= high)
	{
		ft_simple_printf("BOUCLETAMER\n");
		if (j->value <= high)
		{
			ft_simple_printf("PA\n");
			i = i->next;
			ft_pa_command(data);
			ft_new_command(data, PA);
		}
		j = j->next;
	}
	return ((i->next) ? i->next->value : i->value);
}

int		ft_pivot_next(t_stack *stack, int pivot)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->next->value == pivot)
			return (tmp->next->value);
		tmp = tmp->next;
	}
	return (tmp->value);
}

long		ft_high(t_data *data)
{
	t_stack *tmp;

	if (data->head_a && data->size[0] > 3)
		tmp = data->head_a;
	else if (data->head_b && data->size[1] > 3)
		tmp = data->head_b;
	else
		return (2147483649);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

int		ft_low(t_data *data)
{
	t_stack *tmp;

	if (data->head_a && data->size[0] > 3)
	{
		tmp = data->head_a;
		while (tmp->next)
			tmp = tmp->next;
		if (data->head_a->value > tmp->value)
			return (data->head_a->next->value);
		return (data->head_a->value);
	}
	else if (data->head_b && data->size[1] > 3)
	{
		tmp = data->head_b;
		while (tmp->next)
			tmp = tmp->next;
		if (data->head_b->value > tmp->value)
			return (data->head_b->next->value);
		return (data->head_b->value);
	}
	return (0);
}

void	ft_algoqs(t_data *data, int low, long high)
{
	int pivot;

	high = ft_high(data);
	if (high == 2147483649)
	{
		ft_print_stack(data, 'a', 1);
		ft_simple_printf("THREEEEEEE\n");
		return ;
	}
	low = ft_low(data);
	ft_simple_printf("LOW : '%d'\tHIGH : '%d'\n", low, (int)high);
	ft_find_pos(data, 'a', 1);
	//ft_print_stack(data, 'a', 1);
	if (data->size[0] == data->size[2] || ft_stack_sort(data->head_a))
		return ;
	if (data->size[0] > 3 && (low < (int)high))
	{
		ft_simple_printf("AAA LOW < HIGH\n");
		pivot = ft_pivot_a(data, high);
		ft_simple_printf("pivot : '%d'\n", pivot);
		ft_algoqs(data, low, pivot);
		ft_algoqs(data, ft_pivot_next(data->head_a, pivot), high);
	}
	else if (data->size[1] > 3 && (low < high))
	{
		pivot = ft_pivot_b(data, high);
		ft_algoqs(data, low, pivot);
		ft_algoqs(data, ft_pivot_next(data->head_b, pivot), high);
	}
}

int		ft_quick_sort(t_data *data)
{
	ft_simple_printf("QUICKSORT\n");
	ft_algoqs(data, 0, 0);
	if (data->size[1] || !ft_stack_sort(data->head_a))
		ft_print_stack(data, 'a', 1);
	else
		printf("TAMERELAGROSSECHIENNE\n");
	return (1);
}
