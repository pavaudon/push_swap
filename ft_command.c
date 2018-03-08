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

int		ft_is_command(char command, t_both *both)
{
	if (command[0] == 's')
	{
		if (!ft_strcmp("sa", *command) || !ft_strcmp("sb", *command) || !ft_strcmp("ss", *command))
			return (0);
		ft_scommand(both, command[1]);
	}
	if (command[0] == 'p')
	{
		if (!ft_strcmp("pa", *command) || !ft_strcmp("pb", *command))
			return (0);
		ft_pcommand(both, command[1]);
	}
	if (command[0] == 'r')
	{
		if (ft_strcmp("ra", *command) || ft_strcmp("rb", *command) || ft_strcmp("rr", *command))
			ft_rcommand(both, command[1]);
		else if (ft_strcmp("rra", *command) || ft_strcmp("rrb", *command) || ft_strcmp("rrr", *command))
			ft_rrcommand(both, command[2]);
		else
			return (0);
	}
	ft_current_data(both);
	return (1);
}

void	ft_scommand(t_both *both, char c)
{
	int	*tmp;
	int value;

	tmp = (c == 'a' || c == 'r') ? TAB_A : TAB_B;
	value = tmp[0];
	tmp[0] = tmp[1];
	tmp[1] = value;
	if (c == 'b')
		TAB_B = tmp;
	else
	{
		TAB_A = tmp;
		if (c == 'r')
			ft_scommand(both, 'b');
	}
}

void	ft_pcommand(t_both *both, char c)
{
	int *tmp;
	int i;

	i = 0;
	if (c == 'a')
	{
		TAB_B = ft_tabjoin(TAB_B, TAB_A[0], 'b', 'b');
		TAB_A = ft_tabsub(TAB_A, 1, ft_inttablen((TAB_A) - 1));
	}
	else if (c == 'b')
	{
			TAB_A = ft_tabjoin(TAB_A, TAB_B[0], 'b', 'b');
			TAB_B = ft_tabsub(TAB_B, 1, ft_inttablen((TAB_B) - 1));
	}
	else
		pcommand(both, 'b');
}

void	ft_rcommand(t_both *both, char c)
{
	int *tmp;
	int value;

	tmp = (c =='a' || c == 'r') ? TAB_A : TAB_B;
	value = (c == 'a' || c == 'r') ? TAB_A[SIZE_A] : TAB_B[SIZE_B];
	tmp = ft_tabsub(tmp, 1, ft_inttab(tmp));
	tmp = ft_tabjoin(tmp, &value, 'e', 'b');
	if (c == 'b')
		TAB_B = tmp;
	else
	{
		TAB_A = tmp;
		if (c == 'r')
			ft_rcommand(both, 'b');
	}
}

void	ft_rrcommand(t_both *both, char c)
{
	int *tmp;
	int value;

	tmp = (c =='a' || c == 'r') ? TAB_A : TAB_B;
	value = (c == 'a' || c == 'r') ? TAB_A[0] : TAB_B[0];
	tmp = ft_tabsub(tmp, 0, (ft_inttab(tmp) - 1));
	tmp = ft_tabjoin(tmp, &value, 'b', 'b');
	if (c == 'b')
		TAB_B = tmp;
	else
	{
		TAB_A = tmp;
		if (c == 'r')
			ft_rrcommand(both, 'b');
	}
}
