/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:35:25 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 17:35:28 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_command(char **command, t_both *both)
{
	if (*command[0] == 's')
	{
		if (ft_strcmp("sa", *command) || ft_strcmp("sb", *command) || ft_strcmp("ss", *command))
			ft_scommand(both, *command[1]);
		else
			return (-1);
	}
	if (*command[0] == 'p')
	{
		if (ft_strcmp("pa", *command) || ft_strcmp("pb", *command))
			ft_pcommand(both, *command[1]);
		else
			return (-1);
	}
	if (*command[0] == 'r')
	{
		if (ft_strcmp("ra", *command) || ft_strcmp("rb", *command) || ft_strcmp("rr", *command))
			ft_rcommand(both, *command[1]);
		else if (ft_strcmp("rra", *command) || ft_strcmp("rrb", *command) || ft_strcmp("rrr", *command))
			ft_rrcommand(both, *command[2]);
		else
			return (0);
	}
	else
		return (-1);
	ft_current_data(both);
	return (1);
}

void	ft_scommand(t_both *both, char c)
{
	int	*tmp;
	int value;

	tmp = (c == 'a' || c == 'r') ? both->stack_a->tab : both->stack_b->tab;
	value = tmp[0];
	tmp[0] = tmp[1];
	tmp[1] = value;
	if (c == 'b')
		both->stack_b->tab = tmp;
	else
	{
		both->stack_a->tab = tmp;
		if (c == 'r')
			ft_scommand(both, 'b');
	}
}

void	ft_pcommand(t_both *both, char c)
{
	if (c == 'a')
	{
		both->stack_b->tab = ft_tabjoin(both->stack_b->tab, &both->stack_a->tab[0],
		both->stack_b->size, both->stack_a->size, 'b', 'b');
		printf("GOOD TABJOIN : TAB_B\n");
		both->stack_a->tab = ft_tabsub(both->stack_a->tab, 1, (both->stack_a->size - 1));
		printf("GOOD TABSUB TAB_A\n");
	}
	else if (c == 'b')
	{
		both->stack_a->tab = ft_tabjoin(both->stack_a->tab, &both->stack_b->tab[0],
		both->stack_a->size, both->stack_b->size, 'b', 'b');
		both->stack_b->tab = ft_tabsub(both->stack_b->tab, 1, (both->stack_b->size - 1));
	}
	else
		ft_pcommand(both, 'b');
}

void	ft_rcommand(t_both *both, char c)
{
	int *tmp;
	int size;

	tmp = (c =='a' || c == 'r') ? both->stack_a->tab : both->stack_b->tab;
	size = (c == 'a' || c == 'r') ? both->stack_a->size : both->stack_b->size;
	tmp = ft_tabsub(tmp, 1, size);
	tmp = ft_tabjoin(tmp + 1, &tmp[0], (size - 1), 1, 'e', 'b');
	if (c == 'b')
		both->stack_b->tab = tmp;
	else
	{
		both->stack_a->tab = tmp;
		if (c == 'r')
			ft_rcommand(both, 'b');
	}
}

void	ft_rrcommand(t_both *both, char c)
{
	int *tmp;
	int size;

	tmp = (c =='a' || c == 'r') ? both->stack_a->tab : both->stack_b->tab;
	size = (c == 'a' || c == 'r') ? both->stack_a->size : both->stack_b->size;
	tmp = ft_tabsub(tmp, 0, (size - 1));
	tmp = ft_tabjoin(tmp, &tmp[size], (size - 1), 1, 'b', 'b');
	if (c == 'b')
		both->stack_b->tab = tmp;
	else
	{
		both->stack_a->tab = tmp;
		if (c == 'r')
			ft_rrcommand(both, 'b');
	}
}
