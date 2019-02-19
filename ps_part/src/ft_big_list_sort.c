/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:53:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/19 18:25:55 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	main_big_list : ||OK||
**		circle_sort, only_swap
**		mark pour max et min
**		ft_bl_start
**
**	ft_bl_start :
**	||OK||   circle_sort, only_swap
**			      si SIZE_B != 3 ou ft_NOT_MARK (->> return nb not_mark)
**				      ft_search_three ->> pa pour les 3 premiers sans mark
**			      ft_search_first ->> checker le premier de B a replacer dans A
**			      ft_good_place ->> ra/rra tant que != good_place dans A
**		      pb
**		      again tant que A pas trie ou B pas vide
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

void	ft_between(t_data *data, int value, int *little, int *big)		//plus proche < ou > mark
{
	*little = data->min[0];
	*big = data->max[0];
	while (tmp)
	{
		if (tmp->mark && (tmp->value > value && tmp->value < big))
			*big = tmp->value;
		if (tmp->mark && (tmp->value < value && tmp->value > little))
			*little = tmp->value;
		tmp = tmp->next;
	}
}

void	ft_good_place(t_data *data, int **path)
{
	//regarder lequel de b et ra ou rra
}

void	ft_search_b(t_data *data)
{
	int		little[3];
	int		big[3];
	int		which;
	int		path[2][3];
	t_stack *tmp;

	which = -1;
	while (++which < data->size[1])
	{
		tmp = data->head_a;
		ft_between(data, value, &(little[which]), &(big[which]));
		while (tmp && tmp->value != little[which] && tmp->value != big[which])
		{
			path[0][which]++;
			tmp = tmp->next;
		}
		while (tmp->value != data->head_a->value &&
		tmp->value != little[which] && tmp->value != big[which])
		{
			path[1][which]++;
			tmp = tmp->prev;
		}
	}
	ft_choose_b(data, path));
}

char	ft_path(t_data *data)
{
	t_stack *tmp_r;
	t_stack *tmp_rr;
	int		r;
	int		rr;

	tmp_r = data->head_a;
	while (tmp->value != data->head_a->value && !tmp->mark)
	{
		tmp = tmp->next;
		r++;
	}
	tmp_rr = data->head_a;
	while (tmp->value != data->head_a->value && !tmp->mark)
	{
		tmp = tmp->prev;
		rr++;
	}
	return ((r < rr) ? RA : RRA);
}

void	ft_search_three(t_data *data, int nb_marks)	//implementer nb_marks?
{
	t_stack *tmp;

	tmp = data->head_a;
	while (tmp->value != data->head_a->value && data->size[1] < 3 && nb_marks)
	{
		if (!(tmp->marks))
		{
			ft_apply_command(data, 1, PB);
			nb_marks--;
		}
		else
			ft_apply_command(data, 1, ft_path(data));
		tmp = tmp->next;
	}
}

int		ft_bl_start(t_data *data)
{
	while (data->marks < data->size[2])
	{
		if (data->size[1] < 3)
			ft_search_three(data, data->marks < data->size[2]);
		ft_search_b(data);
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