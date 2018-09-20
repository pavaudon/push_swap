/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:13:20 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/20 13:13:21 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "libft.h"

typedef struct		s_stack
{
    int			      	value;
    struct s_stack	*next;
    struct s_stack	*prev;
}               	t_stack;

typedef struct  	s_data
{
    t_stack 		*stack_a;
    t_stack			*stack_b;
    int         *check;
    int         nb_value;
    int     		max[3];			//0 == all		1 == a		2 == b
    int		   		min[3];
    int     		size[3];
}               	t_data;

#endif
