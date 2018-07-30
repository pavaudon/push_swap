/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:23:42 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 17:23:47 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# include <stdio.h>					//a enlever

typedef struct  s_stack
{
    int ab;
    int value;
}               t_stack;

typedef struct  s_data
{
    t_stack *stack;
    int     max;
    int     min[3];
    int     size[3];
//  int*    all_begin_value;  ????
}               t_data;

#endif
