/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:32:00 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 05:02:21 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_isexit(t_data *data)
{
	if (data->map[data->y_map / 64][data->x_map / 64] == 'E' &&
			data->collected == data->to_be_collect)
	{
		data->movecounter += 1;
		ft_printf("move counter = %d\n", data->movecounter);
		ft_error("YOU WIN");
	}
}

int	ft_finish(t_data *data)
{
	if (data->collected == data->to_be_collect)
		return (1);
	return (0);
}

void	ft_putbackground(t_data *data, int img, int nl, int exit)
{
	if (nl)
	{
		data->y += 64;
		data->x = -64;
	}
	else
	{
		if (exit)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img[2], data->x, data->y);
			if (ft_finish(data))
			{
				img = 10;
				mlx_put_image_to_window(data->mlx, data->win,
					data->img[img], data->x, data->y);
			}
		}
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[2], data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[img], data->x, data->y);
	}
}

void	set_background(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->backgroundline = -1;
	while (data->map[++data->backgroundline])
	{
		data->backgroundi = -1;
		while (data->map[data->backgroundline][++data->backgroundi])
		{
			if (data->map[data->backgroundline][data->backgroundi] == '1')
				ft_putbackground(data, 0, 0, 0);
			else if (data->map[data->backgroundline][data->backgroundi] == 'C')
				ft_putbackground(data, 3, 0, 0);
			else if (data->map[data->backgroundline][data->backgroundi] == 'E')
				ft_putbackground(data, 9, 0, 1);
			else if (data->map[data->backgroundline][data->backgroundi] == '\n')
				ft_putbackground(data, 0, 1, 0);
			else
				ft_putbackground(data, 2, 0, 0);
			data->x += 64;
		}
	}
}

char	**ft_read_map(int fd)
{
	int		i;
	char	*str;
	char	**map;

	i = 0;
	map = (char **)ft_calloc(sizeof(char), 9999);
	while (map)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		map[i] = str;
		i++;
	}
	map[i] = NULL;
	return (map);
}
