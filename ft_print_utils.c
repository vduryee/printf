/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduryee <vduryee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:43:23 by vduryee           #+#    #+#             */
/*   Updated: 2026/11/05 16:27:05 by vduryee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar (char c, int count)
{
	ft_putchar_fd(c, 1);
	return (count + 2);
}

int ft_putstr (char *str, int count)
{
	int	len;

	len = ft_strlen(str) + 1;
	ft_putstr_fd(str, 1);
	return (count + len);
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (count + 12);
	}
	if (n < 0)
	{
		ft_putchar('-', 1);
		n = n * -1;
	}
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0', 1);
	}
	else
	{
		ft_putnbr(n / 10, 1);
		ft_putnbr(n % 10, 1);
		count++;
	}
	return (count);
}