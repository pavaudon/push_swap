/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:17:19 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 11:17:20 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# include <stdio.h>					//a enlever

typedef struct  s_stack
{
    int		value;
	t_stack	*next;
}               t_stack;

typedef struct  s_data
{
    t_stack 	*stack_a;
	t_stack		*stack_b;
    int     	max[3];
    int			min[3];
    int     	size[3];
//  int*    all_begin_value;  ????
}               t_data;

#endif
