/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:31:46 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 16:03:46 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

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

int	xbutton(t_data *data)
{
	(void)data;
	ft_error("GAME CLOSED");
	return (0);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_error("GAME CLOSED");
	else if (keycode == 2)
		ft_move_lr(data, keycode);
	else if (keycode == 0)
		ft_move_lr(data, keycode);
	else if (keycode == 1)
		ft_move_ud(data, keycode);
	else if (keycode == 13)
		ft_move_ud(data, keycode);
	return (0);
}

int	ft_loop_function(t_data *data)
{
	render_loop_collectable(data);
	animation_character(data);
	if (data->enemy == 1)
		ft_enemy_sprites(data);
	ft_loop_player_sprites(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 99);
	if (argc == 2)
	{
		ft_mlx_start(data, argv[1]);
		data->to_be_collect = ft_len_collect(data->map);
		set_background(data);
		find_player_x_y(data);
		ft_enemy_coordinates(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img[1],
			data->x_map, data->y_map);
		mlx_hook(data->win, 17, 0, xbutton, data);
		mlx_hook(data->win, 2, 1L << 0, key_event, data);
		mlx_loop(data->mlx);
	}
	else
	{
		free(data);
		ft_error("ERROR INVALID SYTAX");
	}
	return (0);
}
