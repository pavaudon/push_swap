/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:21:31 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/06 20:31:20 by pavaudon         ###   ########.fr       */
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

void		ft_print_command(char command)	// remplacer sa + sb en ss etc
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

char		*ft_double_command(t_data *data)
{
	int i;
	int delete;
	char	*str;

	str = data->command;

	i = 0;
	delete = 0;
	while (data->command[i]) //*str
	{
		if (data->command[i] == SA || data->command[i] == SB)	// si i + 1 existe 
		{
			//i + 1 existe et == l'autre
			//i == ss et i + 1 == .
			//delete++
			//i + 2
		}s
	}
}

void		ft_look_command(t_data)
{
	d
	ft_print_command(data->command[i])
}

"xx S. ra"