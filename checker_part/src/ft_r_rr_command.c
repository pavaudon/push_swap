/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rr_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:20:49 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/06 20:02:53 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ra_command(t_data *data, char which)
{
	t_stack *tmp;

	ft_simple_printf("RA COMMAND\n");
	if (data->size[0] < 2)
	{
		if (data->size[0] == 2)
			ft_s_command(data, 'a');
		if (which == 'r')
			ft_rb_command(data, 'b');
		return ;
	}
	tmp = data->head_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = data->head_a;
	data->head_a = data->head_a->next;
	data->head_a->prev = NULL;
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
	ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
	if (which == 'r')
		ft_rb_command(data, 'b');
}

void		ft_rb_command(t_data *data, char which)
{
	t_stack *tmp;

	ft_simple_printf("RA COMMAND\n");
	if (data->size[1] < 2)
	{
		if (data->size[1] == 2)
			ft_s_command(data, 'a');
		return ;
	}
	tmp = data->head_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = data->head_b;
	data->head_b = data->head_b->next;
	data->head_b->prev = NULL;
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
	ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
}

void		ft_rrb_command(t_data *data)
{
	t_stack *tmp;

	if (data->size[1] <= 2)
	{
		if (data->size[1] == 2)
			ft_s_command(data, 'a');
		return ;
	}
	tmp = data->head_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = data->head_b;
	tmp->prev = NULL;
	data->head_b->prev = tmp;
	data->head_b = data->head_b->prev;
	ft_print_stack(data, 'b', 0);
}

void		ft_rr_command(t_data *data, char which)
{
	t_stack *tmp;

	if (which == 'a' || which == 'r')
	{
		if (data->size[0] <= 2)
		{
			ft_s_command(data, 'a');
			if (which == 'r')
				ft_rrb_command(data);
			return ;
		}
		tmp = data->head_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->next = data->head_a;
		tmp->prev = NULL;
		data->head_a->prev = tmp;
		data->head_a = data->head_a->prev;
		ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
		if (which == 'r')
			ft_rrb_command(data);
	}
	else
		ft_rrb_command(data);
}
