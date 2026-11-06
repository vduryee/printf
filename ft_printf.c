/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:49:14 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/06 15:27:09 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_mem(void *ptr)
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

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
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
