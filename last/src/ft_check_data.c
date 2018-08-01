/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <lalicornede42@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:15:53 by pavaudon          #+#    #+#             */
/*   Updated: 2018/08/01 11:16:01 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int     ft_check_data(char **argv, int cpt, int size)
{
    char **tmp;

    argv++;
    if (ft_strchr(str, ' '))
    {
        tmp = ft_strsplit(*argv, ' ')
        while (tmp++)
        {
            if (!ft_is_nb(*tmp) || !ft_is_int(*tmp))
                return (0);
            free(tmp);
        }
    }
    else
        if (!ft_is_nb(*argv) || !ft_is_int(*argv))
            return (0);
    }
    if (cpt > 2 && cpt < size)
        return (ft_check_data(argv++), cpt--, size);
    return (1);
}

int     ft_is_nb(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) || (str[i] == '-' && i == 0))
        {
            i++;
            while (str[i] && (ft_isdigit(str[i])))
                i++;
        }
        else
            return (0);
    }
    return (1);
}

int     ft_is_int(char *str)
{
    if (ft_atoi(str) && ft_atoi(str) <= 2147483647)
        return (1);
    return (0);
}

int     ft_strtablen(char **tab)
{
    int i;

    i = 0;
    while (tab)
        i++;
    return (i);
}

int     ft_is_in_tab(char **tab, int value)
{
    while (tab)
    {
        if (value == ft_atoi(*tab))
            return (0);
        tab++;
    }
    return (1);
}

int     ft_is_again(char **argv, int argc, int value)
{
    int i;
    char **tab;

    i = 0;
    while (++i < argc - 1)
    {
        if (!tab)
            tab = (ft_strchr(argv[i], ' ')) ? ft_strsplit(argv[i], ' ') : NULL;
        value = !tab ? ft_atoi(argv[i]) : ft_atoi(*tab);
        if (tab && !ft_is_in_tab(tmp, value))
                return (0);
            if (tab + 1)
                tab++;
        }
        else if (ft_strchr(argv[i + 1], ' ') &&
        !ft_is_in_tab(ft_strsplit(argv[i + 1]), value))
                return (0);
        else
            if (value == ft_atoi(argv[i + 1]))
                return (0);
    }
    return (1);
}
