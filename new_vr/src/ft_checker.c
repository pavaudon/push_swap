/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:54:25 by pavaudon          #+#    #+#             */
/*   Updated: 2018/12/13 16:54:26 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int   ft_checker(t_data *data)
{
  char  *command;
  int   len;
  int   ret;

  while ((ret = read(command, buffer, 4)) <= 0)
  {
    len = (!command) ? 0 : ft_strlen(command);
    if ((data->size[ALL] > 1 && !command) || (len < 2 || len > 5) ||
    !ft_is_command(command, data, len))
      ft_error("Error : bad command");
  }
  return (data->size[ALL] == 1 || ((data->size[STACK_A] == data->size[ALL])
  && (ft_stack_sort(data)
  && data->size[STACK_B] == 0)));
}

void ft_error(char *error)
{
  ft_simple_printf("%s\n", error);
  exit (1);
}

int   main(int argc, char **argv)
{
  t_data *data;

  data = NULL;
  if (argc > 1)
  {
    if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
  		return (0);
    if (!check_data(argc, argv))
      return (0);
    // > if (!(ft_stack_fill(data, argc, argv)) > if (!is_again) > maj_data
    if (ft_checker(data))
      ft_simple_printf("OK\n");
    else
      ft_simple_printf("KO\n");
  }
  else
    ft_error("./checker [int arguments]");
  return (0);
}
