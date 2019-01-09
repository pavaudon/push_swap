/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_again.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2018/12/13 16:53:01 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_min_max(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (which == 1) ? data->head_b : data->head_a;
	data->min[which] = tmp->value;
	data->max[which] = tmp->value;
	while (tmp->next)
	{
		data->min[which] = (data->min[which] > tmp->value) ? tmp->value :
		data->min[which];
		data->max[which] = (data->max[which] < tmp->value) ? tmp->value :
		data->max[which];
		tmp = tmp->next;
	}
	if (which == 2)
	{
		data->min[0] = data->min[2];
		data->max[0] = data->max[2];
	}
}

int  ft_is_again(t_data *data)
{
  t_stack *tmp;
  t_stack *compare;

  tmp = data->head_a;
  if (!tmp->next)	//a regler
    return (1);
  while (tmp->next)
  {
		compare = tmp->next;
    while (compare)
    {
      if (tmp->value == compare->value)
        return (0);
      compare = compare->next;
    }
    tmp = tmp->next;
  }
  ft_min_max(data, 2);
  return (1);
}

/*
int 	ft_is_again(t_data *data)
{
	t_stack *tmp;
	int 		compare;
	int 		i;
	int 		next;

	i = 0;
	if (data->size[2] == 1)		//verifier
		return (1);
	while (i++ < data->size[2])	// < ou <= ?
	{
		next = 0;
		tmp = data->head_a;
		while (i > 0 && next < i)
			tmp = tmp->next;
		compare = (i > 0) ? tmp->value : tmp->prev->value;
		while (tmp)
		{
			if (compare == tmp->value)
				return (0);
			tmp = tmp->next;
		}
	}
	ft_min_max(data, 2);
	return (1);
}
*/
