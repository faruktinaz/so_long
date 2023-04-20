/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:39 by ogenc             #+#    #+#             */
/*   Updated: 2023/01/11 03:22:46 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printpointer(unsigned long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_printpointer(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_hexprint(char c, unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb >= 16)
		len += ft_hexprint(c, nb / 16);
	if (c == 'x')
		len += ft_putchar("0123456789abcdef"[nb % 16]);
	else if (c == 'X')
		len += ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (len);
}

int	ft_type(char c, va_list arr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arr, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arr, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(arr, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_printpointer(va_arg(arr, unsigned long int)) + 2);
	}
	else if (c == 'x' || c == 'X')
		return (ft_hexprint(c, va_arg(arr, unsigned int)));
	return (0);
}

int	ft_printf(const char *sign, ...)
{
	va_list	arr;
	int		i;
	int		len;

	va_start(arr, sign);
	i = 0;
	len = 0;
	while (sign[i])
	{
		if (sign[i] == '%')
		{
			len += ft_type(sign[i + 1], arr);
			i++;
		}
		else
			len += write(1, &sign[i], 1);
		i++;
	}
	va_end(arr);
	return (len);
}
