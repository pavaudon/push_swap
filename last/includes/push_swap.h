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

int		  ft_is_command(char *command, t_data *data, int len);
int	  	ft_stack_sort(t_stack *stack);
int     ft_check_data(char **argv, int argc, int i);
int     ft_is_again(char **argv, int argc, t_data *data);
t_data  *ft_data_fill(t_data *data);
int     ft_fill_checker_tab(char **argv, int argc, t_data *data);
int 		ft_addbeginstack(t_stack *stack, int value, int i);
int	  	ft_addbackstack(t_stack *stack, int value, int i);
void	  ft_s_command(t_data *data, char which);
void	  ft_p_command(t_data *data, char which);
void	  ft_r_command(t_data *data, char which);
void	  ft_rr_command(t_data *data, char which);
int		  ft_is_rcommand(char *command, t_data *data, int len);
void		ft_size(t_data *data, int which);
void		ft_min_max(t_data *data, int which);
t_stack	*ft_stack_fill(t_stack *stack_a, t_data *data);
void	  ft_print_stack(t_data *data, char which, int both);
void    ft_error(char *error);


#endif
