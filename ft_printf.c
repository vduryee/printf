/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:14 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/05 18:17:19 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_switch(char type, va_list args, int count)
{
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *), count);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int), count);
	else if (type == '%')
		count += ft_putchar('%');
	else if (type == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	// else if (type == 'p')
	// // print void pointer in hex
	// else if (type == 'x')
	// // putnbr hex lowercase
	// else if (type == 'X')
	// // putnbr hex uppercase
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
			ft_putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			count = (ft_switch(format[i + 1], args, count));
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
	unsigned int unb = 2147483648;
	char ch = 'a';
	char str[] = "Hello World";
	ft_printf("Number: %d\n", nb);
	ft_printf("Char: %c\n", ch);
	ft_printf("String: %s\n", str);
	ft_printf("Unsigned: %u\n", unb);
	ft_printf("---------------------\n");
	int test = ft_printf("Percent: %%\n");
	int test2 = printf("Percent: %%\n");
	ft_printf("%d\n", test);
	ft_printf("%d\n", test2);
	printf("%d\n", test);
	printf("%d\n", test2);
	return 0;
}