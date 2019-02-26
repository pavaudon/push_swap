/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:53:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/26 21:35:45 by pavaudon         ###   ########.fr       */
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

int		move_top(t_stack *to_move, t_stack *head)
{
	int		move;
	int		size;
	t_stack	*tmp;

	move = 0;
	size = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp == to_move)
			move = size;
		size++;
		tmp = tmp->next;
	}
	if (move >= size / 2)
		move = -(size - move);
	return (move);
}

int		ft_abs(int nb)
{
	return ((nb < 0) ? -nb : nb);
}

t_stack	*go_min_max(t_data *data, int min_max)
{
	t_stack *tmp;

	tmp = data->head_a;
	while (tmp)
	{
		if (min_max && tmp->value == data->max[0])
			return (tmp);
		if (!min_max && tmp->value == data->min[0])
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int		move_to_limit(t_data *data, int nb)
{
	t_stack		*limit_low;
	t_stack		*limit_up;
	t_stack		*tmp;
	int			low;
	int			up;

	limit_up = go_min_max(data, 1);
	limit_low = go_min_max(data, 0);
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->mark)
		{
			if (tmp->value > nb && tmp->value < limit_up->value)
				limit_up = tmp;
			if (tmp->value < nb && tmp->value > limit_low->value)
				limit_low = tmp;
		}
		tmp = tmp->next;
	}
	low = move_top(limit_low, data->head_a) + 1;
	up = move_top(limit_up, data->head_a);
	return (ft_abs(up) < ft_abs(low) ? up : low);
}

void	get_move_count(t_data *data)
{
	t_stack *tmp;

	tmp = data->head_b;
	while (tmp)
	{
		tmp->mvb = move_top(tmp, data->head_b);
		tmp->mva = move_to_limit(data, tmp->value);
		tmp->mv_count = ft_abs(tmp->mvb) + ft_abs(tmp->mva);
		tmp = tmp->next;
	}
}

void	push_opti(t_data *data)
{
	t_stack	*move;
	t_stack	*tmp;

	while ((move = data->head_b) != NULL)
	{
		get_move_count(data);
		tmp = (data->size[1] > 1) ? data->head_b->next : NULL;
		while (tmp)
		{
			if (move->mv_count > tmp->mv_count)
				move = tmp;
			tmp = tmp->next;
		}
		while (move->mvb > 0 && move->mvb--)
			ft_apply_command(data, 1, RB);
		while (move->mvb < 0 && move->mvb++)
			ft_apply_command(data, 1, RRB);
		while (move->mva > 0 && move->mva--)
			ft_apply_command(data, 0, RA);
		while (move->mva < 0 && move->mva++)
			ft_apply_command(data, 0, RRA);
		move->mark = 1;
		data->marks += 1;
		ft_apply_command(data, 1, PB);
	}
}

char	ft_path(t_data *data)
{
	t_stack *tmp;
	int		r;
	int		rr;

	ft_simple_printf("PATH\n");
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

	ft_simple_printf("GETUNMARK : '%d'\n", unmarks);
	while ((data->size[1] < 3) && unmarks)
	{
		ft_simple_printf("AAA\n");
		tmp = data->head_a;
		ft_simple_printf("BBB\n");
		if (tmp->mark == 0)
		{
			ft_simple_printf("CCCC\n");
			ft_apply_command(data, 0, PA);
			ft_simple_printf("DDD\n");
			unmarks--;
			ft_simple_printf("EEEE\n");
		}
		else
		{
			ft_simple_printf("FFFF '%d'\n", unmarks);
			ft_print_stack(data, 'a', 0);
			ft_apply_command(data, 0, ft_path(data));
			ft_simple_printf("GGGG\n");
		}
	}
	ft_simple_printf("end\n");
}

int		ft_bl_start(t_data *data)
{
	ft_simple_printf("a MARKS : '%d'\n", data->marks);
	ft_print_stack(data, 'a', 0);
	while (data->marks < data->size[2])
	{
		ft_simple_printf("b marks : (marks '%d' SB : '%d') - S2 '%d'\n", data->marks, data->size[1], data->size[2]);
		while (data->size[1] < 3 &&
		((data->marks + data->size[1]) < data->size[2]))
			ft_get_unmark(data, data->size[2] - data->marks);
		ft_simple_printf("c\n");
		push_opti(data);
		//data->marks += 1;
		ft_simple_printf("d\n");
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

//ft_count_g_p a commencer par chaque elem apres min qui compte combien plus grand jusqu'a max
void	ft_count_g_p(t_data *data, t_stack *check)
{
	t_stack *tmp;
	int		value;
	int		count;

	tmp = check;
	value = tmp->value;
	count = 0;
	while (tmp)
	{
		while (tmp && (tmp->value != data->max[0]))
		{
			if (tmp->value > value && ++count)
				value = tmp->value;
			tmp = tmp->next;
		}
		if (tmp && tmp->value == data->max[0])
		{
			check->cgp = count + 1;
			data->count_g_p = (count > data->count_g_p)
			? count + 1 : data->count_g_p;
			return ;
		}
		tmp = data->head_a;
	}
}

void	ft_mark_g_p(t_data *data)
{
	t_stack *tmp;
	int		value;

	tmp = data->head_a;
	data->marks += data->count_g_p;
	while (tmp && tmp->cgp != data->count_g_p)
		tmp = tmp->next;
	if (!tmp)
		return ;
	tmp->mark = 1;
	value = tmp->value;
	while (tmp)
	{
		while (tmp && tmp->value != data->max[0])
		{
			if (tmp->value > value && ((value = tmp->value) || 1))
				tmp->mark = 1;
			tmp = tmp->next;
		}
		if (tmp && tmp->value == data->max[0])
			return ;
		tmp = data->head_a;
	}
}

void	ft_good_place(t_data *data)
{
	t_stack *tmp;

	data->count_g_p = 0;
	tmp = data->head_a;
	while (tmp && (tmp->value != data->min[0]))
		tmp = tmp->next;
	if (tmp && tmp->final_pos != data->size[0])
		tmp = tmp->next;
	else
		tmp = data->head_a;
	while (tmp)
	{
		while (tmp && tmp->value != data->max[0])
		{
			ft_count_g_p(data, tmp);
			tmp = tmp->next;
		}
		if (tmp && tmp->value == data->max[0])
			tmp = NULL;
		else
			tmp = data->head_a;
	}
	if (data->count_g_p != 0)
		ft_mark_g_p(data);
}

int		main_big_list(t_data *data)
{
	t_stack *tmp;

	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	tmp = data->head_a;
	ft_simple_printf("BIG LIST\n");
	while (tmp)
	{
		if (tmp->value == data->min[2] || tmp->value == data->max[2])
			tmp->mark++;
		tmp = tmp->next;
	}
	ft_simple_printf("MARK MIN MAX OK\n");
	data->marks = 2;
	ft_find_pos(data, 0, 0);
	ft_good_place(data);
	return (ft_bl_start(data));
}