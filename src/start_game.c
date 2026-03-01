/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:30:16 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/23 08:53:35 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ketu_ate(t_map *map)
{
	ft_printf("🦊 WINNER 🍎\n");
	mlx_terminate(map->mlx_ptr);
	free_stuff(map);
	exit (0);
}

static void	eat_apples(t_map *map)
{
	int		i;

	i = 0;
	if (map->_map[map->player_y][map->player_x] == 'C')
	{
		map->_map[map->player_y][map->player_x] = '0';
		while (i < map->col)
		{
			if (map->_collect->instances[i].x == map->player_x * TS
				&& map->_collect->instances[i].y == map->player_y * TS)
				map->_collect->instances[i].enabled = false;
			i++;
		}
		map->found_col--;
	}
}

static void	player_movement(t_map *map, char direction)
{
	if (direction == 'R')
	{
		map->player_x += 1;
		map->_plr->instances[0].x += TS;
	}
	if (direction == 'L')
	{
		map->player_x -= 1;
		map->_plr->instances[0].x -= TS;
	}
	if (direction == 'U')
	{	
		map->player_y -= 1;
		map->_plr->instances[0].y -= TS;
	}
	if (direction == 'D')
	{
		map->player_y += 1;
		map->_plr->instances[0].y += TS;
	}
	if (map->_map[map->player_y][map->player_x] == 'C')
		eat_apples(map);
	if (map->_map[map->player_y][map->player_x] == 'E' && map->found_col == 0)
		ketu_ate(map);
	print_moves();
}

static void	hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->mlx_ptr);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (map->_map[map->player_y][map->player_x + 1] != '1')
			player_movement(map, 'R');
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (map->_map[map->player_y][map->player_x - 1] != '1')
			player_movement(map, 'L');
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (map->_map[map->player_y - 1][map->player_x] != '1')
			player_movement(map, 'U');
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{	
		if (map->_map[map->player_y + 1][map->player_x] != '1')
			player_movement(map, 'D');
	}
}

void	start_game(t_map *map)
{
	dimensions(map);
	map->mlx_ptr = mlx_init(1, 1, "fake", false);
	checkreso(map);
	mlx_terminate(map->mlx_ptr);
	map->mlx_ptr = mlx_init(map->map_width * TS,
			map->map_height * TS, "KETU", true);
	if (!map->mlx_ptr)
	{
		ft_putstr_fd("ERRORRRRR", 2);
		free(map->map);
		free(map);
		exit(1);
	}
	load_assets(map);
	draw_map(map);
	draw_player(map);
	mlx_key_hook(map->mlx_ptr, hook, map);
	mlx_loop(map->mlx_ptr);
	mlx_terminate(map->mlx_ptr);
	free_stuff(map);
}
