/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:54:15 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/14 13:54:16 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_push_swap(t_data *data)
{
  ft_find_pos(data);

  //choisir algo pour moins de 10, 2 nombres a trier etc
}

int main(int argc, char **argv)
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
