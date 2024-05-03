/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:13 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:32:35 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>

int	find_color(int *color, char *str, char c, int j)
{
	int		i;
	char	**color_nums;

	i = 1;
	while (str[i] <= 32 || str[i] == c)
		i++;
	color_nums = ft_split(str + i, ',');
	i = 0;
	while (color_nums[j])
	{
		color[j] = ft_atoi(color_nums[j]);
		j++;
	}
	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255 || color_nums[i] == NULL)
		{
			ft_free(color_nums);
			return (-1);
		}
		i++;
	}
	ft_free(color_nums);
	return (0);
}

int	parse_texture_continued(t_data *cub, int i, int j)
{
	if (ft_strncmp(cub->full_map[i], "NO ", 3) == 0)
	{
		if (!cub->north.dir)
			cub->north.dir = ft_strdup2(cub->full_map[i], "NO");
		j++;
	}
	else if (ft_strncmp(cub->full_map[i], "SO ", 3) == 0)
	{
		if (!cub->south.dir)
			cub->south.dir = ft_strdup2(cub->full_map[i], "SO");
		j++;
	}
	else if (ft_strncmp(cub->full_map[i], "WE ", 3) == 0)
	{
		if (!cub->west.dir)
			cub->west.dir = ft_strdup2(cub->full_map[i], "WE");
		j++;
	}
	else if (ft_strncmp(cub->full_map[i], "EA ", 3) == 0)
	{
		if (!cub->east.dir)
			cub->east.dir = ft_strdup2(cub->full_map[i], "EA");
		j++;
	}
	return (j);
}

void	parse_texture(t_data *cub, int i, int j)
{
	while (i < cub->map_line_num)
	{
		j = parse_texture_continued(cub, i, j);
		if (ft_strncmp(cub->full_map[i], "F ", 2) == 0)
		{
			if (find_color(cub->color.f, cub->full_map[i], 'F', 0) == -1)
				err_msg(cub, "error: Failed to read color codes\n", 2);
			j++;
		}
		else if (ft_strncmp(cub->full_map[i], "C ", 2) == 0)
		{
			if (find_color(cub->color.c, cub->full_map[i], 'C', 0) == -1)
				err_msg(cub, "error: Failed to read color codes\n", 2);
			j++;
		}
		i++;
	}
	if (!cub->east.dir || !cub->north.dir || !cub->south.dir || !cub->west.dir
		|| cub->color.f[0] == -1 || cub->color.c[0] == -1 || j != 6)
		err_msg(cub, "error: Map is missing a directional marker\n", 2);
}

void	ft_map(t_data *cub, int line)
{
	int	i;

	i = 0;
	while (cub->full_map[line][0] == '\n')
		line--;
	while (line > 0 && is_character(cub->full_map[line]))
		line--;
	cub->map = (char **)ft_calloc(sizeof(char *), (cub->map_line_num - line));
	cub->line = cub->map_line_num - line;
	if (!cub->map)
		err_msg(cub, "Error: malloc error\n", 2);
	line++;
	ft_line_control(cub, line, 0, 0);
	while (line <= cub->map_line_num - 1)
	{
		cub->map[i] = ft_strdup(cub->full_map[line]);
		if (!cub->map[i])
		{
			ft_free_n(cub->map, i);
			err_msg(cub, "Error: malloc error\n", 2);
		}
		i++;
		line++;
	}
}

void	map_read(t_data *cub, int i)
{
	int	fd;

	fd = open(cub->map_name, O_RDONLY);
	if (fd == -1)
		err_msg(cub, "failed to open file\n", 0);
	cub->full_map = (char **) ft_calloc(sizeof(char *), cub->map_line_num);
	if (!cub->full_map)
		err_msg(cub, "Memory allocation failed\n", 1);
	while (i < cub->map_line_num)
	{
		cub->full_map[i] = get_next_line(fd);
		if (!cub->full_map[i])
		{
			ft_free_n(cub->full_map, i);
			err_msg(cub, "error: malloc error\n", 0);
		}
		i++;
	}
	close (fd);
	parse_texture (cub, 0, 0);
	ft_map(cub, cub->map_line_num - 1);
	check_map(cub);
}
