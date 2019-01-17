/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/17 16:32:24 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *error)
{
	ft_simple_printf("%s\n", error);		//error\n first like subject?
	exit (1);		//pas a la norme?
}

int		ft_stack_sort(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	if (!stack)
		return (0);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		printf("dgweffw\n");
		tmp = tmp->next;
	}
		printf("dgweffdqwfudyqwfdfqwduqw\n");
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

void	ft_new_command(t_data *data, char add)
{
	data->command[data->count++] = add;
	data->command[data->count] = '\0';
}
