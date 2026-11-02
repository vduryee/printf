/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:14 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/02 16:35:35 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch (char *format)
{
	if (*format == '%')
		ft_putchar_fd(*format, 1);
	else if (*format == 'c')
		ft_putchar_fd((*format + 1) , 1);
	else if (*format == 's')
	// putstr
	else if (*format == 'p')
	// print pointer in hex (must print (nil) 0x in front)
	else if (*format == 'd' || *format == 'i')
	// putnbr
	else if (*format == 'u')
	// putnbr but unsigned
	else if (*format == 'x')
	// putnbrhex in lowercase (base 16)
	else if (*format == 'X')
	// putnbrhex in uppercase (base 16)
	return (0) // return count ?
}

int	ft_printf(const char *format, ...)
{
	va_list	list;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
			format++;
		if (*format)
			return (ft_switch(format));
	}	
	va_end(list);
	return(0); // return count ?
}
