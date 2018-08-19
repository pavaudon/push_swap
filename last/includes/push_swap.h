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

# include <stdio.h>

# include "libft.h"

typedef struct		s_stack
{
    int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}               	t_stack;

typedef struct  	s_data
{
    t_stack 		*stack_a;
	t_stack			*stack_b;
    int     		max[3];			//0 == all		1 == a		2 == b
    int				min[3];
    int     		size[3];
}               	t_data;

int			ft_check_data(char **argv, int cpt, int size);
int 	    ft_is_again(char **argv, int argc, int value);
void		ft_s_command(t_data *data, char which);
void		ft_p_command(t_data *data, int wich);
void		ft_r_command(t_data *data, int which);
void		ft_rr_command(t_data *data, int which);
int			ft_stack_sort(t_stack *stack);
int			ft_addbackstack(t_stack *stack, int value, int i);
int			ft_addbeginstack(t_stack *stack, int value);
int			ft_is_command(char *command, t_data *data, int len);
t_data		*ft_data_fill(char **argv, int argc, t_data *data);
t_stack		*ft_stack_fill(char **argv, int argc, t_stack *stack_a);
void		ft_size(t_data *data, int truc);
void		ft_min_max(t_data *data, int truc);
int			ft_is_rcommand(char *command, t_data *data, int len);

#endif
