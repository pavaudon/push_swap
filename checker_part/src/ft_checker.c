/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:54:25 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/19 17:58:03 by pavaudon         ###   ########.fr       */
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

int			ft_checker(t_data *data)
{
	char	command[5];
	int		len;

	ft_bzero(command, 5);
	while (read(0, &command, 4))
	{
		len = 0;
		len = (command[2] == '\n') ? 2 : len;
		len = (command[3] == '\n') ? 3 : len;
		//printf("'%s'\nLEN : '%d'\n", command, len);
		if ((len < 2 || len > 3) || !ft_is_command(command, data, len))	//(data->size[2] > 1 && len == 0)
			ft_error("Error : bad command");
		ft_bzero(command, 5);
	}
	return (data->size[2] == 1 || ((data->size[0] == data->size[2])
	&& (ft_stack_sort(data->head_a) && data->size[1] == 0)));
}

void		ft_before_checker(t_data *data, int argc, char **argv)
{
	if (!ft_check_data(argc, argv) ||
	!ft_stack_fill(data, argc, argv) ||
	!ft_is_again(data))
	{
		ft_cleanup(data);
		ft_error("BAD ARGUMENTS");
	}
}

int			main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (argc > 1)
	{
		ft_before_checker(&data, argc, argv);
		if (ft_checker(&data))
			ft_simple_printf("OK\n");
		else
			ft_simple_printf("KO\n");
		ft_cleanup(&data);
	}
	return (0);
}
