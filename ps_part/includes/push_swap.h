/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:22 by pavaudon          #+#    #+#             */
/*   Updated: 2019/01/23 20:12:04 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "libft.h"

# define SA 'A'
# define SB 'B'
# define SS 'C'
# define PA 'D'
# define PB 'E'
# define RA 'F'
# define RB 'G'
# define RR 'H'
# define RRA 'I'
# define RRB 'J'
# define RRR 'K'

typedef struct		s_stack
{
	int				value;
	int				final_pos;
	int				actual_pos;
	int				move_pos;		//a enlever?
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_data
{
	t_stack			*head_a;
	t_stack			*head_b;
	int				nb_value;
	int				max[3];		//0 == a	1 == b	2 == all
	int				min[3];
	int				size[3];
	char			*command;
	//define des commandes + nombres de commandes en une fonctions pour savoir combien enlever si ca foire?
	int				count; //pour command[count];
}					t_data;

int					ft_check_data(int argc, char **argv);
int					ft_stack_fill(t_data *data, int argc, char **argv);
int					ft_is_again(t_data *data);

int					ft_stack_sort(t_stack *stack);

int					ft_addbackstack(t_stack *stack, int value, int i);
int					ft_addbeginstack(t_stack **stack, int value, int i);

void				ft_error(char *error);

int					ft_is_command(char *command, t_data *data, int len);

void				ft_s_command(t_data *data, char which);
void				ft_p_command(t_data *data, char which);
void				ft_rb_command(t_data *data, char which);
void				ft_ra_command(t_data *data, char which);
void				ft_rr_command(t_data *data, char which);
void				ft_pa_command(t_data *data);
void				ft_pb_command(t_data *data);

void				ft_print_stack(t_data *data, char which, int both);

void				ft_find_pos(t_data *data, int which, int both);
void				ft_min_max(t_data *data, int which);
void				ft_new_command(t_data *data, char add);
void				ft_max_first(t_data *data, int which);
void				ft_min_end(t_data *data, int which);
void				ft_two_three(t_data *data, int which, int both);
int					ft_stackb_sort(t_data *data);

void				ft_quick_sort(t_data *data, int low, long high);
int					ft_sort_three(t_data *data, int which, int both);

#endif
