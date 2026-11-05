/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 10:02:03 by vduryee           #+#    #+#             */
/*   Updated: 2026/10/25 11:01:48 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	while (i < len)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
