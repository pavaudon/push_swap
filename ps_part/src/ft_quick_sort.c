/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:31:40 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/23 19:56:08 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//moitie plus petite en bas ou moitie plus grande en haut de A
void		ft_pivot_b(t_data *data, int high)
{
	t_stack	*i;

	i = data->head_b;
	while (data->size[1] > 3)
	{
		i = data->head_b;
		if (i->value < high)
		{
			ft_rb_command(data, 'b');
			ft_new_command(data, RB);
		}
		else if (i->value >= high)
		{
			i = i->next;
			ft_pb_command(data);
			ft_new_command(data, PB);
		}
		ft_print_stack(data, 'a', 1);
		i = i->next;
	}
}
//moitie plus grand en bas ou moitie plus petite en haut de B
void		ft_pivot_a(t_data *data, int high)
{
	t_stack	*i;

	i = data->head_a;
	while (data->size[0] > 3)
	{
		i = data->head_a;
		if (i->value > high)
		{
			ft_ra_command(data, 'a');
			ft_new_command(data, RA);
		}
		else if (i->value <= high)
		{
			i = i->next;
			ft_pa_command(data);
			ft_new_command(data, PA);
		}
		ft_print_stack(data, 'a', 1);
		i = i->next;
	}
}

//derniere value de la stack a quicksorter
long		ft_high(t_data *data)
{
	t_stack *tmp;

	if (data->head_a && data->size[0] > 3)
		tmp = data->head_a;
	else if (data->head_b && data->size[1] > 3)
		tmp = data->head_b;
	else
		return (2147483649);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}
//si A[0]/B[0] est plus grand que A[end]/B[end] alors low sera A[1]/B[1]
int		ft_low(t_data *data)
{
	t_stack *tmp;

	if (data->head_a && data->size[0] > 3)
	{
		tmp = data->head_a;
		while (tmp->next)
			tmp = tmp->next;
		if (data->head_a->value > tmp->value)
			return (data->head_a->next->value);
		return (data->head_a->value);
	}
	else if (data->head_b && data->size[1] > 3)
	{
		tmp = data->head_b;
		while (tmp->next)
			tmp = tmp->next;
		if (data->head_b->value > tmp->value)
			return (data->head_b->next->value);
		return (data->head_b->value);
	}
	return (0);
}
//quicksort fini, end_qs met tout B dans A
void	ft_end_qs(t_data *data)
{
	if (data->size[1] <= 3 && !ft_stackb_sort(data))
	{
		ft_two_three(data, 1, 0);
		while (data->size[1] != 0)
		{
			ft_pb_command(data);
			ft_new_command(data, PB);
		}
	}
	if (data->size[0] == data->size[2] && ft_stack_sort(data->head_a))
	{
		ft_print_stack(data, 'a', 1);
		ft_simple_printf("\nDID IT\n");
	}
	else
		ft_simple_printf("GAME OVER\n");
}
//appel de pivot_a ou pivot_b ou two_three a trier si la taille d'une stack est <= 3
void	ft_quick_sort(t_data *data, int low, long high)
{
	ft_print_stack(data, 'a', 1);
	high = ft_high(data);
	if (high == 2147483649)
		return ;
	low = ft_low(data);
	ft_find_pos(data, 'a', 1);
	if (data->size[0] == data->size[2] && ft_stack_sort(data->head_a))
		return ;
	if ((data->size[0] <= 3) || (data->size[1] <= 3))
		ft_two_three(data, 0, 1);
	if (data->size[0] > 3 && !ft_stack_sort(data->head_a))
	{
		ft_pivot_a(data, high);
		ft_quick_sort(data, 0, 0);
	}
	else if (data->size[1] > 3 && !ft_stackb_sort(data))
	{
		ft_pivot_b(data, low);
		ft_quick_sort(data, 0, 0);
	}
	else
		ft_end_qs(data);
}