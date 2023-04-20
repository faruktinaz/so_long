/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:38:51 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 02:49:22 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_put_enemy(t_data *data, int i, int a)
{
	data->map[data->enemy_y / 64][(data->enemy_x / 64) + i] = 'X';
	data->map[data->enemy_y / 64][(data->enemy_x) / 64] = '0';
	data->enemy_x += (64 * i);
	mlx_put_image_to_window(data->mlx, data->win, data->img[16 + (a * i)],
		data->enemy_x, data->enemy_y);
}

int	ft_enemy_sprites(t_data *data)
{
	static int	x = 1;
	static int	i = 1;
	static int	a = 1;

	while (++x < 3000)
		return (0);
	if (ft_enemy_check_wall(data, i) == 2)
	{
		ft_put_enemy(data, i, a);
		a++;
		if (a == 3)
			a = 1;
	}
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img[16],
			data->enemy_x, data->enemy_y);
	if (ft_enemy_check_wall(data, i) == 1)
		i = -(i);
	if (data->map[data->y_map / 64][data->x_map / 64] == 'X')
		ft_error("GAME OVER YOU DEAD");
	x = 0;
	return (1);
}

int	find_player_x_y(t_data *data)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (data->map[line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == 'P')
			{
				data->x_map = i * 64;
				data->y_map = line * 64;
			}
		}
		line++;
	}
	return (0);
}

void	screen_size_x_y(t_data *data)
{
	int	x;
	int	y;

	x = ft_strlen(data->map[0]) - 1;
	y = 0;
	while (data->map[y])
			y++;
	data->screen_x = x * 64;
	data->screen_y = y * 64;
}
