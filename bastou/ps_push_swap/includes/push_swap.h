/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:55:20 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/25 06:03:02 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/libft.h"

typedef struct	s_inf
{
	int			*a;
	int			*b;
	int			len_a;
	int			len_b;
	int			len;
	int			cpt;
	int			arg;
	t_bool		cpt_rules;
	t_bool		print_rules;
	t_bool		final_display;
	t_bool		print_display;
}				t_inf;

int				take_arg(t_inf *inf, int ac, char **av, int arg);

void			push_swap(t_inf *inf);

int				take_max(int *p, int len);
int				take_min(int *p, int len);
int				is_reverse(t_inf *inf);

int				is_rabis(t_inf *inf, int pivot);
int				is_ra(t_inf *inf, int pivot);
int				is_rb(t_inf *inf);
int				check_five_less(t_inf *inf);

void			push_up_sort(int *t, int len);
void			push_back_sort(int *t, int len);

int				sort_ra_rra(t_inf *inf);
int				sort_piece(t_inf *inf);
int				is_it_necessary(t_inf *inf);

void			rule_sa(t_inf *inf);
void			rule_sb(t_inf *inf);
void			rule_pa(t_inf *inf);
void			rule_pb(t_inf *inf);
void			rule_ra(t_inf *inf);
void			rule_rb(t_inf *inf);
void			rule_rra(t_inf *inf);
void			rule_rrb(t_inf *inf);
void			rule_ss(t_inf *inf);
void			rule_rr(t_inf *inf);
void			rule_rrr(t_inf *inf);

void			display(t_inf *inf);
int				check_sort(int *i, int len);
void			check_list(int *list, int deb, int fin);
int				is_simple_sa(t_inf *inf);

#endif
