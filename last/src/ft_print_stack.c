/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:50:46 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/25 12:50:47 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_data *data, char which, int both)
{
	t_stack *tmp;

	tmp = (which == 'a') ? data->stack_a : data->stack_b;
	if (!tmp)
	{
		ft_simple_printf(">>>>		STACK_%c		<<<<\nEMPTY\n\n", which - 32);
		if (both && which == 'a')
			ft_print_stack(data, 'b', 0);
		return ;
	}
	ft_simple_printf(">>>>		STACK_%c		<<<<\n", which - 32);
	while (tmp)
	{
		ft_simple_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_simple_printf("\n");
	if (both && which == 'a')
		ft_print_stack(data, 'b', 0);
}
