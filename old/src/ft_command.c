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

void	ft_print_a_b(t_both *both)
{
	printf("	TAB_A	\n");
	ft_puttab(TAB_A, SIZE_A);
	printf("	TAB_B	\n");
	ft_puttab(TAB_B, SIZE_B);
}

int		ft_is_command(char *command, t_both *both, int len)
{
	if (command[0] == 's' && len == 2)
	{
		if (ft_strcmp("sa", command) || ft_strcmp("sb", command) ||
		ft_strcmp("ss", command))
			ft_scommand(both, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'p' && len == 2)
	{
		if (ft_strcmp("pa", command) || ft_strcmp("pb", command))
			ft_pcommand(both, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'r' && len < 4)
		return (ft_is_rcommand(command, both, len));
	else
		return (0);
	ft_print_a_b(both);
	ft_current_data(both);
	return (1);
}

int		ft_is_rcommand(char *command, t_both *both, int len)
{
	if (len == 2 && (ft_strcmp("ra", command) || ft_strcmp("rb", command) ||
	ft_strcmp("rr", command)))
		ft_rcommand(both, command[1]);
	else if (len == 3 && (ft_strcmp("rra", command)
	|| ft_strcmp("rrb", command) || ft_strcmp("rrr", command)))
		ft_rrcommand(both, command[2]);
	else
		return (0);
	ft_print_a_b(both);
	return (1);
}

void	ft_scommand(t_both *both, char c)
{
	int		*tmp;
	int		value;

	tmp = (c == 'a' || c == 's') ? ft_tabdup(TAB_A, SIZE_A) :
	ft_tabdup(TAB_B, SIZE_B);
	value = tmp[0];
	tmp[0] = tmp[1];
	tmp[1] = value;
	if (c == 'b' && SIZE_B > 1)
	{
		free(TAB_B);
		TAB_B = ft_tabdup(tmp, SIZE_B);
	}
	else if ((c == 'a' || c == 's') && SIZE_A > 1)
	{
		free(TAB_A);
		TAB_A = ft_tabdup(tmp, SIZE_A);
		if (c == 's')
			ft_scommand(both, 'b');
	}
	free(tmp);
}

void	ft_pcommand(t_both *both, char c)
{
	if (c == 'a')
	{
		if (SIZE_A > 0)
		{
			TAB_B = (SIZE_B > 0) ? ft_tabfsjoin(&TAB_A[0], TAB_B, 1, SIZE_A)
			: ft_tabndup(TAB_A, 1, 1);
			if (SIZE_A > 1)
				TAB_A = ft_tabsub(TAB_A, 1, (SIZE_A - 1));
			SIZE_A -= 1;
			SIZE_B += 1;
		}
	}
	else if (c == 'b')
	{
		if (SIZE_B > 0)
		{
			TAB_A = (SIZE_A > 0) ? ft_tabfsjoin(&TAB_B[0], TAB_A, 1, SIZE_B)
			: ft_tabndup(TAB_B, 1, 1);
			if (SIZE_B > 1)
				TAB_B = ft_tabsub(TAB_B, 1, (SIZE_B - 1));
			SIZE_B -= 1;
			SIZE_A += 1;
		}
	}
}

void	ft_rcommand(t_both *both, char c)
{
	int value;
	int	*tmp;

	if (c == 'b' && SIZE_B > 1)
	{
		value = TAB_B[0];
		tmp = ft_tabsub(TAB_B, 1, (SIZE_B - 1));
		TAB_B = ft_tabffjoin(tmp, &value, (SIZE_B - 1), 1);
	}
	if (c == 'a' || c == 'r')
	{
		if (SIZE_A > 1)
		{
			value = TAB_A[0];
			tmp = ft_tabsub(TAB_A, 1, (SIZE_A - 1));
			TAB_A = ft_tabffjoin(tmp, &value, (SIZE_A - 1), 1);
		}
		if (c == 'r')
			ft_rcommand(both, 'b');
	}
}

void	ft_rrcommand(t_both *both, char c)
{
	int value;
	int	*tmp;

	if (c == 'b' && SIZE_B > 0)
	{
		value = TAB_B[SIZE_B - 1];
		tmp = ft_tabsub(TAB_B, 0, (SIZE_B - 1));
		TAB_B = ft_tabfsjoin(&value, tmp, 1, (SIZE_B - 1));
	}
	if (c == 'a' || c == 'r')
	{
		if (SIZE_A > 0)
		{
			value = TAB_A[SIZE_A - 1];
			tmp = ft_tabsub(TAB_A, 0, (SIZE_A - 1));
			TAB_A = ft_tabfsjoin(&value, tmp, 1, (SIZE_A - 1));
		}
		if (c == 'r')
			ft_rcommand(both, 'b');
	}
}
