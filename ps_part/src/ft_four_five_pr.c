/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five_pr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:42:23 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/08 21:28:02 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_help_c_p(t_data *data, int f_first, int *fp)
{
	t_stack	*tmp;
	int		help;
	int i;

	ft_simple_printf("HELP CP\n");
	tmp = data->head_a;
	help = 0;
	i = 0;
	ft_simple_printf("size : '%d'\n", data->size[0]);
	while (tmp)
	{
		if (tmp->final_p != f_first)
		{
			i++;
			fp[help++] = tmp->final_p;
		}
		tmp = tmp->next;
	}
	ft_simple_printf("IIII : '%d'\n", i);
	ft_simple_printf("END HELP CP\n");
}

void	ft_circle_pos(t_data *data, int f_first)
{
	t_stack *tmp;
	int		help;
	int		fp[2];
	int		subst;

	ft_simple_printf("F_FIRST : '%d'\n", f_first);
	ft_simple_printf("CIRCLE POS\n");
	ft_help_c_p(data, f_first, fp);
	help = 2;
	ft_print_stack(data, 'a', 1);
	subst = (fp[0] > fp[1]) ? 1 : 0;
	ft_simple_printf("CIRCLE POS\n");
	tmp = data->head_a;
	while (tmp)
	{
		if (tmp->final_p != f_first)
		{
			if (subst && ((f_first > fp[0]) || (f_first < fp[1])))
				tmp->circle_pos = (help == 2) ? 3 : 2;
			else if (!subst && ((f_first > fp[1]) || (f_first < fp[0])))
				tmp->circle_pos = (help == 2) ? 2 : 3;
			help--;
		}
		else
			tmp->circle_pos = 1;
		tmp = tmp->next;
	}
	tameredanstonpere(data);
	ft_simple_printf("END CIRCLE POS\n");
}

int		ft_new_first(t_data *data)
{
	t_stack *tmp;
	int		search;
	int		follow;

	tmp = data->head_a;
	tameredanstonpere(data);
	ft_simple_printf("NEW FIRST\n");
	if (data->head_b->final_p == data->max[2] - 1
		&& data->max[0] == data->max[2])
	{
		ft_simple_printf("END NEW FIRST 1 '%d'\n", data->max[0]);
		return (data->max[0]);
	}
	if ((data->head_b->value == data->max[2])
		|| (data->head_b->value == data->min[2] + 1))
	{
		ft_simple_printf("END NEW FIRST 2 '%d'\n", data->min[0]);
		return (data->min[0]);
	}
	search = (data->head_b->final_p <= 3) ? 1 : -1;
	follow = (data->size[1] == 2)
	? data->head_b->final_p - data->head_b->next->final_p : 0;
	ft_simple_printf("follow : '%d'\n", follow);
	search += (follow && (follow != 1 && follow != -1)) ? 0 : search;
	ft_simple_printf("search : '%d'\n", search);
	while (tmp)
	{
		if (tmp->final_p - search == data->head_b->final_p)
		{
			tameredanstonpere(data);
			ft_simple_printf("END NEW FIRST 3 : '%d'\n", tmp->value);
			return (tmp->value);
		}
		tmp = tmp->next;
	}
	ft_simple_printf("END NEW FIRST 4 '%d'\n", tmp->final_p);
	return (tmp->final_p);
}
