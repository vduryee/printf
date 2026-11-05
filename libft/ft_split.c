/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:35:27 by vduryee           #+#    #+#             */
/*   Updated: 2026/10/29 14:24:16 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && !(str[i] == c))
			i++;
	}
	return (count);
}

static char	**ft_free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	split_helper(char **tab, char const *str, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		while (str[i] && !(str[i] == c))
			i++;
		if (i > start)
		{
			tab[j] = ft_substr((char *)str, start, (size_t)i - (size_t)start);
			if (!tab[j])
				return (0);
			j++;
		}
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(char *), (ft_count_words((char *)str, c) + 1));
	if (!tab)
		return (NULL);
	if (!split_helper(tab, str, c))
	{
		ft_free_all(tab);
		return (NULL);
	}
	return (tab);
}
