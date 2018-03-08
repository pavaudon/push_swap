/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:24:53 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 17:24:54 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_current_data(t_both *both)
{
	SIZE_A = ft_inttablen(TAB_A);
	SIZE_B = ft_inttablen(TAB_B);
	MIN_A = ft_get_min_max(TAB_A, "min");
	MIN_B = ft_get_min_max(TAB_B, "min");
	MAX_A = ft_get_min_max(TAB_A, "max");
	MAX_B = ft_get_min_max(TAB_B, "max");
}

int     ft_is_good_int(char *str)
{
  int i;

  i = -1;
  while (str[i++])
  {
    if (!ft_isdigit(str[i]) && str[0] != '-')
      return (-1);
  }
  if (!ft_atoi(str))
    return (-1);
  return (1);
}

int     ft_checkarg(int argc, char **argv)
{
  int i;
  int tmp;
  int j;
  int value;

  j = 0;
  while (++j < argc)
  {
    i = 0;
    while (++i < argc)
    {
      value = ft_atoi(argv[i]);
      tmp = ft_atoi(argv[j]);
      if (tmp == value)
        return (-1);
    }
  }
  return (1);
}
