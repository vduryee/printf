/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:54:33 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/05 18:15:19 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

int ft_putchar (char c);
int ft_putstr (char *str, int count);
int	ft_putnbr(int n, int count);
int	ft_putnbr_unsigned(unsigned int n, int count);

#endif