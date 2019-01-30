/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:48:40 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/30 16:56:10 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_circle_sort(t_data *data, int which)
{
	t_stack *tmp;
	int		sort;
	int		first;

	sort = 0;
	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
		return (0);
	ft_find_pos(data, which, 0);
	while (tmp->next && tmp->value != data->min[which])
		tmp = tmp->next;
	first = tmp->actual_pos;
	while (tmp->next)
	{
		if ((first + sort) != tmp->final_pos)
			return (0);
		sort++;
		tmp = tmp->next;
	}
	tmp = (!which) ? data->head_a : data->head_b;
	while (tmp->next && tmp->value != data->max[which])
	{
		if ((sort + tmp->actual_pos) != tmp->final_pos)
			return (0);
		tmp = tmp->next;
		sort++;
	}
	return (1);
}

void	ft_good_circle(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
		return ;
	while (!ft_circle_sort(data, which))
	{
		if (which)
			ft_ra_command(data, which);
		else
			ft_rb_command(data, which);
	}
}

void	ft_prev_next(t_data *data, int *prev, int *next, int which, int value)
{
	t_stack *tmp;

	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
		return ;
	while (tmp->next && tmp->value != value)
		tmp = tmp->next;
	if (tmp->prev)
		*prev = tmp->prev->value;
	if (tmp->next)
		*next = tmp->next->value;
	else if (!tmp->next)
	{
		tmp = (!which) ? data->head_a : data->head_b;
		*next = tmp->value;
	}
	while (tmp->next && tmp->value != value)
		tmp = tmp->next;
	if (!tmp->prev)
	{
		while (tmp->next)
			tmp = tmp->next;
		*prev = tmp->value;
	}
}

void	ft_mark_four(t_data *data, int which)
{
	ft_simple_printf("MARK FOUR\n");
	t_stack *tmp;
	int		prev;
	int		next;

	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
		return ;
	ft_simple_printf("TAMERE\n");
	while (tmp->next)
	{
		ft_prev_next(data, &prev, &next, which, tmp->value);
		if ((prev < tmp->value && tmp->value < next) ||
		(prev > tmp->value && tmp->value > next))
		{
			ft_simple_printf("mark++ : '%d'\n", tmp->value);
			tmp->mark = 1;
		}
		tmp = tmp->next;
	}
}

/*
**	(changer les listes en doubles circulaires)
**	creer fonction qui prend une liste de 4 valeurs et qui la trie
**	en maximum 1 rotate et 1 swap
**
**
**
**
** 1 2 3 4
**
**	2 *  |  2 *  |  2 *  |  1
**	1    |  3    |  4    |  2 *
**	3 *  |  1    |  1    |  4
**	4    |  4    |  3    |  3 *
**
**	2 *  |  2 *  |  2 *  |  1  	 |
**	1    |  3    |  4    |  2 *  |
**	3 *  |  1    |  1    |  4    |
**	4    |  4    |  3    |  3 *  |
**       | *<->S | *<->S |
**
**
**	3 *  |	1    |  4  	 |  3 *	 |
**	4    |	3 *  |  3 *  |  1    |
**	2 *  |	4    |  1    |  2 *  |
**	1    |	2 *  |  2 *  |  4    |
**
**	2 *  |	4    |  1  	 |  2 *	 |
**	1    |	2 *  |  2 *  |  4    |
**	3 *  |	1    |  4    |  3 *  |
**	4    |	3 *  |  3 *  |  1    |
*/

int		ft_adjacent(t_data *data, int which)		// gerer mark nb nb mark == adjacent
{
	t_stack *tmp;
	int		cpt;
	
	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
		return (0);
	cpt = 0;
	while (tmp->next && !tmp->mark)
		tmp = tmp->next;
	if (tmp->actual_pos != 4 && tmp->next->mark)
		return (1);
	return (0);
}

void	ft_two_marks(t_data *data, int which)
{
	t_stack *tmp;

	ft_simple_printf("TWO MARK\n");
	tmp = (!which) ? data->head_a : data->head_b;
	if (!tmp)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	if (!ft_adjacent(data, which))
	{
		ft_simple_printf("HEEEERE\n");
		if (tmp->mark)
		{
			if ((tmp->final_pos == 3 && tmp->value > tmp->next->value) ||
			(tmp->final_pos == 2 && tmp->value < tmp->next->value))
				ft_rr_command(data, which);
		}
		else
		{
			if ((tmp->next->final_pos == 3 && tmp->value < tmp->next->value) ||
			(tmp->next->final_pos == 2 && tmp->value > tmp->next->value))
				ft_rr_command(data, which);
		}
	}
	ft_s_command(data, which);
	ft_print_stack(data, (which) ? 'b' : 'a', 0);
}

int		ft_four_sort(t_data *data, int which)
{
	t_stack *tmp;
	int		mark;

	tmp = data->head_a;
	if (!tmp)
		return (0);
	if (ft_circle_sort(data, which))
		return (1);
	ft_simple_printf("CHECK CIRCLE SORT\n");
	ft_mark_four(data, which);
	ft_simple_printf("APPEL MARK FOUR\n");
	mark = 0;
	tmp = data->head_a;
	while (tmp->next)
	{
		if (tmp->mark)
			mark++;
		tmp = tmp->next;
	}
	ft_simple_printf("COUNT MARKS : '%d'\n", mark);
	if (mark == 2)
		ft_two_marks(data, which);
	else
		ft_simple_printf("ONLY ONE MARK\n");
	ft_good_circle(data, which);
	return (1);
}
