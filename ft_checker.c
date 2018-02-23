# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_checker.c                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <lalicornede42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 12:19:38 by pavaudon          #+#    #+#              #
#    Updated: 2018/02/08 13:29:22 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "push_swap.h"

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

  j = 1;
  while (j++ < argc)
  {
    i = 1;
    while (i++ < argc)
    {
      value = ft_atoi(argv[i]);
      tmp = ft_atoi(argv[j]);
      if (tmp == value)
        return (-1);
    }
  }
  return (1);
}

void      ft_data_stack(int argc, char **argv, t_stack *stack_a)
{
  int   i;
  int   cpt;
  int   min;
  int   max;

  i = 1;
  cpt = 0;
  min = argv[2];
  max = min;
  while (i++ < argc)
  {
    cpt++;
    min = (min > argv[i]) ? ft_atoi(argv[i]) : min;
    max = (max < argv[i]) ? ft_atoi(argv[i]) : max;
  }
  stack_a->size = cpt;
}

int     ft_fill_a(int argc, char **argv, t_stack *stack_a)
{
  int   i;
  int   j;

  i = 1;
  j = -1;
  ft_data_stack(argc, argv, stack_a);
  if (!stack_a->tab = (int*)ft_memalloc(sizeof(int) * stack_a->size))
    return (-1);
  while (i++ < argc)
    stack_a->tab[j++] = ft_atoi(argv[i]);
  return (1);
}

int     ft_checker(int argc, char **argv)
{
  t_stack *stack_a;
  char     *command;

  if (!unicorn = (t_stack*)ft_memalloc(sizeof(t_stack)) || !ft_checkarg(argc, argv) || !stack_a->tab = ft_fill_a(argc, argv, stack_a)
    return (-1);
  while (get_next_line(0, &command))
  {
    if (!ft_is_command(&command))             //check quelle commande et appelle son fonctionnement
    {
        ft_puterror("Error : bad command\n");
        return (-1);
    }
  }
  return (0);
}

int     ft_puterror(char *error)
{
  ft_putstr_fd(error, 2);
  return (-1);
}

int     main(int argc, char **argv)
{
  int i;

  i = ;
  if (argc < 2)
    return(ft_puterror("Error : ./checker int arguments\n"));
  while (i++ < argc)
  {
    if (!ft_is_good_int(argv[i]))
      return (ft_puterror("Error : ./checker int arguments\n"));
  }
  if (ft_checker(argc, argv))
    ft_putstr("OK\n");
  else
    ft_putstr("KO\n");
  return (0);
}
