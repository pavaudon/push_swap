/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/27 15:29:27 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *error)
{
	ft_simple_printf("%s\n", error);
	exit (1);
}

int		ft_stack_sort(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
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
	new->prev = end;
	if (end)
		end->next = new;
	else
		*lst = new;
	return (1);
}

int		ft_is_command(char *command, t_data *data, int len)
{
	if (len == 3)
	{
		if (command[0] == 'r' && command[1] == 'r' && (command[2] == 'a'
		|| command[2] == 'b' || command[2] == 'r'))
			ft_rr_command(data, command[2]);
		else
			return (0);
	}
	if (len == 2)
	{
		if (command[0] == 's' && (command[1] == 'a' || command[1] == 'b'
		|| command[1] == 's'))
			ft_s_command(data, command[1]);
		else if (command[0] == 'p' && (command[1] == 'a' || command[1] == 'b'))
			ft_p_command(data, command[1]);
		else if (command[0] == 'r' && (command[1] == 'a' || command[1] == 'r'))
			ft_ra_command(data, command[1]);
		else if (command[0] == 'r' && command[1] == 'b')
			ft_rb_command(data, command[1]);
		else
			return (0);
	}
	return (1);
}
