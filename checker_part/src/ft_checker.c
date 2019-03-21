/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:54:25 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/21 19:01:09 by pavaudon         ###   ########.fr       */
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
	int		len;

	command = NULL;
	while (get_next_line(0, &command))
	{
		len = ft_strlen(command);
		if ((len < 2 || len > 3) || !ft_is_command(command, data, len))	//(data->size[2] > 1 && len == 0)
		{
			printf("'%s'\nLEN : '%d'\n", command, len);
			ft_error("Error : bad command");
		}
		free(command);
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

void	ft_print_stack(t_data *data, char which, int both)	//a enlever car useless au rendu
{
	t_stack *tmp;

	tmp = (which == 'a') ? data->head_a : data->head_b;
	if (!tmp)
	{
		ft_simple_printf(">>>>		STACK_%c		<<<<\nEMPTY\n\n",
		which - 32);
		if (both && which == 'a')
			ft_print_stack(data, 'b', 0);
		return ;
	}
	ft_simple_printf(">>>>		STACK_%c		<<<<\n", which - 32);
	ft_simple_printf("SIZE_%c : '%d'\n", which - 32, (which == 'b') ?
	data->size[1] : data->size[0]);
	while (tmp)
	{
		ft_simple_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_simple_printf("\n");
	if (both && which == 'a')
		ft_print_stack(data, 'b', 0);
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
		{
			ft_print_stack(&data, 'a', 1);
			ft_simple_printf("KO\n");
		}
		ft_cleanup(&data);
	}
	return (0);
}
