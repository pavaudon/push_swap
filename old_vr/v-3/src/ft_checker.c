/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:31:31 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/20 13:31:32 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   ft_checker(t_data *data)
{
  char  *command;
  int   len;

  while (get_next_line(0, &command))
  {
    len = (!command) ? 0 : ft_strlen(command);
    if ((data->size[0] > 1 && !command) || (len < 2 || len > 5) ||
    !ft_is_command(command, data, len))
      ft_error("Error : bad command");
    if (((data->size[1] == data->size[0]) && (ft_stack_sort(data->stack_a)
    && data->size[2] == 0)) || data->size[0] == 1)
      return (1);
    ft_simple_printf("size_A : '%d'\tsize_B : '%d'\tsize_all : '%d'\n",
    data->size[1], data->size[2], data->size[0]);
  }
  return (0);
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
  if (argc >= 2)
  {
    if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
  		return (0);
    if (((argc == 2) ? !ft_check_data(argv, 2, 0) :
    !ft_check_data(argv, argc, 0))
    || !ft_is_again(argv, argc, data))
      ft_error("./checker [int arguments]");
    if (!(ft_data_fill(data)))
      ft_error("data_fill failed");
    ft_print_stack(data, 'a', 1);
    ft_simple_printf("CHECKER START\n\n");
    if (ft_checker(data))
      ft_simple_printf("OK\n");
    else
      ft_simple_printf("KO\n");
  }
  else
    ft_error("./checker [int arguments]");
  return (0);
}
