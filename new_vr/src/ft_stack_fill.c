/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:52:59 by pavaudon          #+#    #+#             */
/*   Updated: 2018/12/13 16:53:01 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void  ft_fill_head(s_stack *head_a)
{
  prev = NULL;
  next = NULL;
}

void  ft_stack_fill(t_data data, int argc, char **argv)
{
  if (!(data->head_a =(t_stack*)ft_memalloc(t_stack)))
    return ;
  ft_fill_head(data->head_a);
  //trouver comment remplir sans plus de malloc
}
