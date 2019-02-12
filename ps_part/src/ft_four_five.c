/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:46:29 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/12 15:59:30 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	OK
**
**	faire un circle_sort :
**		_ est-ce que c'est trie en boucle?
**		_ (si oui : donne le chemin le plus court jusqu'a min (ra/rra))
**		# return 0 si non, 1 si ra, 2 si rra
*/

/*
**	#  sort_five :
**	_ check only_swap et circle_sort, si vrai ->> proceder commandes et return
**	_ tant que !stack_sort ou !circle_sort :
**		_ si + de 1 changement et val[fin] == max et val == max -1 ->> rra
**		_ si val == min et val + 1 == max ||
**				val == max et val + 1 == max -1 ||
**				val == min +1 et val + 1 == min ||
**			(5 values : val == max et val + 1 == max -2) ->> sa
**		_ si val != min et val > val + 1 || val == max -1 et val + 1 == max ||
**				(5 values : val == max -2 et val + 1 == max)
**				|| val == max et val + 1 != max -1 ->>>> ra
**		_ si val == max -1 (5 values:ou val == max -2) et val[fin] == max -> rra
**				//max doit etre au dessus de min dans une boucle
**		_ si circle_sort ->>> rotate dans le bon sens
**		_ (pour 5 values) :	// autre fonction REFLECHIR QUAND NE PAS FAIRE
**			_ si val == 3 et liste + 1 != triee (et val[fin] != max) -> pa
**				_si !trie : tant que list != 4 5 1 2 ||
**					//_ si val == 4 et val +1 == 2 ||
**						val == min et val[fin] == min +1->> rra
**					_ si val == min +1 et val +1 == min ||
**						val == max et val +1 == max -1 ||
**						val == max et val[fin] == min ->> sa
**					_ si val != max et val > val + 1 ||
**					|| val == min +1 et val[fin] == min ||
**						val == min et val +1 == max ->> ra
**					_ si val == min et val +1 == min +1 ->> ra ra
**				 _ si aucun des autres cas ->> sa rra
**
**				_ si trie : tant que val != max -1 ->> ra
**						_ si val == max et val + 1 == max -1 -> sa
**					_ fin que ->> pb
**				_ tant que val != min rra
*/


/*
**	# AUTRE OPTION :
**	_ check only_swap_first, only_swap_end et circle_sort, si vrai ->>
**				proceder commandes et return
**	_ pa pa
**	_ trier B en decroissant
**			sauf si max en B[1]
**
**	$ _ tant que B != empty
**		_ FT_HELP_SORT A dans le bon sens :
**			si B[0] <= 2
**				_ A[0] == B[0] + 1
**			si B[0] >= 3
**				_ A[0] == B[0] - 1
**		_ si B_size == 1 et B[0] == MAX et circle_sort
**			_ PB, RA [RETURN]
**		_ PB
**		_ si B[0] et B[1] se suivent ->> PB
**
**	_ si stack_sort [RETURN]
**	_ si circle_sort [RETURN]
**	_ sinon FUCK
**
**	_ min en first
*/

/*
**	# HELP_SORT
**	si B[0] <= 2
**		_ FIRST == B[0] + 1
**	si B[0] >= 3
**		_ FIRST == B[0] - 1
**	FT_CIRCLE_POS :
**		FIRST == 1
**		SUITE == circle_pos
*/

void	ft_circle_pos(t_data *data, int first)
{
	t_stack *tmp;
	int		help;
	int		min;

	ft_simple_printf("CIRCLE_POS\n");
	ft_simple_printf("si max et min ils doivent se toucher\n");
	ft_simple_printf("si new_first == 2 et min dans A : min == end\n");
	tmp = data->head_a;
	help = 1;
	while (tmp && tmp->value != first)
		tmp = tmp->next;
	min = (tmp->final_pos == 2 && (data->min[2] == data->min[0])) ? 1 : 0;
	while (tmp)
	{
		//tmp->circle_pos = (tmp->value == data->min[0] && min) ?
		//data->size[0] : help++;
		tmp->circle_pos = help++;
		tmp = tmp->next;
	}
	//if (data->head_a->value == first)
	//	return ;
	tmp = data->head_a;
	while (tmp && tmp->value != first)
	{
		tmp->circle_pos = help++;
		tmp = tmp->next;
	}
	tmp = data->head_a;
	while (tmp)
	{
		ft_simple_printf("circle_pos[%d] : '%d'\n", tmp->value, tmp->circle_pos);
		tmp = tmp->next;
	}
}

int		ft_new_first(t_data *data)
{
	t_stack *tmp;
	int		search;
	int		follow;

	ft_simple_printf("NEW_FIRST\n");
	tmp = data->head_a;
	if (data->head_b->value == data->max[2])
		return (data->min[0]);
	search = (data->head_b->final_pos <= 3) ? 1 : -1;
	follow = (data->size[1] == 2)
	? data->head_b->final_pos - data->head_b->next->final_pos : 0;
	search += (follow != 1 && follow != -1) ? 0 : search;
	while (tmp)
	{
		if (tmp->final_pos - search == data->head_b->final_pos)
			return (tmp->value);
		tmp = tmp->next;
	}
	ft_simple_printf("NEW FIRST : '%d'\n", tmp->value);
	return (tmp->value);
}

int		ft_is_help_sort(t_data *data)
{
	t_stack *tmp;
	int		help;

	tmp = data->head_a;
	help = 0;
	while (tmp)
	{
		if (++help != tmp->circle_pos)
			return (0);
		tmp = tmp->next;
	}
	tmp = data->head_a;
	while (tmp)
	{
		ft_simple_printf("VALUE : '%d'\tFP : '%d'\tCP : '%d'\n", tmp->value, tmp->final_pos, tmp->circle_pos);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_help_sort(t_data *data)
{
	t_stack *tmp;
	int		again;

	again = 0;
	ft_simple_printf("HELP_SORT\n");
	ft_circle_pos(data, ft_new_first(data));
	ft_simple_printf("CIRCLE POS OK\n");
	while (!again)
	{
		tmp = data->head_a;
		ft_circle_pos(data, data->head_a->value);
		ft_simple_printf("circle pos ok\n");
		if (tmp->circle_pos == 3 && tmp->next->circle_pos == 1)
			ft_apply_command(data, 0, RA);
		else if ((tmp->next->circle_pos == 3 && tmp->circle_pos == 1) ||
		(tmp->circle_pos == 3 && tmp->next->circle_pos == 2) ||
		(tmp->circle_pos == 2 && tmp->next->circle_pos == 1))
			ft_apply_command(data, 0, SA);
		else if (tmp->next->circle_pos == 3 && tmp->circle_pos == 2)
			ft_apply_command(data, 0, RRA);
		if (ft_is_help_sort(data))
			again++;
		tmp = data->head_a;
		while (tmp)
		{
			ft_simple_printf("VALUE : '%d'\tcircle_pos : '%d'\n", tmp->value, tmp->circle_pos);
			tmp = tmp->next;
		}
	}
}

int		ft_hentai_sort(t_data *data)
{
	t_stack *tmp;

	ft_apply_command(data, 1, PB);
	ft_simple_printf("FIRST PB\n");
	ft_only_swap(data);
	ft_print_stack(data, 'a', 1);
	if (data->head_a->value == data->max[2] &&
	data->head_a->next->final_pos == data->size[2] - 1)
		ft_apply_command(data, 0, SA);
	ft_circle_sort(data);
	if (!(data->size[1]) && ft_stack_sort(data->head_a))
		return (1);
	ft_simple_printf("NOT SORT OR CIRCLE SORT OR SIZE_B not empty\n");
	ft_apply_command(data, 1, PB);
	ft_simple_printf("SECOND PB\n");
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	else
	{
		tmp = data->head_a;
		while (tmp)
		{
			ft_simple_printf("value : '%d'\tF_P : '%d'\n", tmp->value, tmp->final_pos);
			tmp = tmp->next;
		}
	}
	return (0);
}
/// 2 5 4 3 1 ====== 2 3 5 4 1 || 2 1 5 4 3 == 2 1 5 4 3 PAS TRIE
int		ft_four_five_sort(t_data *data)
{
	t_stack *tmp;

	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	while (data->size[0] != 3)
	{
		if (data->size[2] == 5 && data->head_a->final_pos == 3)
			ft_apply_command(data, 0, RA);
		ft_apply_command(data, 0, PA);
	}
	ft_simple_printf("AFTER PB\n");
	ft_print_stack(data, 'a', 1);
	if (data->size[1] == 2 &&
	(data->head_b->value == data->max[2] ||
	(data->head_b->value < data->head_b->next->value)))
		ft_apply_command(data, 1, SB);
	if (!ft_stack_sort(data->head_a))
	{
		tmp = data->head_b;
		while (tmp)
		{
			ft_simple_printf("VALUE : '%d' FINALPOS2 : '%d'\n", tmp->value, tmp->final_pos);
			tmp = tmp->next;
		}
		if (data->size[1] == 2 && ((data->head_b->final_pos == 5
		&& data->head_b->next->final_pos == 4) ||
		(data->head_b->final_pos == 2 && data->head_b->next->final_pos == 1)))
		{
			ft_simple_printf("GOOOOOOOOOOOOOD\n");
			ft_sort_three(data, 0, 0);
		}
		else if (data->size[1] == 2)
			ft_help_sort(data);
	}
	ft_simple_printf("AFTER FIRST HEL_SORT OR SORT_THREE\n");
	ft_hentai_sort(data);
	ft_simple_printf("AFTER HENTAI_SORT\n");
	ft_print_stack(data, 'a', 1);
	return (1);
}
