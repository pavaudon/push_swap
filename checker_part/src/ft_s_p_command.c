/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_p_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:21:12 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/06 20:04:57 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s_process(t_stack *old_two, t_stack *old_one)
{
	t_stack	*third;

	third = old_two->next;
	old_one->prev = old_two;
	old_two->next = old_one;
	old_two->prev = NULL;
	old_one->next = third;
	if (third)
		third->prev = old_one;
}

void	ft_s_command(t_data *data, char which)
{
	if (which == 'b' && data->size[1] > 1)
	{
		ft_s_process(data->head_b->next, data->head_b);
		data->head_b = data->head_b->prev;
	}
	else if (which != 'b' && data->size[0] > 1)
	{
		ft_s_process(data->head_a->next, data->head_a);
		data->head_a = data->head_a->prev;
	}
	if (which == 's' && data->size[1] > 1)
		ft_s_command(data, 'b');
	ft_print_stack(data, 'a', 0);
}

void	ft_pa_command(t_data *data)
{
	t_stack	*ea;
	t_stack	*eb;

	ft_simple_printf("PA COMMAND\n");
	eb = data->head_a;
	ea = data->head_b;
	if (!data->size[1])
		return ;
	data->head_b = ea->next;
	if (data->head_b)
		data->head_b->prev = NULL;
	ea->next = eb;
	if (eb)
		eb->prev = ea;
	ea->prev = NULL;
	data->head_a = ea;
	data->size[1]--;
	data->size[0]++;
	return ;
}

void	ft_pb_command(t_data *data)
{
	t_stack	*ea;
	t_stack	*eb;

	ft_simple_printf("PB COMMAND\n");
	ea = data->head_a;
	eb = data->head_b;
	if (!data->size[0])
		return ;
	data->head_a = ea->next;
	if (data->head_a)
		data->head_a->prev = NULL;
	ea->next = eb;
	if (eb)
		eb->prev = ea;
	ea->prev = NULL;
	data->head_b = ea;
	data->size[0]--;
	data->size[1]++;
	return ;
}

void	ft_p_command(t_data *data, char which)
{
	if (which == 'a' && data->size[1] >= 1)
		ft_pa_command(data);
	else if (which == 'b' && data->size[0] >= 1)
		ft_pb_command(data);
	ft_print_stack(data, 'a', 1);
}
