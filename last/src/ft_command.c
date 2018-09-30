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
}

void	ft_p_command(t_data *data, char which)
{
	if (which == 'a' && data->size[1])
		ft_pa_command(data);
	else if (which == 'b' && data->size[2])
		ft_pb_command(data);
	ft_print_stack(data, 'a', 1);
}

// [first] become [end]
void 	ft_r_command(t_data *data, char which)
{
	t_stack *tmp;

	tmp = (which == 'b') ? data->stack_b : data->stack_a;
	if (!tmp->next)
		return ;
	ft_addbackstack(tmp, tmp->value,
		(which == 'b') ? data->size[2] : data->size[1]);
	if (which == 'b')
	{
		data->stack_b = tmp;
		data->stack_b->next->prev = NULL;
		data->stack_b = data->stack_b->next;
	}
	else
	{
		data->stack_a = tmp;
		data->stack_a->next->prev = NULL;
		data->stack_a = data->stack_a->next;
	}
	ft_print_stack(data, (which == 'r' ? 'a' : which), (which == 'r' ? 1 : 0));
	if (which == 'r')
		ft_r_command(data, 'b');
}

static t_stack *get_prelast(t_stack *stack)
{
	if ((!stack) || (!stack->next))
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void 	ft_del_end_stack(t_stack *stack)
{
	t_stack		*pre_last;

	ft_simple_printf("PUTE\n");
	pre_last = get_prelast(stack);
	if (!pre_last)
	{
		ft_putstr("caca\n");
		return ;
	}
	ft_simple_printf("caca: %d\n", pre_last->value);
	if (pre_last->next)
		free(pre_last->next);
	pre_last->next = NULL;
}

// [end] become [first]
void 	ft_rr_command(t_data *data, char which)
{
	t_stack *tmp;
	t_stack *begin;

	begin = (which == 'b') ? data->stack_b : data->stack_a;
	tmp = begin;
	if (!begin->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	ft_addbeginstack((which == 'b') ? &(data->stack_b) : &(data->stack_a),
		tmp->value, (which == 'b') ? data->size[2] : data->size[1]);
	if (which == 'b')
		ft_del_end_stack(data->stack_b);
	else
		ft_del_end_stack(data->stack_a);
	ft_print_stack(data, (which == 'r' ? 'a' : which), (which == 'r' ? 1 : 0));
	if (which == 'r')
		ft_rr_command(data, 'b');
}

/*
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
*/
