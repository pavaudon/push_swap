/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_four_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:46:29 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/08 21:21:15 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tameredanstonpere(t_data *data)
{
	int i;
	t_stack *tmp;

	i = 0;
	return ;
	printf("STRUCT : '%p'\n", data);
	ft_print_stack(data, 'a', 1);
	printf("ADD HEAD_A : '%p'\tHEAD_B : '%p'\n", data->head_a, data->head_b);
	tmp = data->head_a;
	printf("MAILLONS A\n");
	while(tmp)
	{
		printf("I : '%d '%p'\n", i++, tmp);
		tmp = tmp->next;
	}
	i = 0;
	tmp = data->head_b;
	printf("MAILLONS B\n");
	while(tmp)
	{
		printf("I : '%d '%p'\n", i++, tmp);
		tmp = tmp->next;
	}
	i = 0;
	printf("MAX A : '%d'\t MAX B : '%d'\tMAX ALL : '%d'\n", data->max[0], data->max[1], data->max[2]);
	printf("MIN A : '%d'\t MIN B : '%d'\t MIN ALL : '%d'\n", data->min[0], data->min[1], data->min[2]);
	printf("SIZE A : '%d'\t SIZE B : '%d'\t SIZE ALL : '%d'\n", data->size[0], data->size[1], data->size[2]);
	printf("MARKS : '%d'\n", data->marks);
	printf("COUNT : '%d'\nCOMMAND : '%p' \n''", data->count, data->command);
	while (data->command[i])
		printf("%c", data->command[i++]);
	printf("''\n\n");
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
	return (1);
}

void	ft_help_sort(t_data *data)
{
	t_stack *tmp;
	int		again;

	again = 0;
	ft_simple_printf("HELP SORT\n");
	tameredanstonpere(data);
	ft_circle_pos(data, ft_new_first(data));
	tameredanstonpere(data);
	ft_simple_printf("PUTE\n");
	while (!again)
	{
		ft_simple_printf("TAMERE\n");
		tmp = data->head_a;
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
	}
	ft_simple_printf("END HELP SORT\n");
}

int		ft_hentai_sort(t_data *data)
{
	ft_simple_printf("HENTAI SORT\n");
	ft_apply_command(data, 1, PB);
	if (!data->size[1] && (ft_circle_sort(data) || ft_only_swap(data)))
		return (1);
	ft_only_swap(data);
	if (data->head_a->value == data->max[2] &&
	data->head_a->next->final_p == data->size[2] - 1)
		ft_apply_command(data, 0, SA);
	if (data->head_a->value != data->max[2] &&
	data->size[1] && data->head_b->final_p != 4)
	{
		ft_only_swap(data);
		ft_circle_sort(data);
	}
	if (data->size[1] && data->max[0] == data->max[2] &&
	data->head_b->final_p == 4)
		ft_apply_command(data, 0, RRA);
	if (data->size[1] && data->head_a->value == data->max[2] &&
	data->head_b->final_p != 4)
		ft_apply_command(data, 0, RA);
	if (!(data->size[1]) && ft_stack_sort(data->head_a))
		return (1);
	ft_apply_command(data, 1, PB);
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	return (0);
}

int		ft_four_five_sort(t_data *data)
{
	if (ft_circle_sort(data) || ft_only_swap(data))
		return (1);
	ft_simple_printf("GO FOUR FIVE\n");
	tameredanstonpere(data);
	while (data->size[0] > 3)
	{
		//tameredanstonpere(data);
		if (data->size[2] == 5 && data->head_a->final_p == 3)
			ft_apply_command(data, 0, RA);
		ft_apply_command(data, 0, PB);
		tameredanstonpere(data);
	}
	ft_simple_printf("PUTE1\n");
	ft_min_max(data, 1);
	ft_simple_printf("PUTE2\n");
	if (data->size[1] == 2
		&& (data->head_b->value == data->max[2] && data->head_b->final_p != 4)
		&& (data->head_b->value < data->head_b->next->value))
		ft_apply_command(data, 1, SB);
	ft_simple_printf("PUTE3\n");
	if ((data->size[1] == 2
		&& ((data->head_b->final_p == 2 && data->head_b->next->final_p != 1)
		|| (data->head_b->final_p == 4 && data->head_b->next->final_p == 5)))
		|| (data->size[1] == 1 && (data->max[1] == data->max[2])))
		ft_sort_three(data, 0);
	else
		ft_help_sort(data);
	ft_simple_printf("PUTE4\n");
	ft_hentai_sort(data);
	ft_simple_printf("PUTE5\n");
	return (1);
}
