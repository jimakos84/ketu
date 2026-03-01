/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:48:52 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/23 09:19:47 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	correct_symbols(t_map *map, char **copy_map)
{
	int		i;
	char	*map_str;

	map_str = map->map;
	i = 0;
	while (map_str[i])
	{
		if (map_str[i] == '1' || map_str[i] == '0' || map_str[i] == 'C'
			|| map_str[i] == 'P' || map_str[i] == 'E'
			|| map_str[i] == '\n')
			i++;
		else
		{
			ft_putstr_fd("Error\nMap: Some wrong symbols in the map!\n", 2);
			invalid_map(map, copy_map, 0);
		}
	}
}

void	checkreso(t_map *map)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	mlx_get_monitor_size(0, &width, &height);
	if (width < map->map_width * TS || height < map->map_height * TS)
	{
		mlx_terminate(map->mlx_ptr);
		ft_putstr_fd("Error\nMap: Too big map\n", 2);
		invalid_map(map, map->_map, 0);
	}
}
