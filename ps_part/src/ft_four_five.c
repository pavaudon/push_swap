/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:46:29 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/30 19:48:40 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	ONLY A
**
**	faire un circle_sort a 25 lignes :
**		_ est-ce que c'est trie en boucle?
**		_ (si oui : donne le chemin le plus court jusqu'a min (ra/rra))
**		# return 0 si non, 1 si ra, 2 si rra
**
**	faire un only_swap :
**		_ only SA?
**		# donner un tmp de la liste, swap et si sort_list, faire SA sur la liste
**
**
**	# regarder si sort_four peut etre aussi sort_five?
**
**	#  sort_five :
**	_ check only_swap et circle_sort, si vrai ->> proceder commandes et return
**	_ tant que !stack_sort ou !circle_sort :
**		_ si val == min et val + 1 == max ou si val == 4 et val + 1 == 3 ->> sa
**		_ si val != 1 et val > val + 1 ->>>> ra
**		_ (pour 4 values) si val == 3, val + 1 == 1 et val[fin] == 4 ->>> rra
**				//4 doit etre au dessus de 1 dans une boucle
**		_ si circle_sort ->>> rotate dans le bon sens
**
**
**
*/

int		ft_circle_sort(t_data *data)
{
	t_stack *tmp;
	int		sort;
	int		first;

	sort = 0;
	tmp = data->head_a;
	if (!tmp)
		return (0);
	ft_find_pos(data, 0, 0);
	while (tmp && tmp->value != data->min[which])
		tmp = tmp->next;
	first = tmp->actual_pos;
	while (tmp)
	{
		if ((tmp->actual_pos - first + 1) != tmp->final_pos)
			return (0);
		sort++;
		tmp = tmp->next;
	}
	tmp = data->head_a;
	while (tmp && tmp->value != data->max[which])
	{
		if (sort != tmp->final_pos)
			return (0);
		tmp = tmp->next;
		sort++;
	}
	return (1);	//((first <= (data->size[0] % 2) ? data->size[0] : data->size[0] + 1) 1 : 2)
}