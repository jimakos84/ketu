/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:04:51 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/23 12:35:57 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# define TS 64

typedef struct s_map
{
	char			*map;
	char			**_map;
	int				found_col;
	int				col;
	int				player;
	int				found_exit;
	int				exit;
	int				player_x;
	int				player_y;
	int				map_width;
	int				map_height;
	mlx_image_t		*_tree;
	mlx_image_t		*_background;
	mlx_image_t		*_plr;
	mlx_image_t		*_collect;
	mlx_image_t		*_exit;
	void			*mlx_ptr;
}	t_map;

	//--------MAP VALIDATION--------//

void	file_valid(char *filename, t_map *map);
void	map_parsing(char *argv, t_map *map);
void	is_rectangular(t_map *map);
void	is_horizontal_wall(t_map *map, char **array);
void	check_vertical_wall(char **lines, t_map *map, int error);
void	free_n_more_check(char **lines, t_map *map);
void	invalid_map(t_map *map, char **copy_map, char c);
void	correct_symbols(t_map *map, char **copy_map);
void	flood_fill(int x, int y, char **copy_map, t_map *map);
void	is_playable(t_map *map);

	//--------GAME--------//

void	start_game(t_map *map);
void	draw_map(t_map *map);
void	draw_player(t_map *map);

	//--------UTILS--------//

void	player_position(t_map *map, char **copy_map);
void	print_moves(void);
void	dimensions(t_map *map);
void	checkreso(t_map *map);
void	load_assets(t_map *map);
void	free_stuff(t_map *map);
void	_error(t_map *map, char c, char *line, int fd);
void	free_gnl_leftovers(int fd);
void	count_newlines(t_map *map, char **_map);

#endif
