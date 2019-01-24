/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/24 17:20:07 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *error)
{
	ft_simple_printf("%s\n", error);		//error\n first like subject?
	exit (1);		//pas a la norme?
}
//verification de stack A
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
		tmp = tmp->next;
	}
	return (1);
}
//ajout d'un maillon a la fin de la stack
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

int			ft_pushback(t_stack **lst, int val, int i)
{
	t_stack	*new;
	t_stack	*end;

	((void)i);
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

int			ft_pushfront(t_stack **lst, int val, int i)
{
	t_stack	*new;

	((void)i);
	if (!lst)
		return (0);
	if (!(new = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (0);
	new->prev = NULL;
	new->value = val;
	new->next = *lst;
	if (new->next)
		new->next->prev = new;
	*lst = new;
	return (1);
	
}

//ajout d'un maillon au debut de la stack
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
//ajout d'une commande dans char*command a print a la fin et incrementation du nombre de commandes
void	ft_new_command(t_data *data, char add)
{
	data->command[data->count++] = add;
	data->command[data->count] = '\0';
}
