/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:43:36 by ogenc             #+#    #+#             */
/*   Updated: 2023/03/21 20:32:05 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len += ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			n = -(n);
			len += ft_putchar('-');
		}
		if (n > 9)
			len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += ft_putchar(n + '0');
	else
	{
		len += ft_putunbr(n / 10);
		len += ft_putunbr(n % 10);
	}
	return (len);
}
