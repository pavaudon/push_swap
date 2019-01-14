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

void		ft_size(t_data *data, int which)
{
	t_stack *tmp;

	tmp = (which == 1) ? data->head_b : data->head_a;
	while (tmp)
	{
		data->size[which] += 1;
		tmp = tmp->next;
	}
	if (which == 2)
		data->size[0] = data->size[2];
}

void  ft_init_stack(t_stack *stack)
{
  stack->prev = NULL;
  stack->next = NULL;
}

int  ft_spe_fill(t_stack *head_a, char *str, int j)
{
  int i;

  i = -1;
  while (str[++i])
  {
    if (!(ft_addbackstack(head_a, ft_atoi(&str[i]), i + j)))
      return (0);
    if (str[i] == '-')
  		i++;
  	while (str[i] && (ft_isdigit(str[i])))
  		i++;
  }
  return (1);
}


int  ft_fill(t_stack *head_a, int argc, char **argv)
{
	int i;

	i = 0;
	printf("STACK FILL\n");
  while (++i < argc)
  {
    if (ft_strchr(argv[i], ' ')) // '/t' enleve
    {
      if (!(ft_spe_fill(head_a, argv[i], i - 1)))
        return (0);
    }
    else
		{
      if (!(ft_addbackstack(head_a, ft_atoi(argv[i]), i - 1)))
        return (0);
			printf("i : '%d'\n", i);
			printf("head_a->value : '%d'\n", head_a->value);
    }
  }
  return (1);
}

/*
int  ft_stack_fill(t_data *data, int argc, char **argv)
{
	printf("FUCK1\n");
	data->head_a = NULL;
	printf("FUCK2\n");
	if (!(ft_fill(data->head_a, argc, argv)))
    return (0);
	printf("FUCK3\n");
	data->head_b = NULL;
	ft_size(data, 2);
	printf("FUCK4\n");
	return (1);
}
*/
int  ft_stack_fill(t_data *data, int argc, char **argv)
{
  if (!(data->head_a =(t_stack*)ft_memalloc(sizeof(t_stack))))	//enlever ce malloc?
    return (0);
  ft_init_stack(data->head_a);
	if (!(ft_fill(data->head_a, argc, argv)))
    return (0);
  if (!(data->head_b =(t_stack*)ft_memalloc(sizeof(t_stack))))	//enlever celui la aussi?
    return (0);
  ft_init_stack(data->head_b);
  ft_size(data, 2);
  return (1);
}
