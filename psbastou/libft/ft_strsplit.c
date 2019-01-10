/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 02:25:46 by bchanot           #+#    #+#             */
/*   Updated: 2015/12/07 13:47:51 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cpt(char const *s, char c)
{
	int cpt;
	int cpt2;

	cpt = 0;
	cpt2 = 0;
	while (s[cpt])
	{
		while (s[cpt] == c && s[cpt])
			cpt++;
		if (s[cpt] != c && s[cpt])
			cpt2++;
		while (s[cpt] != c && s[cpt])
			cpt++;
	}
	return (cpt2);
}

static int		ft_word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	if (!len)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**t_str;
	int		word;
	int		i;

	word = 0;
	i = 0;
	if (!s)
		return (NULL);
	t_str = (char **)malloc(sizeof(char *) * (ft_cpt(s, c) + 1));
	if (!t_str)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			t_str[word] = ft_strsub(&s[i], 0, ft_word_len(&s[i], c));
			i = i + ft_word_len(&s[i], c);
			word++;
		}
	}
	t_str[word] = NULL;
	return (t_str);
}
