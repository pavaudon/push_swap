/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_p_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:21:12 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/28 19:18:09 by pavaudon         ###   ########.fr       */
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
	ft_print_stack(data, 'a', 0);
}

void	ft_pa_command(t_data *data)
{
	ft_simple_printf("PA COMMAND\n");
	t_stack	*ea;
	t_stack	*eb;

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
	ft_simple_printf("PB COMMAND\n");
	t_stack	*ea;
	t_stack	*eb;

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
//appel pa ou pb
void	ft_p_command(t_data *data, char which)
{
	if (which == 'a' && data->size[1] >= 1)
		ft_pa_command(data);
	else if (which == 'b' && data->size[0] >= 1)
		ft_pb_command(data);
	ft_print_stack(data, 'a', 1);
}
