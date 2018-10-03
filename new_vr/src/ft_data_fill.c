/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:08:57 by pavaudon          #+#    #+#             */
/*   Updated: 2018/10/03 12:09:02 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   ft_data_fill(t_data *data)
{
  if (!(data->tab[STACK_A] = (int*)ft_memalloc(sizeof(int) * data->nb_value))
  && !(data->tab[STACK_B] = (int*)ft_memalloc(sizeof(int) * data->nb_value)))
    return (0);
  if (!ft_stack_fill(data))
    return (0);
  data->size[STACK_A] = data->nb_value;
  data->size[ALL] = data->size[STACK_A];
  ft_min_max(data, STACK_A);
  data->min[ALL] = data->min[STACK_A];
  data->max[ALL] = data->max[STACK_A];
  return (1);
}

int   ft_stack_fill(t_data *data)
{
  int i;

  i = -1;
  while (++i < data->nb_value)
  {
    if (!(data->tab[STACK_A][i] = data->check[i]))
      return (0);
  }
  return (1);
}

void  ft_min_max(t_data *data, int which)
{
  int i;

  i = 0;
  data->min[which] = *(data->tab[which]) + i;
  data->max[which] = data->min[which];
  while (++i < data->nb_value)
  {
    data->min[which] = (data->min[which] > data->tab[which][i]) ?
    data->tab[which][i] : data->min[which];
    data->max[which] = (data->max[which] < data->tab[which][i]) ?
    data->tab[which][i] : data->max[which];
  }
}
