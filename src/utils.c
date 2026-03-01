/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:10:11 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/22 16:26:49 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(void)
{
	static int		moves;

	ft_printf("Moves: %d\n", moves + 1);
	moves++;
}

void	dimensions(t_map *map)
{
	int	i;

	i = 0;
	map->map_width = 0;
	map->map_height = 0;
	while (map->map[i])
	{
		if (map->map[i] == '\n')
		{
			if (map->map_height == 0)
				map->map_width = i;
			map->map_height++;
		}
		i++;
	}
}

mlx_image_t	*load_img(t_map *map, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Error\nFailed to load textures!\n", 2);
		mlx_terminate(map->mlx_ptr);
		free_stuff(map);
		exit (1);
	}
	img = mlx_texture_to_image(map->mlx_ptr, texture);
	mlx_delete_texture(texture);
	return (img);
}

void	load_assets(t_map *map)
{
	map->_exit = load_img(map, "./images/hole.png");
	map->_collect = load_img(map, "./images/apple.png");
	map->_plr = load_img(map, "./images/fox.png");
	map->_background = load_img(map, "./images/Grass_Middle.png");
	map->_tree = load_img(map, "./images/Oak_Tree.png");
	if (!map->_exit || !map->_collect || !map->_plr || !map->_background
		|| !map->_tree)
	{
		ft_putstr_fd("Error\nFailed to load images!\n", 2);
		mlx_terminate(map->mlx_ptr);
		free_stuff(map);
		exit(1);
	}
}

void	free_stuff(t_map *map)
{
	int		i;

	if (map)
	{
		if (map->_map)
		{
			i = 0;
			while (map->_map[i])
				free(map->_map[i++]);
			free(map->_map);
		}
		if (map->map)
			free(map->map);
		free(map);
	}
}
