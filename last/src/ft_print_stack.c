/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:16:36 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 11:16:38 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_data *data, char which, int both)
{
	t_stack *tmp;

	tmp = (which == 'A') ? data->stack_a : data->stack_b;
	if (!tmp)
		return ;
	ft_simple_printf(">>>>		STACK_%c		<<<<\n", which);
	while (tmp->next)
	{
		ft_simple_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_simple_printf("\n");
	if (both)
		ft_print_stack(data, 'B', 0);
}
