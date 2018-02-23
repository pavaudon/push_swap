# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push_swap.h                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavaudon <lalicornede42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 12:19:38 by pavaudon          #+#    #+#              #
#    Updated: 2018/02/08 13:29:22 by pavaudon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct  s_stack
{
  int     *tab;
  int     size;
  int     max;
  int     min;
}               t_stack;

#endif
