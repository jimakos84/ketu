/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:28:41 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/23 09:20:49 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_valid(char *filename, t_map *map)
{
	int		len;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Invalid file\n", 2);
		if (map)
			free(map);
		exit (1);
	}
	else
		close(fd);
	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + len - 4, ".ber", 4)
		|| !ft_strncmp(filename + len - 5, "/.ber", 5))
	{
		ft_putstr_fd("Invalid file!\n", 2);
		if (map)
			free(map);
		exit(1);
	}
}

void	invalid_map(t_map *map, char **copy_map, char c)
{
	int		i;

	i = 0;
	if (c == 'H')
		ft_putstr_fd("Error\nMap: Horizontal wall open!\n", 2);
	if (c == 'A')
		ft_putstr_fd("Error\nMap: Incorrect amount of assets!\n", 2);
	if (c == 'V')
		ft_putstr_fd("Error\nMap: Vertical wall open!\n", 2);
	if (c == 'E')
		ft_putstr_fd("Error\nMap: Empty map file!\n", 2);
	if (c == 'R')
		ft_putstr_fd("Error\nMap: Not rectangular!\n", 2);
	if (c == 'X')
		ft_putstr_fd("Error\nMap: Exit or collectible not reachable!\n", 2);
	while (copy_map && copy_map[i])
		free(copy_map[i++]);
	if (copy_map)
		free(copy_map);
	if (map->map)
		free(map->map);
	if (map)
		free(map);
	exit (1);
}

void	player_position(t_map *map, char **copy_map)
{
	int		i;

	i = 0;
	map->player_x = 0;
	map->player_y = 0;
	while (map->map && map->map[i])
	{
		if (map->map[i] == 'P')
			break ;
		map->player_x++;
		if (map->map[i] == '\n')
		{
			map->player_x = 0;
			map->player_y++;
		}
		i++;
	}
	i = 0;
	flood_fill(map->player_x, map->player_y, copy_map, map);
	while (copy_map && copy_map[i])
		free(copy_map[i++]);
	free(copy_map);
	is_playable(map);
}

void	flood_fill(int x, int y, char **copy_map, t_map *map)
{
	if (x == 0 || y == 0 || copy_map[y][x] == '1' || copy_map[y][x] == 'X')
		return ;
	if (copy_map[y][x] == 'C')
		map->found_col++;
	if (copy_map[y][x] == 'E')
		map->found_exit++;
	copy_map[y][x] = 'X';
	flood_fill(x + 1, y, copy_map, map);
	flood_fill(x - 1, y, copy_map, map);
	flood_fill(x, y + 1, copy_map, map);
	flood_fill(x, y - 1, copy_map, map);
}

void	is_playable(t_map *map)
{
	if (map->col == map->found_col && map->exit == map->found_exit)
	{	
		map->_map = ft_split(map->map, '\n');
		if (!map->_map)
			_error(map, 'T', NULL, -1);
		start_game(map);
	}
	else
		invalid_map(map, NULL, 'X');
}
