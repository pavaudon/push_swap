/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:50:26 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 15:50:28 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		ft_addbackstack(t_stack *stack, int value, int i)
{
	t_stack *tmp;
	t_stack	*new;

	if (i != 1)
	{
		if (!(new = (t_stack*)ft_memalloc(sizeof(t_stack))))
			return (0);
		new->value = value;
		new->next = NULL;
		tmp = stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		if (!(new = (t_stack*)ft_memalloc(sizeof(t_stack))))
			return (0);
		new->value = value;
		new->next = NULL;
		new->prev = NULL;
		stack = new;
	}
	return (1);
}

int		ft_addbeginstack(t_stack *stack, int value)
{
	t_stack *new;

	if (!(new = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	new->value = value;
	new->prev = NULL;
	new->next = stack;
	stack->prev = new;
	return (1);
}

int		ft_is_command(char *command, t_data *data, int len)
{
	if (command[0] == 's' && len == 2)
	{
		if (!ft_strcmp("sa", command) || !ft_strcmp("sb", command) ||
		ft_strcmp("ss", command))
			ft_s_command(data, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'p' && len == 2)
	{
		if (!ft_strcmp("pa", command) || !ft_strcmp("pb", command))
			ft_p_command(data, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'r' && len < 4)
		return (ft_is_rcommand(command, data, len));
	else
		return (0);
	return (1);
}

int		ft_is_rcommand(char *command, t_data *data, int len)
{
	if (len == 2 && (!ft_strcmp("ra", command) || !ft_strcmp("rb", command) ||
	!ft_strcmp("rr", command)))
		ft_r_command(data, command[1]);
	else if (len == 3 && (!ft_strcmp("rra", command)
	|| !ft_strcmp("rrb", command) || !ft_strcmp("rrr", command)))
		ft_rr_command(data, command[2]);
	else
		return (0);
	return (1);
}
