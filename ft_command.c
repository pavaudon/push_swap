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
		if (!ft_strcmp("ra", *command) || !ft_strcmp("rb", *command) || )		//gerer rra/rrb//rrr en meme temps?
			return (0);
		ft_rcommand(both, command[1]);
	}
	ft_current_data(both);
	return (1);
}

void	ft_scommand(t_both *both, char c)
{
	int	*tmp;
	int	i;
	int value;

	tmp = (c == 'a' || c == 'r') ? both->stack_a->tab : both->stack_b->tab;
	i = (c == 'a' || c == 'r') ? both->stack_a->size : both->stack_b->size;
	value = tmp[0];
	tmp[0] = tmp[1];
	tmp[1] = value;
	if (c == 'r')
		ft_scommand(both, 'b');
}

void	ft_pcommand(both, char c)
{
	
}
