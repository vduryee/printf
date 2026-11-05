/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:49:16 by vduryee           #+#    #+#             */
/*   Updated: 2026/10/23 16:55:35 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*fst;
	unsigned char	*snd;

	fst = (unsigned char *)s1;
	snd = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (fst[i] != snd[i])
			return (fst[i] - snd[i]);
		i++;
	}
	return (0);
}
