/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:21:30 by bchanot           #+#    #+#             */
/*   Updated: 2016/10/20 10:49:26 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		display(t_inf *inf)
{
	int	i;

	i = -1;
	ft_putstr_fd("Pile A\n", 2);
	while (++i < inf->len_a)
	{
		ft_putstr_fd("->", 2);
		ft_putnbr_fd(inf->a[i], 2);
	}
	i = -1;
	ft_putstr_fd("\nPile B\n", 2);
	while (++i < inf->len_b)
	{
		ft_putstr_fd("->", 2);
		ft_putnbr_fd(inf->b[i], 2);
	}
	if (inf->len_b > 0)
		ft_putchar_fd('\n', 2);
	ft_putchar_fd('\n', 2);
}

static int	more_fufu(int cpt[4], int *a, int *tab1, int deb1)
{
	if (cpt[1] == (cpt[3] + 1))
	{
		a[cpt[2]] = tab1[cpt[0] - deb1];
		cpt[0]++;
		return (_SUCCESS_);
	}
	else if (tab1[cpt[0] - deb1] < a[cpt[1]])
	{
		a[cpt[2]] = tab1[cpt[0] - deb1];
		cpt[0]++;
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static void	fufu(int *a, int deb1, int fin1, int fin2)
{
	int *tab1;
	int	cpt[4];

	tab1 = (int *)ft_memalloc(sizeof(int) * (fin1 - deb1 + 1));
	cpt[1] = fin1 + 1;
	cpt[0] = deb1;
	cpt[2] = deb1 - 1;
	cpt[3] = fin2;
	while (++cpt[2] <= fin1)
		tab1[cpt[2] - deb1] = a[cpt[2]];
	fin1++;
	cpt[2] = deb1 - 1;
	while (++cpt[2] <= cpt[3])
	{
		if (cpt[0] == fin1)
			break ;
		else if (more_fufu(cpt, a, tab1, deb1))
			;
		else
		{
			a[cpt[2]] = a[cpt[1]];
			cpt[1]++;
		}
	}
	ft_memdel((void **)&tab1);
}

void		check_list(int *list, int deb, int fin)
{
	int mid;

	if (fin != deb)
	{
		mid = (fin + deb) / 2;
		check_list(list, deb, mid);
		check_list(list, mid + 1, fin);
		fufu(list, deb, mid, fin);
	}
}
