/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:16:13 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 11:16:17 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker(t_data *data)
{
	char	*command;
	int		len;

	printf("DDDDD\n");
	while (get_next_line(0, &command))
	{
		printf("EEEEE\n");
		len = (!command) ? 0 : ft_strlen(command);
		if ((data->size[0] > 1 && !command) || (len < 2 || len > 5) ||
		!ft_is_command(command, data, len))
		{
			ft_putendl("Error : bad command");
			return (-1);
		}
		printf("FFFFF\n");
		if ((ft_stack_sort(data->stack_a) && data->size[2] == 0)
		|| data->size[0] == 1)
			return (1);
	}
	return (0);
}

int		ft_puterror(char *error)
{
	ft_putendl(error);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (argc >= 2)
	{
		if (((argc == 2) ? !ft_check_data(argv, 0, 0) :
		!ft_check_data(argv, 0, argc))
		&& !ft_is_again(argv, argc, 0))
			return (ft_puterror("Error : ./checker int arguments"));
		ft_data_fill(argv, argc, data);
		if (ft_checker(data))
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	else
		ft_putendl("Error : ./checker int arguments");
	return (0);
}
