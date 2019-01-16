/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:28:04 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/24 07:43:24 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(t_inf *inf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < inf->len)
	{
		j = -1;
		while (++j < inf->len)
		{
			if (j != i)
			{
				if (inf->a[i] == inf->a[j])
					return (_ERROR_);
			}
		}
	}
	return (_SUCCESS_);
}

static int	take_mode(t_inf *inf, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-v"))
			inf->print_display = true;
		else if (!ft_strcmp(av[i], "-e"))
			inf->final_display = true;
		else if (!ft_strcmp(av[i], "-c"))
			inf->cpt_rules = true;
		else if (!ft_strcmp(av[i], "-b"))
			inf->print_rules = false;
		else if (!ft_strcmp(av[i], "?") || !ft_strcmp(av[i], "-h") ||
				!ft_strcmp(av[i], "--help") || !ft_strcmp(av[i], "-help"))
			return (-1);
		else
			return (i - 1);
		i++;
	}
	return (0);
}

static void	ps_print_rules(t_inf *inf)
{
	ft_putstr_fd("Number of rules: ", 2);
	ft_putnbr_fd(inf->cpt, 2);
	ft_putchar_fd('\n', 2);
}

int			main(int ac, char **av)
{
	t_inf	inf;

	inf.cpt = 0;
	inf.cpt_rules = false;
	inf.print_rules = true;
	inf.final_display = false;
	inf.print_display = false;
	if ((inf.arg = take_mode(&inf, ac, av)) == -1)
		ft_putstr("help:\n-v : display all piles\n-e : display final pile\n\
-c : cpt total rules\n-b : undisplay rules\n");
	else if (!take_arg(&inf, ac, av, inf.arg))
		ft_exit_err("Error");
	else if (!check_duplicate(&inf))
		ft_exit_err("Error");
	else if (!check_sort(inf.a, inf.len_a))
	{
		push_swap(&inf);
		if (inf.final_display == true)
			display(&inf);
		if (inf.cpt_rules == true)
			ps_print_rules(&inf);
	}
	ft_memdel((void **)&inf.a);
	ft_memdel((void **)&inf.b);
	return (0);
}
