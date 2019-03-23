/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:54:38 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/23 20:30:16 by pavaudon         ###   ########.fr       */
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
	char	*command;
	char	tamere;

	if (!(command = (char*)ft_memalloc(sizeof(char) * 4)))
		return (0);
	while (read(0, &tamere, 1))
	{
		if (tamere != '\n' && tamere != '\0')
			ft_strncat(command, &tamere, 1);
		if ((tamere == '\n' && (ft_strlen(command) > 3 || ft_strlen(command) < 2))
			|| (tamere == '\n' && !ft_is_command(command, data, ft_strlen(command))))
			ft_error("Error\nBAD COMMAND\n");
		if (tamere == '\n')
			ft_bzero(command, 4);
	}
	free(command);
	return (data->size[2] == 1 || ((data->size[0] == data->size[2])
	&& (ft_stack_sort(data->head_a) && data->size[1] == 0)));
}

/*
int			ft_checker(t_data *data)
{
	char	*command;
	int		len;

	command = NULL;
	while ((get_next_line(0, &command)) > 0)
	{
		len = ft_strlen(command);
		if ((len < 2 || len > 3) || !ft_is_command(command, data, len))
			ft_error("Error\nBAD COMMAND\n");
		free(command);
	}
	return (data->size[2] == 1 || ((data->size[0] == data->size[2])
	&& (ft_stack_sort(data->head_a) && data->size[1] == 0)));
}
*/
void		ft_before_checker(t_data *data, int argc, char **argv)
{
	if (!ft_check_data(argc, argv)
		|| !ft_stack_fill(data, argc, argv) || !ft_is_again(data))
	{
		ft_cleanup(data);
		ft_error("Error\nBAD ARGUMENTS\n");
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
