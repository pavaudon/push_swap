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

typedef struct  s_stack		//trouver un moyen de mettre dans un tout pour stack_a et stack_b
{
  int     *tab;
  int     size;
  int     max;
  int     min;
}               t_stack;

typedef struct	s_both
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		the_max;
	int		the_min;
	int		the_size;
}				t_both;

#endif
