#include "libft.h"

int		ft_is_in_tab(char **tab, int value)
{
	while (tab)
	{
		if (value == ft_atoi(*tab))
			return (0);
		tab++;
	}
	return (1);
}

int		ft_strtablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_again_in_tab(char **tab, int *j, int value, int len)
{
	if (*j < (len - 1))
	{
		if (!(ft_is_in_tab(tab + 1, value)))
			return (0);
		*j += 1;
	}
	else
	{
		*j = 0;
		free(tab);
	}
	return (1);
}

char	**ft_filltabvalue(char *str, int *len)
{
	char **tab;

	tab = ft_strsplit(str, ' ');
	*len = ft_strtablen(tab);
	return (tab);
}

int		ft_is_again(char **argv, int argc, int value)
{
	int		i;
	int		j;
	int		len;
    int     tmp;
	char	**tab;

	i = 0;
	j = 0;
	while (++i < argc - 1)
	{
		if (ft_strchr(argv[i], ' ') && !tab)
			tab = ft_filltabvalue(argv[i], &len);
		value = !tab ? ft_atoi(argv[i]) : ft_atoi(tab[j]);
        tmp = i;
        while (++tmp < argc - 1)
        {
            if (tab && j < len && !ft_again_in_tab(tab, &j, value, len))
                return (0);
            else if (ft_strchr(argv[tmp + 1], ' ') &&
            !ft_is_in_tab(ft_strsplit(argv[tmp + 1], ' '), value))
                return (0);
            else
            {
                if (value == ft_atoi(argv[tmp + 1]))
                    return (0);
            }
        }
    }
	return (1);
}

int     main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (ft_is_again(argv, argc, 0))
            write(1, "OK\n", 3);
        else
            write(1, "NO\n", 3);
    }
    return (0);
}
