/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:31:41 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 03:21:47 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	argv_checker(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv[i - 3] == '.')
		return (1);
	return (0);
}

int	ft_mlx_start(t_data *data, char*map)
{
	int	fd;
	int	fd2;

	if (argv_checker(map))
	{
		fd = open(map, O_RDONLY);
		fd2 = open(map, O_RDONLY);
	}
	else
	{
		ft_error("ERROR");
		return (0);
	}
	data->map = ft_read_map(fd);
	data->temp_map = ft_read_map(fd2);
	ft_checkerrors(data);
	data->mlx = mlx_init();
	ft_add_imgs(data);
	screen_size_x_y(data);
	data->win = mlx_new_window(data->mlx, data->screen_x, \
			data->screen_y, "so_long");
	return (0);
}
