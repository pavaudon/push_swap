/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:21:31 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/07 19:26:38 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_data *data, char which, int both)
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

void		ft_print_command(char command)
{
	if (command == SA)
		ft_simple_printf("SA\n");
	if (command == SB)
		ft_simple_printf("SB\n");
	if (command == SS)
		ft_simple_printf("SS\n");
	if (command == PA)
		ft_simple_printf("PA\n");
	if (command == PB)
		ft_simple_printf("PB\n");
	if (command == RA)
		ft_simple_printf("RA\n");
	if (command == RB)
		ft_simple_printf("RB\n");
	if (command == RR)
		ft_simple_printf("RR\n");
	if (command == RRA)
		ft_simple_printf("RRA\n");
	if (command == RRB)
		ft_simple_printf("RRB\n");
	if (command == RRR)
		ft_simple_printf("RRR\n");
}

void		ft_double_s(t_data *data, int *delete)
{
	int		i;
	int		same;

	i = 0;
	while (i < data->count)
	{
		same = 1;
		if (data->command[i] == SA || data->command[i] == SB)
		{
			while ((i + same) < data->count && data->command[i + same] == data->command[i])
				same++;
			if (same % 2 == 0)
			{
				*delete += same;
				while (same)
				{
					data->command[i] = '.';
					same--;
					i++;
				}
			}
			else
				i++;
		}
		else
			i++;
	}
}

void		ft_double_command(t_data *data)
{
	int		i;
	int		delete;

	i = 0;
	delete = 0;
	ft_double_s(data, &delete);
	while (i < data->count - 1)
	{
		if ((data->command[i] == SA && data->command[i + 1] == SB)
			|| (data->command[i] == SB && data->command[i + 1] == SA))
		{
			data->command[i] = SS;
			data->command[++i] = '.';
			delete++;
		}
		if ((data->command[i] == RA && data->command[i + 1] == RB)
			|| (data->command[i] == RB && data->command[i + 1] == RA))
		{
			data->command[i] = RR;
			data->command[++i] = '.';
			delete++;
		}
		if ((data->command[i] == RRA && data->command[i + 1] == RRB)
			|| (data->command[i] == RRB && data->command[i + 1] == RRA))
		{
			data->command[i] = RRR;
			data->command[++i] = '.';
			delete++;
		}
		i++;
	}
	ft_simple_printf("COUNT : '%d' - DELETE TA MERE : '%d' == '%d'\n", data->count, delete, data->count - delete);
}

void		ft_look_command(t_data *data)
{
	int i;

	i = -1;
	ft_double_command(data);
	while (data->command[++i])
	{
		if (data->command[i] != '.')
			ft_print_command(data->command[i]);
	}
}
