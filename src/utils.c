/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:24 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:14:00 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../libft/libft.h"
#include <fcntl.h>

void	num_line(t_data *cub)
{
	int		fd;
	char	*line;

	cub->map_line_num = 0;
	fd = open (cub->map_name, O_RDONLY);
	if (fd == -1)
		err_msg(cub, "Error: File could not be read\n", 0);
	line = get_next_line(fd);
	if (line == NULL)
		err_msg(cub, "Error: File is empty\n", 0);
	while (line)
	{
		cub->map_line_num++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}

void	extension_control(char **av, t_data *cub)
{
	int	len;

	cub->map_name = av[1];
	len = ft_strlen(cub->map_name);
	if (cub->map_name[len - 1] != 'b' || cub->map_name[len - 2] != 'u'
		|| cub->map_name[len - 3] != 'c' || cub->map_name[len - 4] != '.')
		err_msg(cub, "Error: Map file is not .cub\n", 0);
	num_line(cub);
}

int	is_character(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (0);
	while (str[i] <= 32 && str[i] != '\n')
		i++;
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W'
		|| str[i] == 'E' || str[i] == 'F' || str[i] == 'C')
		return (0);
	return (1);
}

void	ft_line_control(t_data *cub, int line, int i, int j)
{
	while (cub->full_map[i])
	{
		j = 0;
		if ((cub->full_map[i][0] <= 32 && cub->full_map[i][0] != '\n')
			|| cub->full_map[i][0] == '1' || cub->full_map[i][0] == '0')
		{
			while (cub->full_map[i][j] <= 32 && cub->full_map[i][j] != '\n')
				j++;
			if (cub->full_map[i][j] == '1' || cub->full_map[i][j] == '0')
			{
				if (i == line)
					return ;
				else
				{
					free(cub->map);
					err_msg(cub, "Error: map newline error\n", 2);
				}
			}
		}
		i++;
	}
}
