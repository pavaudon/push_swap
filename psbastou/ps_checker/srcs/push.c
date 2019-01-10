/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 14:16:48 by bchanot           #+#    #+#             */
/*   Updated: 2016/09/21 17:20:17 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_up_sort(int *t, int len)
{
	int	i;

	i = -1;
	while (++i < len - 1)
		t[i] = t[i + 1];
	t[len - 1] = 0;
}

void	push_back_sort(int *t, int len)
{
	while (--len > 0)
		t[len] = t[len - 1];
	t[len] = 0;
}
