/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:54:15 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/23 14:39:26 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_stackdel(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*previous;

	tmp = *stack;
	while (tmp)
	{
		previous = tmp;
		tmp = tmp->next;
		free(previous);
	}
	*stack = NULL;
}

void		ft_cleanup(t_data *data)
{
	if (data->head_a)
		ft_stackdel(&(data->head_a));
	if (data->head_b)
		ft_stackdel(&(data->head_b));
}

//pour la taille du malloc changer suivant le max de commandes
void		ft_before_ps(t_data *data, int argc, char **argv)
{
	if (!ft_check_data(argc, argv) ||
	!ft_stack_fill(data, argc, argv) ||
	!ft_is_again(data) || !(data->command = (char*)malloc(sizeof(11501))))
	{
		ft_cleanup(data);
		free(data);
		ft_error("BAD ARGUMENTS");
	}
	data->count = 0;
}

void	ft_print_command(t_data *data)
{
	int i;

	i = -1;
	while (++i <= data->count)
	{
		if (data->command[i] == SA)
			ft_simple_printf("SA\t");
		if (data->command[i] == SB)
			ft_simple_printf("SB\t");
		if (data->command[i] == SS)
			ft_simple_printf("SS\t");
		if (data->command[i] == PA)
			ft_simple_printf("PA\t");
		if (data->command[i] == PB)
			ft_simple_printf("PB\t");
		if (data->command[i] == RA)
			ft_simple_printf("RA\t");
		if (data->command[i] == RB)
			ft_simple_printf("RB\t");
		if (data->command[i] == RR)
			ft_simple_printf("RR\t");
		if (data->command[i] == RRA)
			ft_simple_printf("RRA\t");
		if (data->command[i] == RRB)
			ft_simple_printf("RRB\t");
		if (data->command[i] == RRR)
			ft_simple_printf("RRR\t");
	}
	ft_simple_printf("\n{%d} commandes utilisees\n", data->count);
}

int		ft_push_swap(t_data *data)
{
	if (data->size[0] == 1 || ft_stack_sort(data->head_a))
		ft_error("Nothing to sort");		//ft_cleanup first?
	ft_find_pos(data, 'a', 1);
	ft_simple_printf("STACK BEFORE START\n");
	//ft_print_stack(data, 'a', 1);
	ft_simple_printf("\n\n");
	if (data->size[0] == 2)
	{
		ft_s_command(data, 0);
		ft_new_command(data, SA);
	}
	if (data->size[0] == 3)
		ft_sort_three(data, 0, 0);
	else if (data->size[0] <= 5)
		printf("A FAIRE ft_sort_five(data, 0)\n");
	if (data->size[0] > 5)
		ft_quick_sort(data);
	//ft_print_stack(data, 'a', 1);
	ft_print_command(data);
	//a voir si/a partir de combien changer le quicksort
	return (1);
}

int		main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (argc > 1)
	{
		if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
			return (0);
		ft_before_ps(data, argc, argv);
		ft_push_swap(data);
		ft_cleanup(data);
		free(data);
	}
	else
		ft_error("./push_swap [int arguments]");
	return (0);
}
