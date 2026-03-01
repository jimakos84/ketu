/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 10:23:18 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/23 09:14:27 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parsing(char *argv, t_map *map)
{
	int				fd;
	char			*line;
	char			*temp;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		invalid_map(map, NULL, 'E');
	map->map = line;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			temp = ft_strjoin(map->map, line);
			if (!temp)
				_error(map, 'S', line, fd);
			free(map->map);
			map->map = temp;
			free(line);
		}
	}
	is_rectangular(map);
}

void	is_rectangular(t_map *map)
{
	static size_t	len;
	int				i;
	static int		error;
	char			**array;

	error = 0;
	i = 0;
	array = ft_split(map->map, '\n');
	if (!array)
		_error(map, 'T', NULL, -1);
	count_newlines(map, array);
	len = ft_strlen(array[i]);
	while (array && array[i])
	{
		if (len != ft_strlen(array[i]))
			error = 1;
		i++;
	}
	if (error)
		invalid_map(map, array, 'R');
	is_horizontal_wall(map, array);
}

void	is_horizontal_wall(t_map *map, char **lines)
{
	int				line_num;
	int				i;
	static int		error;

	error = 0;
	i = 0;
	line_num = 0;
	while (lines[line_num])
		line_num++;
	while (lines[0][i])
	{
		if (lines[0][i] != '1')
			error = 1;
		i++;
	}
	i = 0;
	while (lines[line_num - 1][i])
	{
		if (lines[line_num - 1][i] != '1')
			error = 1;
		i++;
	}
	check_vertical_wall(lines, map, error);
}

void	check_vertical_wall(char **lines, t_map *map, int error)
{
	int			i;
	size_t		line_len;

	i = 0;
	line_len = ft_strlen(lines[i]);
	if (error == 1)
		invalid_map(map, lines, 'H');
	while (lines && lines[i])
	{
		if (lines[i][0] != '1' || lines[i][line_len - 1] != '1')
			invalid_map(map, lines, 'V');
		i++;
	}
	free_n_more_check(lines, map);
}

void	free_n_more_check(char **lines, t_map *map)
{
	int		i;
	char	*layout;

	layout = map->map;
	i = 0;
	i = 0;
	map->found_col = 0;
	map->found_exit = 0;
	map->col = 0;
	map->player = 0;
	map->exit = 0;
	while (layout[i])
	{
		if (layout[i] == 'P')
			map->player++;
		if (layout[i] == 'C')
			map->col++;
		if (layout[i] == 'E')
			map->exit++;
		i++;
	}
	if (map->player != 1 || map->col < 1 || map->exit != 1)
		invalid_map(map, lines, 'A');
	correct_symbols(map, lines);
	player_position(map, lines);
}
