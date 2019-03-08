/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/08 20:37:12 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_error(char *error)
{
	ft_simple_printf("%s\n", error);
	exit(1);
}

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

int			ft_add_back(t_stack **lst, int val)
{
	t_stack	*new;
	t_stack	*end;

	if (!lst)
		return (0);
	end = *lst;
	while (end && end->next)
		end = end->next;
	if (!(new = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (0);
	new->next = NULL;
	new->value = val;
	new->mark = 0;
	new->prev = end;
	if (end)
		end->next = new;
	else
		*lst = new;
	return (1);
}

void		ft_apply_command(t_data *data, int which, char command)
{
	if (command == SA || command == SB)
		ft_s_command(data, 'a' + which);
	else if (command == RB && which)
		ft_rb_command(data, 'b');
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

void		ft_new_command(t_data *data, char add)
{
	data->count += (data->count) ? 0 : 1;
	data->command[data->count] = add;
	data->count++;
	data->command[data->count] = '\0';
}
