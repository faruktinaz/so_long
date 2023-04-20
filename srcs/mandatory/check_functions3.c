/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:37:14 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 02:08:40 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_enemy_check_wall(t_data *data, int i)
{
	if (data->map[data->enemy_y / 64][data->enemy_x / 64 + i] == '1' ||
		data->map[data->enemy_y / 64][data->enemy_x / 64 + i] == 'C' ||
			data->map[data->enemy_y / 64][data->enemy_x / 64 + i] == 'E')
		return (1);
	else if (data->map[data->enemy_y / 64][data->enemy_x / 64 + i] != '1' &&
			data->map[data->enemy_y / 64][data->enemy_x / 64 + i] != 'C' &&
				data->map[data->enemy_y / 64][data->enemy_x / 64 + i] != 'E')
		return (2);
	return (0);
}

void	ft_error(char *errormessage)
{
	ft_printf("\n****************************\n%s\n****************************\n\n",
		errormessage);
	exit(1);
}
