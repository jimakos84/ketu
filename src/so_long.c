/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:04:21 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/16 13:59:52 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map)
{
	map->map = NULL;
	map->_map = NULL;
	map->found_col = 0;
	map->col = 0;
	map->player = 0;
	map->found_exit = 0;
	map->exit = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->map_width = 0;
	map->map_height = 0;
	map->_tree = NULL;
	map->_background = NULL;
	map->_plr = NULL;
	map->_collect = NULL;
	map->_exit = NULL;
	map->mlx_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error!\nMalloc failed!\n", 2);
		exit (1);
	}
	initialize_map(map);
	if (argc != 2)
	{
		write(2, "Error: ", 7);
		ft_printf("Incorrect Execution. Format: ./so_long  <map.ber>\n");
		return (1);
	}
	file_valid(argv[1], map);
	map_parsing(argv[1], map);
	return (0);
}
