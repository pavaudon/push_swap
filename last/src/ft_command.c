/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:38:10 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/22 15:38:11 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s_command(t_data *data, char which)
{
	int		swap;
	t_stack	*tmp;

	swap = (which == 'b') ? data->stack_b->value : data->stack_a->value;
	tmp = (which == 'b') ? data->stack_b : data->stack_a;
	if (which == 'b' ? data->size[2] > 1 : data->size[1] > 1)
	{
		tmp->value = tmp->next->value;
		tmp->next->value = swap;
		ft_print_stack(data, which, (which == 'a' ? 0 : 1));
	}
}

void 	ft_pa_command(t_data *data)
{
	ft_addbeginstack(&(data->stack_b), data->stack_a->value, data->size[2]);

	if (data->size[1] > 1)
	{
		data->stack_a = data->stack_a->next;
		data->stack_a->prev = NULL;
	}
	else
		data->stack_a = NULL;
	data->size[1] -= 1;
	data->size[2] += 1;
	data->stack_b = (data->size[2] > 1) ? data->stack_b->prev : data->stack_b;
}

void 	ft_pb_command(t_data *data)
{
	ft_addbeginstack(&(data->stack_a), data->stack_b->value, data->size[1]);
	if (data->size[2] > 1)
	{
		data->stack_b = data->stack_b->next;
		data->stack_b->prev = NULL;
	}
	else
		data->stack_b = NULL;
	data->size[1] += 1;
	data->size[2] -= 1;
	data->stack_a = (data->size[1] > 1) ? data->stack_a->prev : data->stack_a;
}

void	ft_p_command(t_data *data, char which)
{
	if (which == 'a' && data->size[1])
		ft_pa_command(data);
	else if (which == 'b' && data->size[2])
		ft_pb_command(data);
	ft_print_stack(data, 'a', 1);
}

void	ft_r_command(t_data *data, char which)
{
	t_stack *tmp;
	t_stack	*begin;
	t_stack *link;

	tmp = (which == 'b') ? data->stack_b : data->stack_a;
	begin = (which == 'b') ? data->stack_b : data->stack_a;
	link = (which == 'b') ? data->stack_b : data->stack_a;
	while (tmp)
		tmp = tmp->next;
	ft_simple_printf("tmp to the end\n");
	begin = begin->next;
	ft_simple_printf("begin == 2nd\n");
	begin->prev = NULL;
	ft_simple_printf("begin->prev == NULL\n");
	link->prev = tmp;
	ft_simple_printf("link after tmp\n");
	link->next = NULL;
	ft_simple_printf("link == the end\n");
	tmp->next = link;
	ft_simple_printf("tmp is before link\n");
	ft_simple_printf("stack start in begin\n");
	ft_print_stack(data, (which == 'r' ? 'a' : which), (which == 'r' ? 1 : 0));
	if (which == 'r')
		ft_r_command(data, 'b');
}

void	ft_rr_command(t_data *data, char which)
{
	t_stack *tmp;
	t_stack	*begin;

	tmp = (which == 'b') ? data->stack_b : data->stack_a;
	begin = (which == 'b') ? data->stack_b : data->stack_a;
	while (tmp->next)
		tmp = tmp->next;
	begin->prev = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = begin;
	ft_print_stack(data, (which == 'r' ? 'a' : which), (which == 'r' ? 1 : 0));
	if (which == 'r')
		ft_rr_command(data, 'b');
}
