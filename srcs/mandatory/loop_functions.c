/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:44:38 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 01:35:12 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_putimage(t_data *data, int img, int x)
{
	ft_collect(data);
	ft_isexit(data);
	set_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[img],
		data->x_map - x, data->y_map);
}

void	collectable_put(t_data *data, int x, int y, int i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img[2],
		x * 64, y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->img[i],
		x * 64, y * 64);
}

int	render_loop_collectable(t_data *data)
{
	static int	i = 4;

	if (data->loop < 2000)
	{
		data->loop++;
		return (0);
	}
	data->loop = 0;
	data->line = -1;
	while (data->map[++data->line])
	{
		data->index = -1;
		while (data->map[data->line][++data->index])
		{
			if (data->map[data->line][data->index] == 'C')
				collectable_put(data, data->index, data->line, i);
		}
	}
	if (i == 6)
		i = 2;
	i++;
	return (0);
}

int	ft_loop_player_sprites(t_data *data)
{
	if (data->walk == 1)
	{
		if (data->loop2 < 2000)
		{
			data->loop2++;
			return (0);
		}
		ft_putimage(data, 1, 0);
		data->loop2 = 0;
		data->walk = 0;
	}
	return (1);
}

int	animation_character(t_data *data)
{
	static int	i = 11;

	if (data->loop3 < 3000)
	{
		data->loop3++;
		return (0);
	}
	data->loop3 = 0;
	set_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[i],
		data->x_map, data->y_map);
	if (i == 13)
		i = 10;
	i++;
	return (1);
}
