/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:33:31 by pavaudon          #+#    #+#             */
/*   Updated: 2018/10/03 12:33:32 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_sort(t_data *data)
{
	int i;

	//write(1, "sort\n", 5);
  i = -1;
	while (++i < data->size[STACK_A] - 1)
	{
		//write(1, "sort boucle\n", 12);
		if (data->tab[STACK_A][i] > data->tab[STACK_A][i + 1])
			return (0);
		//write(1, "sort if ok\n", 11);
	}
	return (1);
}

void 	ft_print_stack(t_data *data, int stack, int both)
{
	int i;

	i = -1;
	ft_simple_printf(">>>>		STACK_%c		<<<<\n", 65 + stack);
	if (!data->size[stack])
	{
		ft_simple_printf("EMPTY\n\n");
		if (both && !stack)
			ft_print_stack(data, 1, 0);
		return ;
	}
	while (++i < data->size[stack])
		ft_simple_printf("%d\n", data->tab[stack][i]);
	ft_simple_printf("\n");
	if (both && !stack)
		ft_print_stack(data, 1, 0);
}

int		ft_is_command(char *command, t_data *data, int len)
{
	write(1, "IS COMMAND\n", 11);
	if (command[0] == 's' && len == 2)
	{
		if (!ft_strcmp("sa", command) || !ft_strcmp("sb", command) ||
		ft_strcmp("ss", command))
			ft_s_command(data, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'p' && len == 2)
	{
		if (!ft_strcmp("pa", command) || !ft_strcmp("pb", command)) {
			ft_p_command(data, command[1]);
		}
		else
			return (0);
	}
	else if (command[0] == 'r' && len < 4)
		return (ft_is_rcommand(command, data, len));
	else
		return (0);
	return (1);
}

int		ft_is_rcommand(char *command, t_data *data, int len)
{
	write(1, "IS RCOMMAND\n", 12);
	if (len == 2 && (!ft_strcmp("ra", command) || !ft_strcmp("rb", command) ||
	!ft_strcmp("rr", command)))
		ft_r_command(data, command[1]);
	else if (len == 3 && (!ft_strcmp("rra", command)
	|| !ft_strcmp("rrb", command) || !ft_strcmp("rrr", command)))
		ft_rr_command(data, command[2]);
	else
		return (0);
	return (1);
}
