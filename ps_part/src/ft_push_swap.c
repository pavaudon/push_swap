/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:54:15 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/16 14:26:58 by pavaudon         ###   ########.fr       */
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
}

int	ft_push_swap(t_data *data)
{
	data->count = 0;
	if (data->size[0] == 1 || ft_stack_sort(data->head_a))
		ft_error("Nothing to sort\n");		//ft_cleanup first?
	ft_find_pos(data);
	if (data->size[0] == 2)
		ft_s_command(data, 0);
	if (data->size[0] == 3)
		ft_sort_three(data, 0);
	/*
	if (data->size[0] <= 5)
		ft_sort_five(data, 0);
	*/
	if (data->size[0] > 5)
		ft_quicksort(data);
	//a voir si/a partir de combien changer le quicksort
	return (1);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (argc > 1)
	{
		if (!(data = (t_data*)ft_memalloc(sizeof(t_data))) ||
		!ft_before_process(data, argc, argv))
			return (0);
		ft_push_swap(data);
		ft_cleanup(data);
		free(data);
	}
	else
		ft_error("./push_swap [int arguments]");
	return (0);
}
