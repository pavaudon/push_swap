/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/23 20:09:59 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//size de depart == size[A] et possibilite de connaitre size[B]
void		ft_size(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (which == 1) ? data->head_b : data->head_a;
	while (tmp)
	{
		data->size[which] += 1;
		tmp = tmp->next;
	}
	if (which == 2)
		data->size[0] = data->size[2];
}

void		ft_init_stack(t_stack *stack)
{
	stack->prev = NULL;
	stack->next = NULL;
}
//si arg = "0 1 2" et non = 0 1 2
int			ft_spe_fill(t_stack *head_a, char *str, int j)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if (!(ft_addbackstack(head_a, ft_atoi(&str[i]), i + j)))
			return (0);
		if (str[i] == '-')
			i++;
		while (i < len && (ft_isdigit(str[i])))
			i++;
	}
	return (1);
}
//ajout d'un maillon a la fin avec la nouvelle valeur
int			ft_fill(t_stack *head_a, int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' ')) // '/t' enleve
		{
			if (!(ft_spe_fill(head_a, argv[i], i - 1)))
				return (0);
		}
		else
		{
			if (!(ft_addbackstack(head_a, ft_atoi(argv[i]), i - 1)))
				return (0);
		}
	}
	return (1);
}
//malloc, init stack, appel fill et size
int			ft_stack_fill(t_data *data, int argc, char **argv)
{
	if (!(data->head_a = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	ft_init_stack(data->head_a);
	if (!(ft_fill(data->head_a, argc, argv)))
		return (0);
	if (!(data->head_b = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	ft_init_stack(data->head_b);
	ft_size(data, 2);
	return (1);
}
