/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:19:56 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 02:01:01 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_check_player_exit(char **map)
{
	int	line;
	int	i;
	int	p;
	int	e;

	line = -1;
	p = 0;
	e = 0;
	while (map[++line])
	{
		i = -1;
		while (map[line][++i])
		{
			if (map[line][i] == 'E')
				e++;
			else if (map[line][i] == 'P')
				p++;
		}
	}
	if (p != 1 || e != 1)
		return (0);
	return (1);
}

int	ft_check_line_len(char **map)
{
	int	line;
	int	i;
	int	len;

	line = 0;
	len = 0;
	while (map[len])
		len++;
	if (len > 30)
		ft_error("MAP LENGHT ERROR");
	i = ft_strlen(map[len - 1]);
	if (i > 70)
		ft_error("MAP LENGHT ERROR");
	while (len - 1 > line)
	{
		if (ft_strlen(map[line]) - 1 != i)
			return (0);
		line++;
	}
	return (1);
}

int	ft_check_map_sides(char **map)
{
	int	i;
	int	line;

	line = 0;
	i = -1;
	while (map[line][++i] != '\n')
	{
		if (map[line][i] != '1')
			return (0);
	}
	i = -1;
	while (map[++line])
	{
		if (map[line][0] != '1')
			return (0);
		if (map[line][ft_strlen(map[line]) - 2] != '1')
			return (0);
	}
	while (map[line - 1][++i])
	{
		if (map[line - 1][i] != '1')
			return (0);
	}
	return (1);
}

void	ft_check_map_value(char **temp_map, int x, int y)
{
	temp_map[y][x] = '.';
	if (temp_map[y][x - 1] != '1' && temp_map[y][x - 1] != '.')
		ft_check_map_value(temp_map, x - 1, y);
	if (temp_map[y + 1][x] != '1' && temp_map[y + 1][x] != '.')
		ft_check_map_value(temp_map, x, y + 1);
	if (temp_map[y - 1][x] != '1' && temp_map[y - 1][x] != '.')
		ft_check_map_value(temp_map, x, y - 1);
	if (temp_map[y][x + 1] != '1' && temp_map[y][x + 1] != '.')
		ft_check_map_value(temp_map, x + 1, y);
	else
		temp_map[y][x] = '.';
}

void	ft_check_map_value_2(char **temp_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp_map[i])
	{
		while (temp_map[i][j] != '\0')
		{
			if (temp_map[i][j] == 'E' || temp_map[i][j] == 'C' \
					|| temp_map[i][j] == 'P')
				ft_error("MAP ERROR! MAP INVALID");
			j++;
		}
		j = 0;
		i++;
	}
}
