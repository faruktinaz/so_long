/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:38:15 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 13:49:24 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_enemy_coordinates(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == 'X')
			{
				data->enemy_x = i * 64;
				data->enemy_y = line * 64;
			}
		}
	}
}

static	int	numlen(int num)
{
	int	count;

	count = 0;
	if (num < 0 || num == 0)
		count++;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*itoanext(char *number, int n, int len)
{
	if (number[len - 1] == '8')
	{
		len = len - 1;
	}
	while (n)
	{
		number[len-- -1] = (n % 10) + '0';
		n /= 10;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	len = numlen(n);
	number = malloc (1 * len + 1);
	if (!number)
		return (NULL);
	if (n == 0)
		number[0] = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			number[len - 1] = '8';
			n /= 10;
		}
		number[0] = '-';
		n = -(n);
	}
	number[len] = '\0';
	itoanext(number, n, len);
	return (number);
}

void	ft_string_put(t_data *data)
{
	char	*step;

	step = ft_itoa(data->movecounter);
	mlx_string_put(data->mlx, data->win, 5, 20, 0xffff99, "step: ");
	mlx_string_put(data->mlx, data->win, 45, 20, 0xffff99, step);
	free(step);
}
