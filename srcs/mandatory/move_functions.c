/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:19:40 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 05:00:31 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_move_left(t_data *data)
{
	data->x_map -= 64;
	if (data->map[data->y_map / 64][data->x_map / 64] == '1')
		data->x_map += 64;
	else
	{
		ft_putimage(data, 1, 0);
		data->movecounter += 1;
		ft_printf("move counter = %d\n", data->movecounter);
	}
}

void	ft_move_right(t_data *data)
{
	data->x_map += 64;
	if (data->map[data->y_map / 64][data->x_map / 64] == '1')
		data->x_map -= 64;
	else
	{
		ft_putimage(data, 1, 0);
		data->movecounter += 1;
		ft_printf("move counter = %d\n", data->movecounter);
	}
}

void	ft_move_lr(t_data *data, int keycode)
{
	if (keycode == 0)
		ft_move_left(data);
	else if (keycode == 2)
		ft_move_right(data);
}

void	ft_move_down(t_data *data)
{
	data->y_map -= 64;
	if (data->map[data->y_map / 64][data->x_map / 64] == '1')
		data->y_map += 64;
	else
	{
		ft_putimage(data, 1, 0);
		data->movecounter += 1;
		ft_printf("move counter = %d\n", data->movecounter);
	}
}

void	ft_move_ud(t_data *data, int keycode)
{
	if (keycode == 1)
	{
		data->y_map += 64;
		if (data->map[data->y_map / 64][data->x_map / 64] == '1')
			data->y_map -= 64;
		else
		{
			ft_putimage(data, 1, 0);
			data->movecounter += 1;
			ft_printf("move counter = %d\n", data->movecounter);
		}
	}
	else if (keycode == 13)
		ft_move_down(data);
}
