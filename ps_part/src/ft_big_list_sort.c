/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicorn <unicorn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:53:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/20 17:24:31 by unicorn          ###   ########.fr       */
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




/*
**		SI DEBUT (DONC JUSTE MAX ET MIN MARK) :
**			_ si min le plus proche
**				_ si pas between
**					_ go after min
**			_ si max le plus proche
**				_si pas between
**					_ go to max
**			_ push all 3 en decroissant				
**
*/

void	ft_between(t_data *data, int which, int *little, int *big)		//plus proche < ou > mark
{
	t_stack *tmp;
	int		value;

	tmp = data->head_a;
	while (which--)
		value = data->head_b->next->value;
	*little = data->min[0];
	*big = data->max[0];
	while (tmp)
	{
		if (tmp->mark && (tmp->value > value && tmp->value < *big))
			*big = tmp->value;
		if (tmp->mark && (tmp->value < value && tmp->value > *little))
			*little = tmp->value;
		tmp = tmp->next;
	}
}

void	ft_good_place(t_data *data, int *path, int b)
{
	int go;

	if (b == 1)
		ft_apply_command(data, 1, SB);
	if (b == 2)
		ft_apply_command(data, 1, RRB);
	go = (path[0] <= path[1]) ? path[0] : path[1];
	while (go)
	{
		if (path[0] <= path[1])
			ft_apply_command(data, 1, RA);
		else
			ft_apply_command(data, 1, RRA);
		go--;
	}
}

void	ft_choose_b(t_data *data, int **path)
{
	int	b;
	int big;
	int little;

	b = 0;
	if (data->size[1] == 1)
		ft_good_place(data, path[b], b);
	while (b++ < data->size[1] - 1)		//gerer si le path est le meme ->> pb le plus grand
	{
		if (path[b][0] > path[b + 1][0])
			little = b + 1;
		if (path[b][1] < path[b + 1][1])
			big = b + 1;
	}
	if (little < big)
		ft_good_place(data, path[big], big);
	else
		ft_good_place(data, path[little], little);
}

void	ft_search_b(t_data *data)
{
	int		little[data->size[1]];
	int		big[data->size[1]];
	int		which;
	int		path[data->size[1]][2];
	t_stack *tmp;

	which = -1;
	while (++which < data->size[1])
	{
		tmp = data->head_a;
		ft_between(data, which, &(little[which]), &(big[which]));
		while (tmp && tmp->value != little[which] && tmp->value != big[which])
		{
			path[which][0]++;
			tmp = tmp->next;
		}
		while (tmp->value != data->head_a->value &&
		tmp->value != little[which] && tmp->value != big[which])
		{
			path[which][1]++;
			tmp = tmp->prev;
		}
	}
	ft_choose_b(data, path);
}

char	ft_path(t_data *data)
{
	t_stack *tmp_r;
	t_stack *tmp_rr;
	int		r;
	int		rr;

	tmp_r = data->head_a;
	while (tmp_r->value != data->head_a->value && !tmp_r->mark)
	{
		tmp_r = tmp_r->next;
		r++;
	}
	tmp_rr = tmp_r;
	while (tmp_rr->value != data->head_a->value && !tmp_rr->mark)
	{
		tmp_rr = tmp_rr->prev;
		rr++;
	}
	return ((r < rr) ? RA : RRA);
}

void	ft_search_three(t_data *data, int nb_marks)
{
	t_stack *tmp;

	tmp = data->head_a;
	while (tmp->value != data->head_a->value && data->size[1] < 3 && nb_marks)
	{
		if (!(tmp->mark))
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
		data->head_a->mark = 1;
		data->marks += 1;
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

int		main_big_list(t_data *data)
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