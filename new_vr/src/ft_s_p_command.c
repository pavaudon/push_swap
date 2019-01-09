

#include "push_swap.h"

void	ft_s_command(t_data *data, char which)
{
	printf("S COMMAND\n");
	int		swap;
	t_stack	*tmp;

	swap = (which == 'b') ? data->head_b->value : data->head_a->value;
	tmp = (which == 'b') ? data->head_b : data->head_a;
	if (which == 'b' ? data->size[2] > 1 : data->size[1] > 1)
	{
		tmp->value = tmp->next->value;
		tmp->next->value = swap;
		//ft_print_stack(data, which, (which == 'a' ? 0 : 1));
	}
}

void 	ft_pa_command(t_data *data)
{
	printf("pa COMMAND\n");
	ft_addbeginstack(&(data->head_b), data->head_a->value, data->size[2]);

	if (data->size[1] > 1)
	{
		data->head_a = data->head_a->next;
		data->head_a->prev = NULL;
	}
	else
		data->head_a = NULL;
	data->size[1] -= 1;
	data->size[2] += 1;
}

void 	ft_pb_command(t_data *data)
{
	printf("pb COMMAND\n");
	ft_addbeginstack(&(data->head_a), data->head_b->value, data->size[1]);
	if (data->size[2] > 1)
	{
		data->head_b = data->head_b->next;
		data->head_b->prev = NULL;
	}
	else
		data->head_b = NULL;
	data->size[1] += 1;
	data->size[2] -= 1;
}

void	ft_p_command(t_data *data, char which)
{
	printf("P COMMAND\n");
	if (which == 'a' && data->size[1])
		ft_pa_command(data);
	else if (which == 'b' && data->size[2])
		ft_pb_command(data);
	//ft_print_stack(data, 'a', 1);
}
