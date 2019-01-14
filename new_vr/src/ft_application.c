/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_application                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2018/12/13 16:53:01 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(char *error)
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

int		ft_addbackstack(t_stack *stack, int value, int i)
{
	t_stack *tmp;
	t_stack	*new;

	if (i)
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
		stack->value = value;
		stack->next = NULL;
		stack->prev = NULL;
	}
	return (1);
}

int		ft_addbeginstack(t_stack **stack, int value, int i)
{
	t_stack *new;

	new = NULL;
	if (i)
	{
		if (!(new = (t_stack*)ft_memalloc(sizeof(t_stack))))
			return (0);
		new->value = value;
		new->prev = NULL;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		if (!*stack && !((*stack) = (t_stack*)ft_memalloc(sizeof(t_stack))))
			return (0);
		(*stack)->value = value;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	return (1);
}

int 	ft_is_command(char *command, t_data *data, int len)		// ca marche mais c'est moche donc a ameliorer?
{
	if (len == 3)
	{
	 	if (command[0] == 'r' && command[1] == 'r' && (command[2] == 'a' || command[2] == 'b' || command[2] == 'r'))
			ft_rr_command(data, command[2]);
		else
			return (0);
	}
	if (len == 2)
	{
		if (command[0] == 's' && (command[1] == 'a' || command[1] == 'b' || command[1] == 's'))
			ft_s_command(data, command[1]);
		else if (command[0] == 'p' && (command[1] == 'a' || command[1] == 'b'))
			ft_p_command(data, command[1]);
		else if (command[0] == 'r' && (command[1] == 'a' ||command[1] == 'r'))
      ft_ra_command(data, command[1]);
    else if (command[0] == 'r' && command[1] == 'b')
			ft_rb_command(data, command[1]);
		else
			return (0);
	}
	return (1);
}
