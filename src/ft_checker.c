/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:23:30 by pavaudon          #+#    #+#             */
/*   Updated: 2018/03/07 17:23:33 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void      ft_data_stack(char **argv, t_both *both)
{
	int   i;
	int   cpt;

	i = -1;
	cpt = 0;
	both->the_min = ft_atoi(argv[0]);
	both->the_max = both->the_min;
	while (argv[++i])
	{
    	cpt++;
    	both->the_min = (both->the_min > ft_atoi(argv[i])) ? ft_atoi(argv[i]) : both->the_min;
    	both->the_max = (both->the_max < ft_atoi(argv[i])) ? ft_atoi(argv[i]) : both->the_max;
	}
	both->the_size = cpt;
	SIZE_A = cpt;
	SIZE_B = 0;
}

int     ft_fill_a(char **argv, t_both *both)
{
	int   i;
	int   j;

	i = -1;
	j = -1;
	ft_data_stack(argv, both);
	if (!(TAB_B = (int*)ft_memalloc(sizeof(int) * both->the_size)) ||
	!(TAB_A = (int*)ft_memalloc(sizeof(int) * both->the_size)))
    	return (-1);
	while (argv[++i])
	{
    	TAB_A[++j] = ft_atoi(argv[i]);
		printf("argv[%d] : '%s' TAB_A[%d] : '%d'\n", i, argv[i], j, TAB_A[j]);
	}
	return (1);
}

int     ft_checker(char **argv)
{
	t_both		*both;
	char		*command;

	if (!(both = (t_both*)ft_memalloc(sizeof(t_both))) ||
	!(both->stack_a = (t_stack*)ft_memalloc(sizeof(t_stack))) ||
	!(both->stack_b = (t_stack*)ft_memalloc(sizeof(t_stack))) ||
	!ft_fill_a(argv, both))
		return (-1);
	printf("DEBUT :\n");
	ft_puttab(TAB_A, SIZE_A);
	while (get_next_line(0, &command))
	{
		printf("command : '%s'\n", command);
    	if ((ft_strlen(command) < 2 || ft_strlen(command) > 5) || !ft_is_command(command, both, ft_strlen(command)))
    	{
        	ft_puterror("Error : bad command\n");
        		return (-1);
    	}
		if ((ft_is_sort(TAB_A, SIZE_A) && SIZE_B == 0) || both->the_size == 1)
			return (1);
	}
	return (0);
}

int     ft_puterror(char *error)
{
	ft_putstr_fd(error, 2);
	return (-1);
}

int     main(int argc, char **argv)
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
    if ((tmp == 1) ? !ft_is_good_int(ft_strsplit(argv[1], ' ')) : !ft_is_good_int(argv + 1))
		return (ft_puterror("Error : ./checker int arguments\n"));
	if ((tmp == 1) ? !ft_checker(ft_strsplit(argv[1], ' ')) : !ft_checker(argv + 1))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (0);
}
