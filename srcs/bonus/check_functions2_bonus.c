/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:59:12 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 13:00:40 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_checkerrors(t_data *data)
{
	if (!data->map[0])
		ft_error("ERROR MAP NOT FOUND");
	else if (ft_check_map_sides(data->map) == 0)
		ft_error("MAP ERROR !  WALLS PLACED INCORRECT");
	else if (ft_check_line_len(data->map) == 0)
		ft_error("MAP ERROR !  MAP LENGHT MUST BE SAME");
	else if (ft_check_player_exit(data->map) == 0)
		ft_error("MAP ERROR !  EXIT OR PLAYER MUST BE EQUAL TO 1");
	else if (ft_len_collect(data->map) == 0)
		ft_error("MAP ERROR ! NO COLLECTABLE");
	else if (ft_check_items_characters(data->map) == 0)
		ft_error("MAP ERROR ! UNKNOWN CHARACTER IN MAP");
	else if (ft_check_enemy_line_count(data->map) == 0)
		ft_error("MAP EROOR ! ENEMY MUST BE 1");
	ft_check_map_value(data->temp_map, 1, 1);
	ft_check_map_value_2(data->temp_map);
}

int	ft_check_enemy_line_count(char **map)
{
	int	i;
	int	line;
	int	enemy_count;

	line = -1;
	while (map[++line])
	{
		enemy_count = 0;
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'X')
				enemy_count++;
		}
		if (enemy_count > 1)
			return (0);
	}
	return (1);
}

int	ft_check_items_characters(char **map)
{
	int	i;
	int	line;
	int	result;

	line = -1;
	result = 0;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == '1' || map[line][i] == 'C' ||
					map[line][i] == '\n')
				result++;
			else if (map[line][i] == 'E' || map[line][i] == 'X')
				result++;
			else if (map[line][i] == 'P' || map[line][i] == '0')
				result++;
			else
				return (0);
		}
	}
	return (result);
}

int	ft_len_collect(char **map)
{
	int	i;
	int	line;
	int	lencollect;

	line = 0;
	lencollect = 0;
	while (map[line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'C')
				lencollect++;
		}
		line++;
	}
	return (lencollect);
}

int	ft_check_exit(char **map)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (map[line][i] != 'E' && map[line])
	{
		if (map[line][i] == '\n')
			line++;
		else
			i++;
	}
	if (map[line][i - 1] == '1' && map[line][i + 1] == '1' &&
			map[line + 1][i] == '1' && map[line - 1][i] == '1')
		return (0);
	return (1);
}
