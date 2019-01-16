/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:51:02 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/16 16:32:54 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_med(t_data *data, int which)
{
	t_stack *tmp;
	int		size;

	tmp = (which) ? data->head_b : data->head_a;
	size = (data->size[which] % 2) ? (data->size[which]) / 2 :
	((data->size[which] + 1) / 2);
	while (--size)
		tmp = tmp->next;
	if (tmp->value == data->min[which] || tmp->value == data->max[which])
		return (tmp->next->value)
	return (tmp->value);
}

char	*ft_to_moit_moit(t_data *data, int which, int med, int end)
{
	t_stack *tmp;
	char	to_do[data->size[0 + which]];
	int		i;

	i = 0;
	ft_bzero(to_do, data->size[0 + which]);
	tmp = (which) ? data->head_b : data->head_a;
	while (tmp)
	{
		if (end && tmp->value == med)
			return (to_do);
		if (tmp->value <= med)
			to_do[i] = PA + which;
		else
			to_do[i] = RA + which;
		i++;
		tmp = tmp->next;
	}
	return (to_do);
}

int		ft_moit_moit(t_data *data, int which, int med)		//which
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
	ft_strcat(data->command, to_do);
	return (1);
}

int		ft_stackb_sort(t_data *data)
{
	t_stack *tmp;

	tmp = data->head_b;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_before_qs(t_data *data, int which, int both)
{
	t_stack *tmp;

	tmp = (which) ? data->head_b : data->head_a;
	if (!tmp || data->size[which] < 4)
	{
		if (both && !which)
			ft_before_qs(data, 1, 0);
		return ;
	}
	if (which && tmp->value == data->max[which])
	{
		ft_rb_command(data, which);
		ft_strcat(data->command, RB);
	}
	else if (!which && tmp->value == data->max[which])
	{
		ft_ra_command(data, which);
		ft_strcat(data->command, RA);
	}
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->value == data->min[2])
	{
		ft_rr_command(data, which);
		ft_strcat(data->command, (which) ? RRB : RRA);
	}
	if (both && !which)
		ft_before_qs(data, 1, 0);
}

int		ft_quick_sort(t_data *data)
{
	int med;

	ft_before_qs(data, 0, 2);
	while (!ft_stack_sort(data->head_a) || data->size[0] > 3)
	{
		med = ft_med(data, 0);
		ft_moit_moit(data, 0, med);
	}
	if (!ft_stack_sort(data->head_a))
		ft_sort_three(data, 0);
	while (!ft_stackb_sort(data) || data->size[1] > 3)
	{
		med = ft_med(data, 1);
		ft_moit_moit(data, 1, med);
	}
	ft_before_qs(data, 0, 2);

	//if B sort B dans A highter to smaller
}
