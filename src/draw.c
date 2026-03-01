/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:30:16 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/21 19:24:27 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (map->_map && map->_map[y])
	{
		while (map->_map[y][x])
		{
			mlx_image_to_window(map->mlx_ptr, map->_background,
				x * TS, y * TS);
			if (map->_map[y][x] == '1')
				mlx_image_to_window(map->mlx_ptr, map->_tree, x * TS, y * TS);
			else if (map->_map[y][x] == 'C')
				mlx_image_to_window(map->mlx_ptr, map->_collect,
					x * TS, y * TS);
			else if (map->_map[y][x] == 'E')
				mlx_image_to_window(map->mlx_ptr, map->_exit, x * TS, y * TS);
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_player(t_map *map)
{
	mlx_image_to_window(map->mlx_ptr, map->_plr,
		map->player_x * TS, map->player_y * TS);
}
