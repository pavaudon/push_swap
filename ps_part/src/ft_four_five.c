/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:46:29 by pavaudon          #+#    #+#             */
/*   Updated: 2019/02/01 19:52:44 by pavaudon         ###   ########.fr       */
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
**	_ trier B en decroissant sauf si max : max en B[1]
**
**	$ _ tant que B != empty
**		_trier (en boucle) A dans le bon sens :
**			si B[0] <= 2
**				_ A[0] == B[0] + 1
**			si B[0] >= 3
**				_ A[0] == B[0] - 1
**
**		_ si B[0] et B[1] se suivent ->> pb pb
**		_ sinon pb
**
**	_ si stack_sort [RETURN]
**	_ si circle_sort : boucle ra ou boucle rra
**
**	_ min en first
*/

int		ft_hentai_sort(t_data *data)
{
	(void)data;
	ft_simple_printf("HENTAI SORT A FAIRE\n");
	return (0);
}

int		ft_four_five_sort(t_data *data)
{
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	else
		ft_hentai_sort(data);
	return (1);
}