/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_again.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:36:17 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/20 18:36:18 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     nb_c_in_string(char *str, char c)
{
  int i;
  int nb;

  i = -1;
  nb = 0;
  if (!str)
    return (0);
  while (str[++i])
    nb += (str[i] == c) ? 1 : 0;
  return (nb);
}

int     nb_value(char **argv, char argc)
{
  int size;
  int i;

  i = 0;
  size = 0;
  while (++i < argc)
  {
    if (ft_strchr(argv[i], ' '))
      size += nb_c_in_string(argv[i], ' ') + 1;
    else
      size++;
  }
  return (size);
}

void tmp_in_tab(char **tab, t_data *data, int *cpt)
{
  int i;

  i = -1;
  while (tab[++i])
  {
    if (!(data->check[*cpt] = ft_atoi(tab[i])))
      return ;
    (*cpt)++;
  }
}

int     ft_is_again(char **argv, int argc, t_data *data)
{
  int i;
  int j;
  int value;

  j = -1;
  if (!(data->nb_value = nb_value(argv, argc)) ||
  !(ft_fill_checker_tab(argv, argc, data)))
    return (0);
  while (++j < data->nb_value - 1)
  {
    value = data->check[j];
    i = j + 1;
    while (++i < data->nb_value)
    {
      if (value == data->check[i])
      {
        free(data->check);
        return (0);
      }
    }
  }
  return (1);
}

int     ft_fill_checker_tab(char **argv, int argc, t_data *data)
{
  int   i;
  int   cpt;
  char  **tmp;

  i = 0;
  cpt = 0;
  if (!(data->check = (int*)ft_memalloc(sizeof(int) * data->nb_value)))
    return (0);
  while (++i < argc)
  {
    if (ft_strchr(argv[i], ' '))
    {
      if (!(tmp = ft_strsplit(argv[i], ' ')))
        return (0);
      tmp_in_tab(tmp, data, &cpt);
      free(tmp);
    }
    else
    {
      if (!(data->check[cpt] = ft_atoi(argv[i])))
        return (0);
      cpt++;
    }
  }
  return (1);
}
