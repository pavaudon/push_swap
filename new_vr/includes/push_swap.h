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

# define STACK_A 0
# define STACK_B 1
# define ALL 2

typedef struct  	s_data
{
    int         *tab[2];
    int         *check;
    int         nb_value;
    int     		max[3];			//0 == a		1 == b    2 == all
    int		   		min[3];
    int     		size[3];
}               	t_data;



int     ft_check_data(char **argv, int argc, int i);
int     ft_is_again(char **argv, int argc, t_data *data);
int     ft_fill_checker_tab(char **argv, int argc, t_data *data);

int     ft_data_fill(t_data *data);
int     ft_stack_fill(t_data *data);

int		  ft_is_command(char *command, t_data *data, int len);
int		  ft_is_rcommand(char *command, t_data *data, int len);
void	  ft_s_command(t_data *data, char which);
void	  ft_p_command(t_data *data, char which);
void	  ft_r_command(t_data *data, char which);
void	  ft_rr_command(t_data *data, char which);

void  	ft_print_stack(t_data *data, int stack, int both);
int		  ft_stack_sort(t_data *data);

void		ft_size(t_data *data, int which);
void		ft_min_max(t_data *data, int which);

void    ft_error(char *error);


#endif
