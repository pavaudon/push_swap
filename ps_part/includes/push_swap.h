/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <pavaudon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:22 by pavaudon          #+#    #+#             */
/*   Updated: 2019/03/19 19:23:57 by pavaudon         ###   ########.fr       */
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

# define MAX_VAL 2
# define MIN_VAL 1
# define LAST_VAL 0

typedef struct		s_stack
{
	int				value;
	int				final_p;
	int				actual_pos;
	int				circle_pos;
	int				mark;
	int				mvb;
	int				mva;
	int				mv_count;
	int				cgp;
	int				wgt;
	struct s_stack	*nxtw;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_data
{
	t_stack			*head_a;
	t_stack			*head_b;
	int				max[3];
	int				min[3];
	int				size[3];
	int				marks;
	char			*command;
	int				count;
	size_t			bigger;
}					t_data;

int					ft_check_data(int argc, char **argv);
int					ft_stack_fill(t_data *data, int argc, char **argv);
int					ft_is_again(t_data *data);
int					ft_add_back(t_stack **lst, int val);

int					ft_stack_sort(t_stack *stack);

void				ft_error(char *error);

void				ft_apply_command(t_data *data, int which, char command);
void				ft_new_command(t_data *data, char add);
int					ft_is_command(char *command, t_data *data, int len);
void				ft_look_command(t_data *data);

void				ft_s_command(t_data *data, char which);
void				ft_p_command(t_data *data, char which);
void				ft_rb_command(t_data *data, char which);
void				ft_ra_command(t_data *data, char which);
void				ft_rr_command(t_data *data, char which);
void				ft_pa_command(t_data *data);
void				ft_pb_command(t_data *data);

void				ft_find_pos(t_data *data, int which, int both);
void				ft_min_max(t_data *data, int which);

//void				ft_max_first(t_data *data, int which);
//void				ft_min_end(t_data *data, int which);
int					ft_only_swap(t_data *data);
int					ft_circle_sort(t_data *data);

void				ft_two_three(t_data *data);
int					ft_sort_three(t_data *data);

int					ft_four_five_sort(t_data *data);
int					ft_new_first(t_data *data);
void				ft_circle_pos(t_data *data, int f_first);
void				ft_help_c_p(t_data *data, int f_first, int *fp);

int					main_big_list(t_data *data);
void				push_opti(t_data *data);
void				premark(t_data *data);
t_stack				*get_link(t_data *data, int where);

void	ft_print_stack(t_data *data, char which, int both);


#endif
