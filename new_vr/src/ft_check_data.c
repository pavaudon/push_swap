/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaudon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:48:55 by pavaudon          #+#    #+#             */
/*   Updated: 2018/09/20 13:48:56 by pavaudon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"

 int		ft_is_nb(char *str)
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

 int		ft_is_int(char *str)
 {
 	if (ft_atoi(str) && ft_atoi(str) <= 2147483647)
 		return (1);
 	return (0);
 }

 int    ft_check_data(char **argv, int argc, int i)
 {
   char   **tmp;
   int    j;

   while (++i < argc)
   {
     j = -1;
     tmp = (ft_strchr(argv[i], ' ')) ? ft_strsplit(argv[i], ' ') : NULL;
     if (tmp == NULL && (!ft_is_nb(argv[i]) || !ft_is_int(argv[i])))
       return (0);
     else if (tmp)
     {
       while (tmp[++j])
       {
         if (!ft_is_nb(tmp[j]) || !ft_is_int(tmp[j]))
         {
           free(tmp);
           return (0);
         }
         free(tmp);
       }
     }
   }
   return (1);
 }
