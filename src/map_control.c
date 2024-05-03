/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:16 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/28 02:50:05 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../libft/libft.h"

void	character_control(t_data *cub, int i, int j, int k)
{
	while (i < cub->line - 2 && cub->map[i])
	{
		j = 0;
		while (cub->map[i][j] != '\n')
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				k++;
				cub->direction = cub->map[i][j];
				cub->character_x = j;
				cub->character_y = i;
			}
			else if (!(cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E'
					|| cub->map[i][j] == '0' || cub->map[i][j] == '1'
						|| cub->map[i][j] <= 32))
				err_msg(cub, "Error: foreign character in map\n", 3);
			j++;
		}
		i++;
	}
	if (k != 1)
		err_msg(cub, "Error: There must be only one player\n", 3);
}

char	**copy_map(t_data *cub)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * cub->line);
	if (!map)
		err_msg(cub, "Error: Malloc Error\n", 3);
	while (i < cub->line && cub->map[i])
	{
		map[i] = ft_strdup(cub->map[i]);
		if (!map[i])
		{
			ft_free_n(map, i);
			err_msg(cub, "Error: Malloc Error\n", 3);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	path_finder(char **map, int y, int x, t_data *c)
{
	map[y][x] = '1';
	if (map[y + 1][x] != '1')
	{
		if (map[y + 1][x] == 10 || map[y + 1][x] <= 32 || y + 1 == c->line - 2)
			err_msg(c, "Error: Map Error\n", 4);
		path_finder(map, y + 1, x, c);
	}
	if (map[y - 1][x] != '1')
	{
		if (map[y - 1][x] == '\n' || map[y - 1][x] <= 32 || y - 1 == 0)
			err_msg(c, "Error: Map Error\n", 4);
		path_finder(map, y - 1, x, c);
	}
	if (map[y][x + 1] != '1')
	{
		if (map[y][x + 1] == '\n' || map[y][x + 1] <= 32)
			err_msg(c, "Error: Map Error\n", 4);
		path_finder(map, y, x + 1, c);
	}
	if (map[y][x - 1] != '1')
	{
		if (map[y][x - 1] == '\n' || map[y][x - 1] <= 32)
			err_msg(c, "Error: Map Error\n", 4);
		path_finder(map, y, x - 1, c);
	}
}

void	wall_control(t_data *cub, int i, int j, int a)
{
	int	b;

	while (cub->tmp_map[i])
	{
		j = 0;
		while (cub->tmp_map[i][j] != '\n' && cub->tmp_map[i][j])
		{
			if (cub->tmp_map[i][j] == '0')
			{
				if (i == 0 || i == cub->line - 2)
					err_msg(cub, "Error: map is not covered with walls\n", 4);
				a = ft_strlen(cub->tmp_map[i - 1]);
				b = ft_strlen(cub->tmp_map[i + 1]);
				if (i != 0 && (j > a || j > b))
					err_msg(cub, "Error: map is not covered with walls\n", 4);
				if (i != 0 && (cub->tmp_map[i - 1][j] <= 32
					|| cub->tmp_map[i + 1][j] <= 32
						|| cub->tmp_map[i][j - 1] <= 32
							|| cub->tmp_map[i][j + 1] <= 32))
					err_msg(cub, "Error: map is not covered with walls\n", 4);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_data *cub)
{
	character_control(cub, 0, 0, 0);
	if (cub->character_y == 0 || cub->character_y == cub->line - 2)
		err_msg(cub, "Error: Character in the wrong position\n", 3);
	cub->tmp_map = copy_map(cub);
	path_finder(cub->tmp_map, cub->character_y, cub->character_x, cub);
	wall_control(cub, 0, 0, 0);
	ft_free(cub->tmp_map);
}
