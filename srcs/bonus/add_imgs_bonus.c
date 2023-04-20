/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_imgs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:31:39 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 03:21:31 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_add_imgs2(t_data *data, int x, int y)
{
	data->img[7] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/characterright.xpm", &x, &y);
	data->img[8] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/characterleft.xpm", &x, &y);
	data->img[9] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/exit.xpm", &x, &y);
	data->img[10] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/deadbodydoor.xpm", &x, &y);
	data->img[11] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/characteranimation1.xpm", &x, &y);
	data->img[12] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/characteranimation2.xpm", &x, &y);
	data->img[13] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/characteranimation3.xpm", &x, &y);
	data->img[14] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/enemy3.xpm", &x, &y);
	data->img[15] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/enemy4.xpm", &x, &y);
	data->img[16] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/enemy.xpm", &x, &y);
	data->img[17] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/enemy1.xpm", &x, &y);
	data->img[18] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/enemy2.xpm", &x, &y);
}

void	ft_add_imgs(t_data *data)
{
	int	y;
	int	x;

	data->img = ft_calloc(sizeof(void *), 19);
	data->img[1] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/character.xpm", &x, &y);
	data->img[0] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/wood.xpm", &x, &y);
	data->img[2] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/wood4.xpm", &x, &y);
	data->img[3] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/collectup.xpm", &x, &y);
	data->img[4] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/collectleft.xpm", &x, &y);
	data->img[5] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/collectdown.xpm", &x, &y);
	data->img[6] = mlx_xpm_file_to_image(data->mlx,
			"./srcs/img/collectright.xpm", &x, &y);
	ft_add_imgs2(data, x, y);
}
