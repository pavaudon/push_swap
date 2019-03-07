/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:54:15 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/07 19:30:19 by pavaudon         ###   ########.fr       */
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
		|| !(data->command = (char*)malloc(sizeof(char ) * 11501)))
	{
		ft_cleanup(data);
		ft_error("BAD ARGUMENTS");
	}
	data->count = 0;
}

int			ft_push_swap(t_data *data)
{
	if (data->size[0] == 1 || ft_stack_sort(data->head_a))
	{
		ft_error("Nothing to sort");
		return (1);
	}
	ft_find_pos(data, 0, 0);
	if (data->size[0] == 2)
	{
		ft_s_command(data, 0);
		ft_new_command(data, SA);
	}
	if (data->size[0] == 3)
		ft_sort_three(data, 0);
	else if (data->size[0] == 4 || data->size[0] == 5)
		ft_four_five_sort(data);
	if (data->size[0] > 5)
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
	else
		ft_error("./push_swap [int arguments]");
	return (0);
}
