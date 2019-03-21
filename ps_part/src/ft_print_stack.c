/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:21:31 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/21 19:03:18 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		ft_print_command(char command)
{
	if (command == SA)
		ft_simple_printf("sa\n");
	if (command == SB)
		ft_simple_printf("sb\n");
	if (command == SS)
		ft_simple_printf("ss\n");
	if (command == PA)
		ft_simple_printf("pa\n");
	if (command == PB)
		ft_simple_printf("pb\n");
	if (command == RA)
		ft_simple_printf("ra\n");
	if (command == RB)
		ft_simple_printf("rb\n");
	if (command == RR)
		ft_simple_printf("rr\n");
	if (command == RRA)
		ft_simple_printf("rra\n");
	if (command == RRB)
		ft_simple_printf("rrb\n");
	if (command == RRR)
		ft_simple_printf("rrr\n");
}

void		ft_double_s(t_data *data, int *delete, int i)
{
	int		same;

	while (i < data->count)
	{
		same = 1;
		if (data->command[i] == SA || data->command[i] == SB)
		{
			while ((i + same) < data->count
				&& data->command[i + same] == data->command[i])
				same++;
			if (same % 2 == 0)
			{
				*delete += same;
				while (same--)
				{
					data->command[i] = '.';
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

void		ft_useless_p(t_data *data, int *delete, int i)
{
	int		same;

	while (i < data->count)
	{
		same = 1;
		if (data->command[i] == PB)
		{
			while ((i + same) < data->count
				&& data->command[i + same] == PA)
				same++;
			if (same % 2 == 0)
			{
				*delete += same;
				while (same--)
				{
					data->command[i] = '.';
					i++;
				}
			}
			else
				i++;
		}
		else
			i++;
	}
	//ft_simple_printf("JUST USELESS P : '%d'\n", *delete);
}

void		ft_double_command(t_data *data, int *delete, int i)
{
	while (i < data->count - 1)
	{
		if ((data->command[i] == SA && data->command[i + 1] == SB)
			|| (data->command[i] == SB && data->command[i + 1] == SA))
		{
			data->command[i] = SS;
			data->command[++i] = '.';
			*delete += 1;
		}
		if ((data->command[i] == RA && data->command[i + 1] == RB)
			|| (data->command[i] == RB && data->command[i + 1] == RA))
		{
			data->command[i] = RR;
			data->command[++i] = '.';
			*delete += 1;
		}
		if ((data->command[i] == RRA && data->command[i + 1] == RRB)
			|| (data->command[i] == RRB && data->command[i + 1] == RRA))
		{
			data->command[i] = RRR;
			data->command[++i] = '.';
			*delete += 1;
		}
		i++;
	}
}

void		ft_look_command(t_data *data)
{
	int delete;
	int i;

	delete = 0;
	//ft_simple_printf("tester si ca trie toujours avec les delete sinon fuck a retirer\n");
	i = -1;
	//ft_double_s(data, &delete, 0);
	//ft_useless_p(data, &delete, 0);
	//ft_double_command(data, &delete, 0);
	//ft_simple_printf("COUNT : '%d' - DELETE TA MERE : '%d' == '%d'\n", data->count, delete, data->count - delete);
	while (data->command[++i])
	{
		if (data->command[i] != '.')
			ft_print_command(data->command[i]);
	}
}
