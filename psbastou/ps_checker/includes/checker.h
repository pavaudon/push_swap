/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:29:22 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/24 06:21:19 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/includes/libft.h"

typedef struct			s_list
{
	char				*line;
	struct s_list		*next;
}						t_list;

typedef struct			s_inf
{
	int					*a;
	int					*b;
	int					len_a;
	int					len_b;
	int					len;
	t_list				*list;
}						t_inf;

int						take_arg(t_inf *inf, int ac, char **av);

int						make_rules(t_inf *inf);
int						ms_free_error(char *tmp, char **list);

void					push_up_sort(int *t, int len);
void					push_back_sort(int *t, int len);

t_list					*add_list(t_list *list, char *line);
void					freeinf(t_inf *inf);
t_list					*freelist(t_list *list);

void					rule_sa(t_inf *inf);
void					rule_sb(t_inf *inf);
void					rule_pa(t_inf *inf);
void					rule_pb(t_inf *inf);
void					rule_ra(t_inf *inf);
void					rule_rb(t_inf *inf);
void					rule_rra(t_inf *inf);
void					rule_rrb(t_inf *inf);

#endif
