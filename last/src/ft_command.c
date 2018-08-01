/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:56:04 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 15:56:05 by pavaudon         ###   ########.fr       */
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
	if (which == 's')
		ft_s_command(data, 'b');
}

void	ft_p_command(t_data *data, int wich)
{
	t_stack *tmp;

	tmp = (wich == 'b') ? data->stack_b : data->stack_a;
	if (which == 'b')
		ft_addbackstack(stack_b, data->stack_a->value);
	else
		ft_addbackstack(stack_a, data->stack_b->value);
	tmp->next->prev = NULL;
	free(tmp);
}

void	ft_r_command(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (wich == 'b') ? data->stack_b : data->stack_a;
	if (which == 'b')
	{
		
	}
	else

	if (which == 'r')
		ft_r_command(data, 'r');
}

void	ft_rr_command(t_data *data, int which)
{
	if (which == 'b')
	{

	}
	else

	if (which == 'r')
		ft_rr_command(data, 'r');
}
