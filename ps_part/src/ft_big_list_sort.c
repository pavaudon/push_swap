/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:53:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/15 16:44:06 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	main_big_list :
**		circle_sort, only_swap
**		mark pour max et min
**		ft_bl_start
**
**	ft_bl_start :
**			circle_sort, only_swap
**			si SIZE_B != 3 ou ft_NOT_MARK (->> return nb not_mark)
**				ft_search_three ->> pa pour les 3 premiers sans mark
**			ft_search_first ->> checker le premier de B a replacer dans A
**			ft_good_place ->> ra/rra tant que != good_place dans A
**		pb
**		again tant que A pas trie ou B pas vide
**
**	ft_search_first :
**		int ra[3]
**		int rra[3]
**		ft_look_b ->> regarde dans B si nb +1 (et +2) y est ->> devient first
**		ft_search_begin	->> return nb ra
**		ft_search_end	->> return nb rra
**		regarder sur les autres values de B si != end_B
**		mettre first en first dans B
**		value->mark++
**		data->marks++;
**		return RA ou RRA
**
**
*/

void	ft_look_b(t_data *data)
{
	t_stack *tmp;
	int		fp;
	int		where;

	tmp = data->head_b;
	where = 1;
	while (tmp->next)
	{
		where++;
		if ((fp - tmp->final_pos) == -1)
			break ;
		tmp = tmp->next;
	}
}

void	ft_search_first(t_data *data)
{
	t_stack	*b;
	t_stack	*tmp;
	int		ra[3];
	int		rra[3];

	tmp = data->head_a;
	b = ft_look_b(data);
}

void	ft_search_three(t_data *data, int how_much, int nb_marks)
{
	t_stack *tmp;

	tmp = data->head_a;
	while (tmp && data->size[1] < 3)
	{
		if (!(tmp->marks))
			ft_apply_command(data, 1, PB);
		else
	}
}

int		ft_bl_start(t_data *data)
{
	while (data->marks < data->size[2])
	{
		if (data->size[1] < 3)
			ft_search_three(data, data->size[1], data->marks < data->size[2]);
		ft_good_place(data, ft_search_first(data));
		ft_apply_command(data, 1, PB);
		if (!(data->size[1]) && (ft_circle_sort(data) || ft_only_swap(data)))
			return (1);
	}
	if (ft_stack_sort(data->head_a))
	{
		ft_simple_printf("CA MARCHE T TRO COOL\n");
		return (1);
	}
	else
	{
		ft_simple_printf("C DE LA MERDE\n");
		return (0);
	}
}

int		main__big_list(t_data *data)
{
	t_stack *tmp;

	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->value == data->min[2] || tmp->value == data->min[2])
			tmp->mark++;
		tmp = tmp->next;
	}
	data->marks = 2;
	return (ft_bl_start(data));
}