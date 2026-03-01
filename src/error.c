/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:41:26 by dvlachos          #+#    #+#             */
/*   Updated: 2025/02/23 12:42:59 by dvlachos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_error(t_map *map, char c, char *line, int fd)
{
	if (c == 'S')
		ft_putstr_fd("Error\nString Join failed!\n", 2);
	if (c == 'T')
		ft_putstr_fd("Error\nSplit failed!\n", 2);
	if (line)
		free(line);
	if (fd > 0)
		free_gnl_leftovers(fd);
	free_stuff(map);
	exit (1);
}

void	free_gnl_leftovers(int fd)
{
	char	*xd;

	xd = get_next_line(fd);
	while (xd)
	{
		free(xd);
		xd = get_next_line(fd);
	}
	if (xd)
		free(xd);
	if (fd)
		close(fd);
}

void	count_newlines(t_map *map, char **_map)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		if (map->map[i] == '\n')
			count++;
		i++;
	}
	i = 0;
	while (map && _map[i])
	{
		i++;
	}
	if (i != count)
	{
		invalid_map(map, _map, 'R');
	}
}
