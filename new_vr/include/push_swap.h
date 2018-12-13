/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:22 by pavaudon          #+#    #+#             */
/*   Updated: 2018/12/13 14:02:25 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "libft.h"

typedef struct  s_stack
{
  int             value;
  int             final_pos;
  //actual_pos?
  struct s_stack  *next;
  struct s_stack  *prev;
}               t_stack;

typedef struct  s_data
{
  t_stack     *head_a;
  t_stack     *head_b;
  int         nb_value;
  int     		max[3];			//0 == a		1 == b    2 == all
  int		   		min[3];
  int     		size[3];
}               t_data;


int     ft_check_data(char **argv, int argc, int i);


#endif
