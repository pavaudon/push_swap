/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:54:25 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/14 19:24:56 by pavaudon         ###   ########.fr       */
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
	ft_print_stack(data, 'a', 0);
	while (read(0, &command, 4))
	{
		len = 0;
		len = (command[2] == '\n') ? 2 : len;
		len = (command[3] == '\n') ? 3 : len;
		printf("COMMAND : '%s'\n", command);   //a enlever
		if ((data->size[2] > 1 && len == 0) || (len < 2 || len > 3) ||
		!ft_is_command(command, data, len))
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
		free(data);
		ft_error("BAD ARGUMENTS");
	}
}

int			main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (argc > 1)
	{
		if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
			return (0);
		ft_before_checker(data, argc, argv);
		if (ft_checker(data))
			ft_simple_printf("OK\n");
		else
			ft_simple_printf("KO\n");
		ft_cleanup(data);
		free(data);
	}
	else
		ft_error("./checker [int arguments]");
	return (0);
}
