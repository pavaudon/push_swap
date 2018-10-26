/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:39:56 by pavaudon          #+#    #+#             */
/*   Updated: 2018/10/03 12:39:58 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_s_command(t_data *data, char which)    //swap les adresses au lieu de swap les values?
{
  int stack;
  int swap;

  stack = (which == 'b') ? 1 : 0;
  swap = data->tab[stack][0];
  data->tab[stack][0] = data->tab[stack][1];
  data->tab[stack][1] = swap;
  if (which == 'r')
    ft_s_command(data, 'b');
  ft_print_stack(data, stack, (which == 's') ? 1 : 0);
}

void    ft_p_command(t_data *data, char which)
{
  int stack;
  int add;

  stack = (which == 'b') ? 1 : 0;
  add = (stack) ? 0 : 1;
  if (data->size[stack])
  {
    data->tab[add] = (data->size[add]) ?
    ft_tabfsjoin(data->tab[stack], data->tab[add], 1, data->size[add] + 1) :
    ft_tabndup(data->tab[stack], 1, 1);
    if (data->size[stack] > 1)
      data->tab[stack] = ft_tabsub(data->tab[stack], 1, data->size[stack] - 1);
    data->size[stack] -= 1;
    data->size[add] += 1;
  }
  ft_print_stack(data, 0, 1);
}

void    ft_r_command(t_data *data, char which)
{
  int stack;
  int *tmp;
  int value;

  stack = (which == 'b') ? 1 : 0;
  if (data->size[stack] > 1)
  {
    value = data->tab[stack][data->size[stack] - 1];
    tmp = ft_tabsub(data->tab[stack], 0, data->size[stack] - 1);
    data->tab[stack] = ft_tabfsjoin(&value, tmp, 1, data->size[stack] - 1);
  }
  ft_print_stack(data, stack, (which == 'r') ? 1 : 0);
  if (which == 'r')
    ft_r_command(data, 'b');
}

void    ft_rr_command(t_data *data, char which)
{
  int stack;
  int *tmp;
  int value;

  stack = (which == 'b') ? 1 : 0;
  if (data->size[stack] > 1)
  {
    value = *(data->tab[stack]) + 0;
    tmp = ft_tabsub(data->tab[stack], 1, data->size[stack] - 1);
    data->tab[stack] = ft_tabffjoin(tmp, &value, data->size[stack] - 1, 1);
  }
  ft_print_stack(data, stack, (which == 'r') ? 1 : 0);
  if (which == 'r')
    ft_r_command(data, 'b');
}
