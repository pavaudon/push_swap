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

int		ft_is_command(char *command, t_both *both)
{
	if (command[0] == 's')
	{
		if (ft_strcmp("sa", command) || ft_strcmp("sb", command) || ft_strcmp("ss", command))
			ft_scommand(both, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'p')
	{
		if (ft_strcmp("pa", command) || ft_strcmp("pb", command))
			ft_pcommand(both, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'r')
	{
		if (ft_strcmp("ra", command) || ft_strcmp("rb", command) || ft_strcmp("rr", command))
			ft_rcommand(both, command[1]);
		else if (ft_strcmp("rra", command) || ft_strcmp("rrb", command) || ft_strcmp("rrr", command))
			ft_rrcommand(both, command[2]);
		else
			return (0);
	}
	else
		return (0);
	ft_current_data(both);
	return (1);
}

void	ft_scommand(t_both *both, char c)
{
	int	*tmp;
	int value;

	tmp = (c == 'a' || c == 's') ? ft_tabdup(TAB_A, SIZE_A) : ft_tabdup(TAB_B, SIZE_B);
	value = tmp[0];
	tmp[0] = tmp[1];
	tmp[1] = value;
	if (c == 'b')
	{
		TAB_B = ft_tabdup(tmp, SIZE_B);
		printf("	TAB_B	\n");
		ft_puttab(TAB_B, SIZE_B);
	}
	else
	{
		TAB_A = ft_tabdup(tmp, SIZE_A);
		printf("	TAB_A	\n");
		ft_puttab(TAB_A, SIZE_A);
		if (c == 's')
			ft_scommand(both, 'b');
	}
}

void	ft_pcommand(t_both *both, char c)
{
	if (c == 'a' && SIZE_A > 0)
	{
		TAB_B = (SIZE_B > 0) ? ft_tabjoin(TAB_B, &TAB_A[0], SIZE_B, SIZE_A, 'b', 'b') : ft_tabndup(TAB_A, 1, 1);
		TAB_A = ft_tabsub(TAB_A, 1, (SIZE_A - 1));
		SIZE_A -= 1;
		SIZE_B += 1;
		printf("	TAB_A	\n");
		ft_puttab(TAB_A, SIZE_A);
		printf("	TAB_B	\n");
		ft_puttab(TAB_B, SIZE_B);
		printf("SIZE_A : %d		SIZE_B : %d\n", SIZE_A, SIZE_B);
	}
	else if (c == 'b' && SIZE_B > 0)
	{
		TAB_A = (SIZE_A > 0) ? ft_tabjoin(TAB_A, &TAB_B[0], SIZE_A, SIZE_B, 'b', 'b') : ft_tabndup(TAB_B, 1, 1);
		TAB_B = ft_tabsub(TAB_B, 1, (SIZE_B - 1));
		SIZE_B -= 1;
		SIZE_A += 1;
		printf("	TAB_A	\n");
		ft_puttab(TAB_A, SIZE_A);
		printf("	TAB_B	\n");
		ft_puttab(TAB_B, SIZE_B);
		printf("SIZE_A : %d		SIZE_B : %d\n", SIZE_A, SIZE_B);
	}
	else
		ft_pcommand(both, 'b');
}

void	ft_rcommand(t_both *both, char c)
{
	int *tmp;
	int size;

	tmp = (c =='a' || c == 'r') ? TAB_A : TAB_B;
	size = (c == 'a' || c == 'r') ? SIZE_A : SIZE_B;
	tmp = ft_tabsub(tmp, 1, size);
	tmp = ft_tabjoin(tmp + 1, &tmp[0], (size - 1), 1, 'e', 'b');
	if (c == 'b')
	{
		TAB_B = tmp;
		printf("	TAB_B	\n");
		ft_puttab(TAB_B, SIZE_B);
	}
	else
	{
		TAB_A = tmp;
		printf("	TAB_A	\n");
		ft_puttab(TAB_A, SIZE_A);
		if (c == 'r')
			ft_rcommand(both, 'b');
	}
}

void	ft_rrcommand(t_both *both, char c)
{
	int *tmp;
	int size;

	tmp = (c =='a' || c == 'r') ? TAB_A : TAB_B;
	size = (c == 'a' || c == 'r') ? SIZE_A : SIZE_B;
	tmp = ft_tabsub(tmp, 0, (size - 1));
	tmp = ft_tabjoin(tmp, &tmp[size], (size - 1), 1, 'b', 'b');
	if (c == 'b')
	{
		TAB_B = tmp;
		printf("	TAB_B	\n");
		ft_puttab(TAB_B, SIZE_B);
	}
	else
	{
		TAB_A = tmp;
		printf("	TAB_A	\n");
		ft_puttab(TAB_A, SIZE_A);
		if (c == 'r')
			ft_rrcommand(both, 'b');
	}
}
