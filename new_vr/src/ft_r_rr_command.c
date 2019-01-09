


#include "push_swap.h"

// [first] become [end]
void 	ft_r_command(t_data *data, char which)
{
	t_stack *tmp;

	printf("R COMMAND\n");
	tmp = (which == 'b') ? data->head_b : data->head_a;
	if (!tmp->next)
		return ;
	ft_addbackstack(tmp, tmp->value,
		(which == 'b') ? data->size[2] : data->size[1]);
	if (which == 'b')
	{
		data->head_b = tmp;
		data->head_b->next->prev = NULL;
		data->head_b = data->head_b->next;
	}
	else
	{
		data->head_a = tmp;
		data->head_a->next->prev = NULL;
		data->head_a = data->head_a->next;
	}
	//ft_print_stack(data, (which == 'r' ? 'a' : which), (which == 'r' ? 1 : 0));
	if (which == 'r')
		ft_r_command(data, 'b');
}

static t_stack *get_prelast(t_stack *stack)
{
	if ((!stack) || (!stack->next))
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void 	ft_del_end_stack(t_stack *stack)
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
void 	ft_rr_command(t_data *data, char which)
{
	t_stack *tmp;
	t_stack *begin;

	printf("RR COMMAND\n");
	begin = (which == 'b') ? data->head_b : data->head_a;
	tmp = begin;
	if (!begin->next)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	ft_addbeginstack((which == 'b') ? &(data->head_b) : &(data->head_a),
		tmp->value, (which == 'b') ? data->size[2] : data->size[1]);
	if (which == 'b')
		ft_del_end_stack(data->head_b);
	else
		ft_del_end_stack(data->head_a);
	//ft_print_stack(data, (which == 'r' ? 'a' : which), (which == 'r' ? 1 : 0));
	if (which == 'r')
		ft_rr_command(data, 'b');
}
