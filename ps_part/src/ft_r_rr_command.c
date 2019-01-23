	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_rr_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:20:49 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/15 17:51:02 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// A[first] become A[end]
void			ft_ra_command(t_data *data, char which)
{
	if (data->size[0] < 2)
		return ;
	ft_addbackstack(data->head_a, data->head_a->value, data->size[0]);
	data->head_a = data->head_a->next;
	free(data->head_a->prev);
	//ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
	if (which == 'r')
		ft_rb_command(data, 'b');
}
//B[first] become B[end]
void			ft_rb_command(t_data *data, char which)
{
	if (data->size[1] < 2)
		return ;
	ft_addbackstack(data->head_b, data->head_b->value, data->size[1]);
	data->head_b = data->head_b->next;
	free(data->head_b->prev);
	which = 0; //a enlever
	//ft_print_stack(data, which, 0);
}
// prev->end devient le nouveau [end]
static t_stack	*get_prelast(t_stack *stack)
{
	if ((!stack) || (!stack->next))
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}
//free de [end] devenu [first]
void			ft_del_end_stack(t_stack *stack)
{
	t_stack		*pre_last;

	pre_last = get_prelast(stack);
	if (!pre_last)
		return ;
	if (pre_last->next)
		free(pre_last->next);
	pre_last->next = NULL;
}

// [end] become [first]
void			ft_rr_command(t_data *data, char which)
{
	t_stack *tmp;

	//printf("RR COMMAND\n");
	if ((which == 'b' && data->size[1] < 2) ||
	((which == 'a' || which == 'r') && data->size[0] < 2))
		return ;
	tmp = (which == 'b') ? data->head_b : data->head_a;
	while (tmp->next)
		tmp = tmp->next;
	ft_addbeginstack((which == 'b') ? &(data->head_b) : &(data->head_a),
		tmp->value, (which == 'b') ? data->size[1] : data->size[0]);
	if (which == 'b')
		ft_del_end_stack(data->head_b);
	else
		ft_del_end_stack(data->head_a);
	//ft_print_stack(data, (which == 'r' ? 'a' : which), 0);
	if (which == 'r')
		ft_rr_command(data, 'b');
}
