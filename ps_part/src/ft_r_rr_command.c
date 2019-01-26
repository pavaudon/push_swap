	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rr_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:20:49 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/15 17:51:02 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
// [first] become [end]
void			ft_ra_command(t_data *data, char which)
{
	if (data->size[0] < 2)
		return ;
	ft_pushback2(&data->head_a, data->head_a->value);
	data->head_a = data->head_a->next;
	free(data->head_a->prev);
	ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
	if (which == 'r')
		ft_rb_command(data, 'b');
}

void			ft_rb_command(t_data *data, char which)
{
	if (data->size[1] < 2)
		return ;
	ft_pushback2(data->head_b, data->head_b->value);
	data->head_b = data->head_b->next;
	free(data->head_b->prev);
	ft_print_stack(data, which, 0);
}
*/

void		ft_ra_command(t_data *data, char which)
{
	t_stack *tmp;

	//ft_simple_printf("RA COMMAND\n");
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
	//ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
	if (which == 'r')
		ft_rb_command(data, 'b');
}
/*
void		ft_rb_command(t_data *data, char which)
{
	t_stack *tmp;

	ft_simple_printf("RB COMMAND\n");
	tmp = data->head_b;
	if (data->size[1] < 2)
		return ;
	while (tmp)
		tmp = tmp->next;
	tmp->next = data->head_b;
	data->head_b = data->head_b->next;
	data->head_b->prev = NULL;
	tmp->next->prev = tmp;
	ft_print_stack(data, which, 0);
}
*/

void		ft_rb_command(t_data *data, char which)
{
	t_stack *tmp;

	(void)which;
	//ft_simple_printf("RA COMMAND\n");
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
	//ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
}

/*
static t_stack	*get_prelast(t_stack *stack)
{
	if ((!stack) || (!stack->next))
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void			ft_del_end_stack(t_stack *stack)
{
	t_stack		*pre_last;

	pre_last = get_prelast(stack);
	if (!pre_last)
		return ;
	if (pre_last->next)
		free(pre_last->next);
	pre_last->next = NULL;
}

// [end] become [first]
void			ft_rr_command(t_data *data, char which)
{
	t_stack *tmp;

	printf("RR COMMAND\n");
	if ((which == 'b' && data->size[1] < 2) ||
	((which == 'a' || which == 'r') && data->size[0] < 2))
		return ;
	tmp = (which == 'b') ? data->head_b : data->head_a;
	while (tmp->next)
		tmp = tmp->next;
	ft_pushfront2((which == 'b') ? &(data->head_b) : &(data->head_a),
		tmp->value);
	if (which == 'b')
		ft_del_end_stack(data->head_b);
	else
		ft_del_end_stack(data->head_a);
	ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
	if (which == 'r')
		ft_rr_command(data, 'b');
}
*/
/*
void		ft_rr_command(t_data *data, char which)
{
	t_stack *tmp;

	ft_simple_printf("RRR COMMAND\n");
	if ((which == 'b' && data->size[1] < 2) ||
	((which == 'a' || which == 'r') && data->size[0] < 2))
		return ;
	tmp = (which == 'b') ? data->head_b : data->head_a;
	while (tmp)
		tmp = tmp->next;
	if (which == 'b')
	{
		data->head_b->prev = tmp;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		data->head_b = data->head_b->prev;
	}
	else
	{
		data->head_a->prev = tmp;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		data->head_a = data->head_a->prev;
	}
	ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
	if (which == 'r')
		ft_rr_command(data, 'b');
}
*/

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
	//ft_print_stack(data, 'b', 0);
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
		//ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
		if (which == 'r')
			ft_rrb_command(data);
	}
	else
		ft_rrb_command(data);
}
