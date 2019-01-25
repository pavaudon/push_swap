/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_p_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:21:12 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/25 14:55:54 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//swap stack[0] et stack[1]
void	ft_s_command(t_data *data, char which)
{
	int		swap;
	t_stack	*tmp;

	printf("S COMMAND\n");
	if (which == 'b' ? data->size[1] > 1 : data->size[0] > 1)
	{
		swap = (which == 'b') ? data->head_b->value : data->head_a->value;
		tmp = (which == 'b') ? data->head_b : data->head_a;
		tmp->value = tmp->next->value;
		tmp->next->value = swap;
	}
	ft_print_stack(data, (which == 's' ? 'a' : which), 0);
	if (which == 's')
		ft_s_command(data, 'b');
}

/*
//put A[0] en B[0]
void	ft_pa_command(t_data *data)
{
	//printf("pa COMMAND\n");
	ft_pushfront2(&(data->head_b), data->head_a->value);
	if (data->size[0] > 1)
	{
		data->head_a = data->head_a->next;
		free(data->head_a->prev);
	}
	else
	{
		free(data->head_a);
		data->head_a = NULL;
	}
	data->size[0] -= 1;
	data->size[1] += 1;
}
*/

void	ft_pa_command(t_data *data)
{
	ft_simple_printf("PA COMMAND\n");
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
/*
//put B[0] en A[0]
void	ft_pb_command(t_data *data)
{
	//printf("pb COMMAND\n");
	ft_pushfront2(&(data->head_a), data->head_b->value);
	if (data->size[1] > 1)
	{
		data->head_b = data->head_b->next;
		free(data->head_b->prev);
	}
	else
	{
		free(data->head_b);
		data->head_b = NULL;
	}
	data->size[0] += 1;
	data->size[1] -= 1;
}
*/

void	ft_pb_command(t_data *data)
{
	ft_simple_printf("PB COMMAND\n");
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
	ft_print_stack(data, 'a', 1);
}
