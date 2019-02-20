/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_p_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicorn <unicorn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:21:12 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/20 16:56:32 by unicorn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap stack[0] et stack[1]
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
}

void	ft_pa_command(t_data *data)
{
	//ft_simple_printf("PA COMMAND\n");
	if (data->size[1] == 0)
	{
		if (data->size[0] > 1)
		{
			data->head_a = data->head_a->next;
			data->head_b = data->head_a->prev;
		}
		else
			data->head_b = data->head_a;
		data->head_b->prev = NULL;
		data->head_b->next = NULL;
	}
	else
	{
		if (data->size[0] > 1)
		{
			data->head_a = data->head_a->next;
			data->head_b->prev = data->head_a->prev;
		}
		else
			data->head_b->prev = data->head_a;
		data->head_b->prev->next = data->head_b;
		data->head_b = data->head_b->prev;
	}
	if (data->size[0] > 1)
		data->head_a->prev = NULL;
	else
		data->head_a = NULL;
	data->size[0] -= 1;
	data->size[1] += 1;
}

void	ft_pb_command(t_data *data)
{
	//ft_simple_printf("PB COMMAND\n");
	if (data->size[0] == 0)
	{
		if (data->size[1] > 1)
		{
			data->head_b = data->head_b->next;
			data->head_a = data->head_b->prev;
		}
		else
			data->head_a = data->head_b;
		data->head_a->prev = NULL;
		data->head_a->next = NULL;
	}
	else
	{
		if (data->size[1] > 1)
		{
			data->head_b = data->head_b->next;
			data->head_a->prev = data->head_b->prev;
		}
		else
			data->head_a->prev = data->head_b;
		data->head_a->prev->next = data->head_a;
		data->head_a = data->head_a->prev;
	}
	if (data->size[1] > 1)
		data->head_b->prev = NULL;
	else
		data->head_b = NULL;
	data->size[0] += 1;
	data->size[1] -= 1;
}
//appel pa ou pb
void	ft_p_command(t_data *data, char which)
{
	if (which == 'a' && data->size[0] >= 1)
		ft_pa_command(data);
	else if (which == 'b' && data->size[1] >= 1)
		ft_pb_command(data);
	//ft_print_stack(data, 'a', 1);
}
