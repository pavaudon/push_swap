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
	tmp->value = tmp->next->value;
	tmp->next->value = swap;
	ft_print_stack(data, which, (which == 'a' ? 0 : 1));
	if (which == 's')
		ft_s_command(data, 'b');
}

void	ft_p_command(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (which == 'b') ? data->stack_b : data->stack_a;
	if (which == 'b')
		ft_addbeginstack(data->stack_b, data->stack_a->value);
	else
		ft_addbeginstack(data->stack_a, data->stack_b->value);
	ft_print_stack(data, which, (which == 'a' ? 0 : 1));
	free(tmp);
}

void	ft_r_command(t_data *data, int which)
{
	t_stack *tmp;
	t_stack	*begin;

	tmp = (which == 'b') ? data->stack_b : data->stack_a;
	begin = (which == 'b') ? data->stack_b : data->stack_a;
	while (tmp->next)
		tmp = tmp->next;
	begin->next->prev = NULL;
	begin->prev = tmp;
	begin->next = NULL;
	tmp->next = begin;
	ft_print_stack(data, which, (which == 'a' ? 0 : 1));
	if (which == 'r')
		ft_r_command(data, 'b');
}

void	ft_rr_command(t_data *data, int which)
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
	ft_print_stack(data, which, (which == 'a' ? 0 : 1));
	if (which == 'r')
		ft_rr_command(data, 'b');
}
