/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:54:33 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/06 12:26:44 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

int ft_putchar (char c);
int ft_putstr (char *str);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int ft_putnbr_hex(unsigned long int n, char type);

#endif