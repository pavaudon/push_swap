/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:04:47 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/24 06:20:49 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list			*freelist(t_list *list)
{
	t_list	*temp1;
	t_list	*temp2;

	if (list)
	{
		temp1 = list;
		while (temp1)
		{
			temp2 = temp1->next;
			ft_memdel((void **)&temp1->line);
			ft_memdel((void **)&temp1);
			temp1 = temp2;
		}
		list = NULL;
	}
	return (list);
}

static t_list	*new_list(void)
{
	t_list	*list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	list->next = NULL;
	list->line = NULL;
	return (list);
}

t_list			*add_list(t_list *list, char *line)
{
	t_list	*tmp;

	if (!(list))
	{
		list = new_list();
		list->line = line;
		return (list);
	}
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_list();
	tmp = tmp->next;
	tmp->line = line;
	return (list);
}

static void		take_arg_help(t_inf *inf, int ac, char **av)
{
	char	**list;
	int		i;
	int		j;
	int		tmp;

	inf->a = (int *)ft_memalloc(sizeof(int) * (inf->len));
	inf->b = (int *)ft_memalloc(sizeof(int) * (inf->len));
	i = 0;
	tmp = -1;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
			inf->a[++tmp] = ft_atoi(list[j]);
		ft_memdel2((void ***)&list);
	}
	inf->len_a = inf->len;
	inf->len_b = 0;
}

int				take_arg(t_inf *inf, int ac, char **av)
{
	int		i;
	int		j;
	char	**list;
	char	*tmp;
	int		nb;

	i = 0;
	inf->len = 0;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
		{
			nb = ft_atoi(list[j]);
			tmp = ft_itoa(nb);
			if (!ft_strisdigit(list[j]) || ft_strcmp(list[j], tmp))
				return (ms_free_error(tmp, list));
			inf->len++;
			ft_memdel((void **)&tmp);
		}
		ft_memdel2((void ***)&list);
	}
	take_arg_help(inf, ac, av);
	return (_SUCCESS_);
}
