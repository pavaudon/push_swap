

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

int     ft_is_again(char *str)      //gérer autrement pour tout prendre
{
    int tmp;

    tmp = ft
}
