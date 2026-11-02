/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:14 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/02 17:51:22 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch (char *format)
{
	if (*format == '%')
		ft_putchar_fd(*format, 1);
	else if (*format == 'c')
		ft_putchar_fd((*format + 1) , 1);
	else if (*format == 's')
		ft_putstr_fd(format + 1, 1);
	else if (*format == 'p')
	;// print pointer in hex (must print (nil) 0x in front)
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(*format, 1);
	else if (*format == 'u')
	;// putnbr but unsigned
	else if (*format == 'x')
	;// putnbrhex in lowercase (base 16)
	else if (*format == 'X')
	;// putnbrhex in uppercase (base 16)
	return (0); // return count ?
}

int	ft_printf(const char *format, ...)
{
	va_list	list;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
			format++;
		if (*format && (*format + 1) == '\0')
			return (ft_switch(format));
		else
			ft_putchar_fd(*format, 1);
		format++;
	}	
	va_end(list);
	return(0); // return count ?
}
int main ()
{
	int nb = 123;
	char ch = 'a';
	char str[] = "Hello World";
	ft_printf("Number: %d\n", nb);
	ft_printf("Char: %c\n", ch);
	ft_printf("String: %s\n", str);
	return 0;
}