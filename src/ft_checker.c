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

void      ft_data_stack(int argc, char **argv, t_both *both)
{
	int   i;
	int   cpt;

	i = 0;
	cpt = 0;
	both->the_min = ft_atoi(argv[1]);
	both->the_max = both->the_min;
	while (++i < argc)
	{
    	cpt++;
    	both->the_min = (both->the_min > ft_atoi(argv[i])) ? ft_atoi(argv[i]) : both->the_min;
    	both->the_max = (both->the_max < ft_atoi(argv[i])) ? ft_atoi(argv[i]) : both->the_max;
	}
	both->the_size = cpt;
	SIZE_A = cpt;
	SIZE_B = 0;
}

int     ft_fill_a(int argc, char **argv, t_both *both)
{
	int   i;
	int   j;

	i = 0;
	j = -1;
	ft_data_stack(argc, argv, both);
	if (!(TAB_B = (int*)ft_memalloc(sizeof(int) * both->the_size)) ||
	!(TAB_A = (int*)ft_memalloc(sizeof(int) * both->the_size)))
    	return (-1);
	while (++i < argc)
    	TAB_A[++j] = ft_atoi(argv[i]);
	return (1);
}

int     ft_checker(int argc, char **argv)
{
	t_both		*both;
	char		*command;

	if (!(both = (t_both*)ft_memalloc(sizeof(t_both))) ||
	!(both->stack_a = (t_stack*)ft_memalloc(sizeof(t_stack))) ||
	!(both->stack_b = (t_stack*)ft_memalloc(sizeof(t_stack))) ||
	!ft_checkarg(argc, argv) || !ft_fill_a(argc, argv, both))
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
 	int i;

 	i = 0;
 	if (argc < 2)
		return(ft_puterror("Error : ./checker int arguments\n"));
	while (++i < argc)
	{
    	if (!ft_is_good_int(argv[i]))
			return (ft_puterror("Error : ./checker int arguments\n"));
	}
	if (ft_checker(argc, argv))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
