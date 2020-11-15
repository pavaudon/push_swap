/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:56:23 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/23 18:54:32 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stackdel(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*previous;

	tmp = *stack;
	while (tmp)
	{
		previous = tmp;
		tmp = tmp->next;
		free(previous);
	}
	*stack = NULL;
}

void		ft_cleanup(t_data *data)
{
	if (data->head_a)
		ft_stackdel(&(data->head_a));
	if (data->head_b)
		ft_stackdel(&(data->head_b));
}

void		ft_before_ps(t_data *data, int argc, char **argv)
{
	if (!ft_check_data(argc, argv)
		|| !ft_stack_fill(data, argc, argv)
		|| !ft_is_again(data)
		|| !(data->command = (char*)ft_memalloc(sizeof(char ) * 500)))
	{
		ft_cleanup(data);
		ft_error("Error\nBAD ARGUMENTS\n");
	}
	data->count = 0;
	data->bigger = 500;
}

int			ft_push_swap(t_data *data)
{
	if (data->size[0] == 1 || ft_stack_sort(data->head_a))
	{
		ft_error("Nothing to sort\n");
		return (1);
	}
	ft_find_pos(data, 0, 0);
	if (data->size[0] == 2)
		ft_apply_command(data, 0, SA);
	if (data->size[0] == 3)
		ft_sort_three(data);
	else if (data->size[0] == 4 || data->size[0] == 5)
		ft_four_five_sort(data);
	else if (data->size[0] > 5)
		main_big_list(data);
	ft_look_command(data);
	return (1);
}

int			main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (argc > 1)
	{
		ft_before_ps(&data, argc, argv);
		ft_push_swap(&data);
		ft_cleanup(&data);
		free(data.command);
	}
	return (0);
}