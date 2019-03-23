/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:54:53 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/23 18:25:09 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_stack_sort(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	if (!stack)
		return (0);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		ft_apply_command(t_data *data, int which, char command)
{
	if (command == SA || command == SB)
		ft_s_command(data, 'a' + which);
	else if (command == RB && which)
		ft_rb_command(data);
	else if (command == RA && !which)
		ft_ra_command(data, 'a');
	else if (command == RRA || command == RRB)
		ft_rr_command(data, 'a' + (command == RRB));
	else if (command == PA)
		ft_p_command(data, 'a');
	else if (command == PB)
		ft_p_command(data, 'b');
	else
		return ;
	ft_new_command(data, command);
}

char		*ft_bigger_command(t_data *data, size_t size)
{
	char	*new;

	data->bigger += size;
	if ((new = ft_strnew(data->count + size)))
	{
		ft_strcpy(new, data->command);
		free(data->command);
	}
	return (new);
}

void		ft_new_command(t_data *data, char add)
{
	if ((size_t)data->count == data->bigger - 1)
		data->command = ft_bigger_command(data, 500);
	data->command[data->count] = add;
	data->count++;
}
