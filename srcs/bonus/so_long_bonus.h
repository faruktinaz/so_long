/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:31:50 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/25 23:51:07 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../library/42-printf/ft_printf.h"
# include "../../library/42-get_next_line/get_next_line.h"
# include "../../library/mlx/mlx.h"

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		**img;
	char		**map;
	char		**temp_map;
	int			collected;
	int			to_be_collect;
	int			loop2;
	int			loop;
	int			loop3;
	int			walk;
	int			line;
	int			index;
	int			movecounter;
	int			x;
	int			enemy;
	int			enemy_x;
	int			enemy_y;
	int			y;
	int			backgroundline;
	int			backgroundi;
	int			screen_x;
	int			screen_y;
	int			x_map;
	int			y_map;
}				t_data;

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *dst, size_t len);
void	*ft_memset(void *dst, int src, size_t n);
int		ft_mlx_start(t_data *data, char*map);
char	**ft_read_map(int fd);
void	screen_size_x_y(t_data *data);
void	set_background(t_data *data);
int		find_player_x_y(t_data *data);
void	ft_putbackground(t_data *data, int img, int nl, int exit);
int		ft_finish(t_data *data);
void	ft_isexit(t_data *data);
int		ft_check_player_exit(char **map);
int		ft_check_map_sides(char **map);
int		ft_check_line_len(char **map);
void	ft_collect(t_data *data);
int		ft_check_exit(char **map);
void	ft_check_map_value(char **temp_map, int x, int y);
void	ft_check_map_value_2(char **temp_map);
void	ft_checkerrors(t_data *data);
int		ft_check_enemy_line_count(char **map);
int		ft_enemy_check_wall(t_data *data, int i);
int		ft_check_items_characters(char **map);
int		key_event(int keycode, t_data *data);
void	ft_move_ud(t_data *data, int keycode);
void	ft_move_down(t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_lr(t_data *data, int keycode);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
int		render_loop_collectable(t_data *data);
int		ft_loop_player_sprites(t_data *data);
int		ft_enemy_sprites(t_data *data);
void	ft_putimage(t_data *data, int img, int x);
void	collectable_put(t_data *data, int x, int y, int i);
int		animation_character(t_data *data);
int		ft_len_collect(char **map);
void	screen_size_x_y(t_data *data);
void	ft_error(char *errormessage);
void	ft_add_imgs(t_data *data);
void	ft_collect(t_data *data);
void	ft_string_put(t_data *data);
void	ft_enemy_coordinates(t_data *data);
char	*ft_itoa(int n);

#endif