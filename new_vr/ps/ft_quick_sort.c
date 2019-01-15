/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:51:02 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/15 17:49:48 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_med(t_data *data, int which)
{
	if (data->size[which] % 2)
		return (data->size[which] / 2);
	return ((data->size[which] + 1) / 2);
}

char	*ft_to_moit_moit(t_data *data, int which, int med)
{
	t_stack *tmp;
	char	to_do[data->size[0 + which]];
	int		i;

	i = 0;
	ft_bzero(to_do, data->size[0 + which]);
	tmp = (which) ? data->head_b : data->head_a;
	while (tmp)
	{
		if (tmp->value <= med)
			to_do[i] = PA + which;
		else
			to_do[i] = RA + which;
		i++;
		tmp = tmp->next;
	}
	return (to_do);
}

int		ft_moit_moit(t_data *data, int which, int med)
{
	t_stack	*tmp;
	char	to_do[data->size[0 + which]];
	int		i;

	i = 0;
	if (!(to_do = ft_to_moit_moit(data, which, med)))
		return (0);
	tmp = (which) ? data->head_b : data->head_a;
	while (to_do[i])
	{
		if (to_do[i] == PA || to_do[i] == PB)
			ft_p_command(data, 'a' + which);
		else if (to_do[i] == RA)
			ft_ra_command(data, 'a');
		else if (to_do[i] == RB)
			ft_rb_command(data, 'b');
		else
			return (0);
		i++;
	}
	return (1);
}

int		ft_quick_sort(t_data *data)
{
	int med;

	while (data->size[0] > 3)
	{
		med = ft_med(data, 0);
		ft_moit_moit(data, med);
	}

	//trier 3 a
	//refaire le while pour B dans A
	//if B sort B dans A highter to smaller

}
