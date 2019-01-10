/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:28:12 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/26 08:59:58 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		take_rules(t_inf *inf)
{
	char	*line;

	line = NULL;
	while (ft_get_next_line(0, &line) > 0)
		inf->list = add_list(inf->list, line);
	return (_SUCCESS_);
}

static int		check_dublicate(t_inf *inf)
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

static int		check_sort(t_inf *inf)
{
	int	i;

	if (inf->len_b != 0)
		return (_ERROR_);
	i = inf->len - 1;
	while (--i >= 0)
	{
		if (inf->a[i] > inf->a[i + 1])
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

static void		print_l(t_list *list, int l)
{
	t_list	*begin;
	int		cpt;

	begin = list;
	cpt = 0;
	if (l)
	{
		while (list)
		{
			ft_putendl(list->line);
			list = list->next;
			cpt++;
		}
		ft_putstr("Number of rules: ");
		ft_putnbr(cpt);
		ft_putchar('\n');
		list = begin;
	}
	ft_printf("OK\n");
}

int				main(int ac, char **av)
{
	t_inf	inf;
	int		l;

	if (ac < 2)
		return (0);
	l = !ft_strcmp(av[1], "-l") ? 1 : 0;
	ac -= !ft_strcmp(av[1], "-l") ? 1 : 0;
	if (!ft_isnum(av[l + 1]) && ft_cptchar(av[l + 1], ' ') < 1 && av[1][0] == '-')
		ft_exit_err("help: -l: display rules list");
	if (!take_arg(&inf, ac, &av[l]))
		ft_putstr_fd("Error\n", 2);
	else if (!check_dublicate(&inf))
		ft_putstr_fd("Error\n", 2);
	else if (!take_rules(&inf))
		ft_putstr_fd("Error\n", 2);
	else if (check_sort(&inf) && !inf.list)
		ft_putendl("OK");
	else if (!make_rules(&inf))
		ft_putstr_fd("Error\n", 2);
	else if (!check_sort(&inf))
		ft_printf("KO\n");
	else
		print_l(inf.list, l);
	freeinf(&inf);
	return (0);
}
