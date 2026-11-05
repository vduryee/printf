/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:14 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/05 17:03:23 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch(char type, va_list args, int count)
{
	if (type == 'c')
		count += ft_putchar(va_arg(args, int), count);
	if (type == 's')
		count += ft_putstr(va_arg(args, char *), count);
	if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int), count);
	if (type == 'u')
	// putnbr but unsigned
	if (type == 'p')
	// print void pointer in hex
	if (type == 'x')
	// putnbr hex lowercase
	if (type == 'X')
	// putnbr hex uppercase
	if (type == '%')
		count += ft_putchar('%', 1);
	return (count);
}

// handle the number of %, if !pair, error

int ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += (ft_switch(format[i + 1], args, count));
			i++;
		}
		i++;
	}
	va_end (args);
	return (count);
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