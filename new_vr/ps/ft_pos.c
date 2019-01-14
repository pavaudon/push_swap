/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:35:38 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/14 16:35:41 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_final_pos(t_data *data, int value)
{
  t_stack *tmp;
  int      pos;

  pos = data->size[0];
  if (value == data->min[0])
    return (1);
  if (value == data->max[0])
    return (pos);
  tmp = data->head_a;
  while (tmp)
  {
    pos -= (value < tmp->value) ? 1 : 0;
    tmp = tmp->next;
  }
  return (pos);
}

void ft_actual_pos(t_data *data, int which, int both)
{
  t_stack *tmp;
  int     i;

  tmp = (which == 'a') ? data->head_a : data->head_b;
  i = 0;
  while (tmp)
  {
    tmp->actual_pos = ++i;
    tmp = tmp->next;
  }
}

void ft_find_pos(t_data *data)
{
  t_stack *tmp;
  int     i;

  tmp = data->head_a;
  i = 0;
  while (++i <= data->size[0])
  {
    tmp->final_pos = ft_find_pos(data, tmp->value);
    tmp->actual_pos = i;
    tmp = tmp->next;
  }
}
