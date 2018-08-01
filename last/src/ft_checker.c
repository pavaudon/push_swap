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

int		ft_is_command(char *command, t_data *data, int len)
{
	if (command[0] == 's' && len == 2)
	{
		if (!ft_strcmp("sa", command) || !ft_strcmp("sb", command) ||
		ft_strcmp("ss", command))
			ft_scommand(data, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'p' && len == 2)
	{
		if (!ft_strcmp("pa", command) || !ft_strcmp("pb", command))
			ft_pcommand(data, command[1]);
		else
			return (0);
	}
	else if (command[0] == 'r' && len < 4)
		return (ft_is_rcommand(command, data, len));
	else
		return (0);
	return (1);
}

int		ft_is_rcommand(char *command, t_data *data, int len)
{
	if (len == 2 && (!ft_strcmp("ra", command) || !ft_strcmp("rb", command) ||
	!ft_strcmp("rr", command)))
		ft_rcommand(data, command[1]);
	else if (len == 3 && (!ft_strcmp("rra", command)
	|| !ft_strcmp("rrb", command) || !ft_strcmp("rrr", command)))
		ft_rrcommand(data, command[2]);
	else
		return (0);
	return (1);
}

int		ft_checker(t_data *data)
{
	char	*command;
	int		len;

	while (get_next_line(0, &command))
	{
		len = (!command) ? 0 : ft_strlen(command);
		if (data->size[0] > 1 && !command || (len < 2 || len > 5) ||
		!ft_is_command(command, data, len))
		{
			ft_putendl("Error : bad command");
			return (-1);
		}
		if ((ft_stack_sort(data->stack_a, data->size[1]) && data->size_b == 0)
		|| data->size[0] == 1)
			return (1);
	}
	return (0);
}

int     main(int arg, char **argv)
{
	t_data *data;

    if (argc > 2)
    {
        if (((argc == 2) ? !ft_check_data(argv, argc, 0) : !ft_check_data(argv),
        0, argc) && (argc == 2) ? !ft_is_again(argv, argc, 0) :
        !ft_is_again(argv), argc, 0))
            return (ft_putendl("Error : ./checker int arguments"));
        ft_data_fill(argv, argc, data);
		if (checker(data))
            ft_putendl("OK");
        else
            ft_putendl("KO");
    }
    else
        ft_putendl("Error : ./checker int arguments");
    return (0);
}
