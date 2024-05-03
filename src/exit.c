/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:27:45 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:35:55 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <unistd.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_n(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

void	compass_free(t_data *cub)
{
	free(cub->north.dir);
	free(cub->south.dir);
	free(cub->west.dir);
	free(cub->east.dir);
	map_free(cub);
}

void	map_free(t_data *cub)
{
	int	i;

	i = 0;
	while (i < cub->map_line_num)
	{
		free(cub->full_map[i]);
		i++;
	}
	free(cub->full_map);
}

void	err_msg(t_data *cub, char *str, int flag)
{
	while (*str)
		write(2, str++, 1);
	if (flag == 1)
		map_free(cub);
	if (flag == 2 || flag == 3 || flag == 4)
		compass_free(cub);
	if (flag == 3 || flag == 4)
		ft_free_n(cub->map, cub->line);
	if (flag == 4)
		ft_free(cub->tmp_map);
	if (cub->north.img)
		mlx_destroy_image(cub->mlx.ptr, cub->north.img);
	if (cub->south.img)
		mlx_destroy_image(cub->mlx.ptr, cub->south.img);
	if (cub->west.img)
		mlx_destroy_image(cub->mlx.ptr, cub->west.img);
	if (cub->east.img)
		mlx_destroy_image(cub->mlx.ptr, cub->east.img);
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.ptr, cub->mlx.img);
	if (cub->mlx.win_ptr)
		mlx_destroy_window(cub->mlx.ptr, cub->mlx.win_ptr);
	exit (1);
}
