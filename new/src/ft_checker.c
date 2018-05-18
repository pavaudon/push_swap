/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:52:21 by pavaudon          #+#    #+#             */
/*   Updated: 2018/05/17 14:52:22 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_puterror(char *error)
{
	ft_putstr_fd(error, 2);
	return (-1);
}

int		main(int argc, char **argv)
{
	int	i;
	int tmp;

	i = 0;
	tmp = 0;
	if (argc < 2 || (!ft_checkarg(argv) && argc > 2))
		return (ft_puterror("Error : ./checker int arguments\n"));
	if (argc == 2 && (ft_strlen(argv[1]) > 1))
	{
		if ((ft_nb_arg(argv[1]) < 2) && !ft_checkarg(ft_strsplit(argv[1], ' ')))
			return (ft_puterror("Error : ./checker int arguments\n"));
		tmp = 1;
	}
	if ((tmp == 1) ? !ft_is_good_int(ft_strsplit(argv[1], ' ')) :
	!ft_is_good_int(argv + 1))
		return (ft_puterror("Error : ./checker int arguments\n"));
	if ((tmp == 1) ? !ft_checker(ft_strsplit(argv[1], ' '))
	: !ft_checker(argv + 1))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (0);
}
