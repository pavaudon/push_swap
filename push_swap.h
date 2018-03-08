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

# define TAB_A "both->stack_a->tab"
# define TAB_B "both->stack_b->tab"
# define SIZE_A "both->stack_a->size"
# define SIZE_B "both->stack_b->size"
# define MIN_A "both->stack_a->min"
# define MIN_B "both->stack_b->min"
# define MAX_A "both->stack_a->max"
# define MAX_B "both->stack_b->max"

typedef struct  s_stack
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

int				ft_puterror(char *error);
int     		ft_checker(int argc, char **argv);
int     		ft_fill_a(int argc, char **argv, t_both *both);
void			ft_data_stack(int argc, char **argv, t_both *both);
int     		ft_checkarg(int argc, char **argv);
int     		ft_is_good_int(char *str);
void			ft_current_data(t_both *both);
void			ft_rrcommand(t_both *both, char c);
void			ft_rcommand(t_both *both, char c);
void			ft_pcommand(t_both *both, char c);
void			ft_scommand(t_both *both, char c);
int				ft_is_command(char command, t_both *both);

#endif
