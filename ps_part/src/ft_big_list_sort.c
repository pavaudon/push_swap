/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:53:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/27 20:47:45 by pavaudon         ###   ########.fr       */
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

char	ft_path(t_data *data)
{
	t_stack *tmp;
	int		r;
	int		rr;

	r = 0;
	rr = 1;
	tmp = data->head_a;
	while (tmp && tmp->mark)
	{
		tmp = tmp->next;
		r++;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (tmp->prev && tmp->mark)
	{
		tmp = tmp->prev;
		rr++;
	}
	return ((r < rr) ? RA : RRA);
}

void	ft_get_unmark(t_data *data, int unmarks)
{
	t_stack *tmp;

	while ((data->size[1] < 12) && unmarks)			//changement de pa pour test
	{
		tmp = data->head_a;
		if (tmp->mark == 0)
		{
			ft_apply_command(data, 0, PA);
			unmarks--;
		}
		else
			ft_apply_command(data, 0, ft_path(data));
	}
}

int		ft_bl_start(t_data *data)
{
	while (data->marks < data->size[2])
	{
		while (data->size[1] < 12 &&
		((data->marks + data->size[1]) < data->size[2]))			//changement de pa pour test
			ft_get_unmark(data, data->size[2] - data->marks);
		push_opti(data);
		if (!(data->size[1]) && (ft_circle_sort(data) || ft_only_swap(data)))
			return (1);
	}
	return (1);
}

int		main_big_list(t_data *data)
{
	t_stack *tmp;

	ft_simple_printf("SI MIN ET MAX SE TOUCHENT : SA DE MIN ET MAX HERE\n");
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->value == data->min[2] || tmp->value == data->max[2])
			tmp->mark++;
		tmp = tmp->next;
	}
	data->marks = 2;
	ft_find_pos(data, 0, 0);
	ft_good_place(data);
	return (ft_bl_start(data));
}