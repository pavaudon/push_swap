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
  char  command[5];
  int   len;

  ft_bzero(command, 5);
  ft_print_stack(data, 'a', 0);
  while (read(0, &command, 4))
  {
    len = 0;
    len = (command[2] == '\n') ? 2 : len;
    len = (command[3] == '\n') ? 3 : len;
    printf("LEN : '%d'\tCOMMAND : '%s'\n", len, command);
    if ((data->size[2] > 1 && len == 0) || (len < 2 || len > 3) ||
    !ft_is_command(command, data, len))
      ft_error("Error : bad command");
    ft_bzero(command, 5);
  }
  return (data->size[2] == 1 || ((data->size[0] == data->size[2])
  && (ft_stack_sort(data->head_a)
  && data->size[1] == 0)));
}

void ft_error(char *error)
{
  ft_simple_printf("%s\n", error);
  exit (1);
}

int   ft_before_checker(t_data *data, int argc, char **argv)
{
  if (!ft_check_data(argc, argv) ||
  !ft_stack_fill(data, argc, argv) ||
  !ft_is_again(data))
    return (0);
  return (1);
}

int   main(int argc, char **argv)
{
  t_data *data;

  data = NULL;
  if (argc > 1)
  {
    if (!(data = (t_data*)ft_memalloc(sizeof(t_data))) ||
    !ft_before_checker(data, argc, argv))
  		return (0);
    if (ft_checker(data))
      ft_simple_printf("OK\n");
    else
      ft_simple_printf("KO\n");
  }
  else
    ft_error("./checker [int arguments]");
  return (0);
}
