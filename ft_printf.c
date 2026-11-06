/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:14 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/06 12:27:20 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int ft_print_mem(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_hex((unsigned long int)ptr, 'x');
	return (count);
}

static int	ft_switch(char type, va_list args, int count)
{
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type == '%')
		count += ft_putchar('%');
	else if (type == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (type == 'p')
		count += ft_print_mem(va_arg(args, void *));
	else if (type == 'x' || type == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), type);
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

// int main ()
// {
// 	int nb = 10354321;
// 	unsigned int unb = 2147483648;
// 	char ch = 'a';
// 	char str[] = "Hello World";
// 	void *ptr = "";
// 	ft_printf("Number: %d\n", nb);
// 	ft_printf("Char: %c\n", ch);
// 	ft_printf("String: %s\n", str);
// 	ft_printf("Percent: %%\n");
// 	ft_printf("Unsigned: %u\n", unb);
// 	ft_printf("Lowercase hex: %x\n", nb);
// 	ft_printf("Uppercase hex: %X\n", nb);
// 	ft_printf("Null pointer: %p\n", ptr);
// 	// printf("Null pointer: %p\n", ptr);
// 	ft_printf("---------------------\n");
// 	// int test = ft_printf("Number: %i\n", nb);
// 	// int test = ft_printf("Char: %c\n", ch);
// 	// int test = ft_printf("String: %s\n", str);
// 	// int test = ft_printf("Percent: %%\n");
// 	// int test = ft_printf("Unsigned: %u\n", unb);
// 	// int test = ft_printf("Lowercase hex: %x\n", nb);
// 	// int test = ft_printf("Uppercase hex: %X\n", nb);
// 	int test = ft_printf("Null pointer: %p\n", ptr);
// 	// int test2 = printf("Number: %i\n", nb);
// 	// int test2 = printf("Char: %c\n", ch);
// 	// int test2 = printf("String: %s\n", str);
// 	// int test2 = printf("Percent: %%\n");
// 	// int test2 = printf("Unsigned: %u\n", unb);
// 	// int test2 = printf("Lowercase hex: %x\n", nb);
// 	// int test2 = printf("Uppercase hex: %X\n", nb);
// 	int test2 = printf("Null pointer: %p\n", ptr);
// 	ft_printf("%d\n", test);
// 	ft_printf("%d\n", test2);
// 	printf("%d\n", test);
// 	printf("%d\n", test2);
// 	return 0;
// }
