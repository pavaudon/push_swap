/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:51:02 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/25 13:08:07 by pavaudon         ###   ########.fr       */
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
	while (tmp->value == data->min[which] || tmp->value == data->max[which])
		tmp = tmp->next;
	if (!tmp)
		tmp = (which) ? data->head_b : data->head_a;
	return (tmp->value);
}

char	*ft_to_moit_moit(t_data *data, int which, int med, char *to_do)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = (which) ? data->head_b : data->head_a;
	while (tmp)
	{
		//if (end && tmp->value == med)
		//	return (to_do);
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
	char	*to_do;
	int		i;

	i = 0;
	if (!(to_do = (char*)malloc(sizeof(char) * data->size[0 + which])) ||
	!(to_do = ft_to_moit_moit(data, which, med, to_do)))
		return (0);
	tmp = (which) ? data->head_b : data->head_a;
	if (!to_do)
		return (0);
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
	i = -1;
	while (to_do[++i])
		ft_new_command(data, to_do[i]);
	free(to_do);
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
	ft_max_first(data, which);
	ft_min_end(data, which);
	if (both && !which)
		ft_before_qs(data, 1, 0);
}

int		ft_quick_sort(t_data *data)
{
	ft_before_qs(data, 0, 2);
	while (!ft_stack_sort(data->head_a))
	{
		printf("TAMERE\n");
		ft_before_qs(data, 0, 2);
		while (!ft_stack_sort(data->head_a) || data->size[0] > 3)
		{
			printf("TONPERE\n");
			ft_moit_moit(data, 0, ft_med(data, 0));
		}
		ft_two_three(data, 0);
		while (!ft_stackb_sort(data) || data->size[1] > 3)
		{
			printf("TASOEUR\n");
			ft_moit_moit(data, 1, ft_med(data, 1));
		}
	}
	while (data->head_b)
	{
		ft_p_command(data, 'b');
		ft_new_command(data, PB);
	}
	if (data->size[0] == data->size[2] && ft_stack_sort(data->head_a))
		return (1);
	return (0);
}
