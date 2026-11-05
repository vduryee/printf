/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:30:57 by vduryee           #+#    #+#             */
/*   Updated: 2026/10/22 16:51:29 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;
	size_t	res;

	i = 0;
	srclen = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (size + srclen);
	dstlen = ft_strlen(dst);
	res = size - dstlen - 1;
	if (dstlen >= size)
		return (size + srclen);
	while (src[i] && res)
	{
		dst[dstlen + i] = src[i];
		i++;
		res--;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
