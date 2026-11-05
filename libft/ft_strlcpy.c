/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:30:57 by vduryee           #+#    #+#             */
/*   Updated: 2026/10/22 13:55:41 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	c;

	len = ft_strlen(src);
	i = 0;
	if (size)
	{
		while (i < size - 1)
		{
			c = src[i];
			dst[i] = c;
			if (c == '\0')
				return (len);
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
