/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:50:32 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/25 15:50:33 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>

# include "libft.h"

typedef struct		s_stack
{
    int			      	value;
    struct s_stack	*next;
}               	t_stack;

#endif
