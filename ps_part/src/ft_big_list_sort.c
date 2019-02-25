/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_list_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:53:54 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/25 19:51:28 by pavaudon         ###   ########.fr       */
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
/*
void	ft_between(t_data *data, int which, int *little, int *big)		//plus proche < ou > mark
{
	t_stack *tmp;
	int		value;

	tmp = data->head_b;
	ft_simple_printf("LIST B\n");
	while (tmp)
	{
		ft_simple_printf("value : '%d'\n", tmp->value);
		tmp = tmp->next;
	}
	tmp = data->head_b;
	while (tmp && which--)
		tmp = tmp->next;
	value = tmp->value;
	tmp = data->head_a;
	ft_simple_printf("VALUE DANS BETWEEN : '%d'\n", value);
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
	little = b;
	big = b;
	while (++b < data->size[1])
	{
		if (path[little][0] > path[b][0])
			little = b;
		if (path[big][1] < path[b][1])
			big = b;
	}
	if (little < big)
		ft_good_place(data, path[big], big);
	else
		ft_good_place(data, path[little], little);
	free(path);
}

void	ft_search_b(t_data *data)
{
	int		little[data->size[1]];
	int		big[data->size[1]];
	int		which;
	int		**path;
	t_stack *tmp;

	which = -1;
	if (!(path = (int**)ft_memalloc(sizeof(int*) * data->size[1])))
		return ;
	while (++which < data->size[1])
	{
		if (!(path[which] = (int*)ft_memalloc(sizeof(int) * 2)))
		{
			free(path);
			return ;
		}
		tmp = data->head_a;
		ft_between(data, which, &(little[which]), &(big[which]));
		ft_simple_printf("LITTLE : '%d' < VALUE : '%d' < BIG : '%d'\n", little[which], which, big[which]);
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
	while (tmp != NULL)
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

	ft_simple_printf("push opti\n");
	while (data->size[1])
	{
		get_move_count(data);
		ft_simple_printf("after get move count\n");
		tmp = data->head_b;
		move = data->head_b->next;
		ft_simple_printf("aaa\n");
		while (tmp)
		{
			ft_simple_printf("bbb\n");
			if (move->mv_count > tmp->mv_count)
				move = tmp;
			tmp = tmp->next;
		}
		ft_simple_printf("go to the opti value : '%d'\n", tmp->value);
		while (move->mvb > 0 && move->mvb--)
			ft_apply_command(data, 1, RB);
		while (move->mvb < 0 && ++move->mvb)
			ft_apply_command(data, 1, RRB);
		while (move->mva > 0 && move->mva--)
			ft_apply_command(data, 0, RA);
		while (move->mva < 0 && ++move->mva)
			ft_apply_command(data, 0, RRA);
		ft_simple_printf("after move to good place\n");
		move->mark = 1;
		ft_apply_command(data, 1, PB);
		ft_simple_printf("pb\n");
	}
}

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
	while (tmp->next)
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

	while ((data->size[1] < 3) && unmarks)
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
		ft_simple_printf("debut boucle\n");
		ft_print_stack(data, 'a', 1);
		ft_simple_printf("NB_MARKS : '%d'\n", data->marks);
		while (data->size[1] < 3 &&
		((data->marks + data->size[1]) < data->size[2]))
			ft_get_unmark(data, data->size[2] - data->marks);
		ft_simple_printf("after get unmarks : SB '%d'\n", data->size[1]);
		push_opti(data);
		ft_simple_printf("after push opti\n");
		data->marks += 1;
		ft_simple_printf("end boucle\n");
		ft_print_stack(data, 'a', 1);
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
	ft_simple_printf("BIG LIST\n");
	while (tmp)
	{
		if (tmp->value == data->min[2] || tmp->value == data->max[2])
			tmp->mark++;
		tmp = tmp->next;
	}
	ft_simple_printf("MARK MIN MAX OK\n");
	data->marks = 2;
	return (ft_bl_start(data));
}