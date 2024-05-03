/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:01 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:13:48 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <unistd.h>

void	game_init2(t_data *cub)
{
	cub->w = false;
	cub->s = false;
	cub->a = false;
	cub->d = false;
	cub->left = false;
	cub->right = false;
	cub->speed = 0;
	cub->rspeed = 0;
	cub->camera_x = 0;
	cub->side = 0;
	cub->perp_wall_dist = 0;
	cub->line_h = 0;
	cub->draw_start = 0;
	cub->draw_end = 0;
	cub->wall_x = 0;
	cub->tex_pos = 0;
	cub->step_size = 0;
}

void	game_init(t_data *cub)
{
	cub->dir_x = 0;
	cub->dir_y = 0;
	cub->plane_x = 0;
	cub->plane_y = 0;
	cub->location_x = 0;
	cub->location_y = 0;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->raydir_x = 0;
	cub->raydir_y = 0;
	cub->delta_dist_x = 0;
	cub->delta_dist_y = 0;
	cub->side_dist_x = 0;
	cub->side_dist_y = 0;
	cub->step_x = 0;
	cub->step_y = 0;
	cub->tex_x = 0;
	cub->tex_y = 0;
	game_init2(cub);
}

void	texture_init(t_data *cub)
{
	cub->north.dir = NULL;
	cub->north.img = NULL;
	cub->south.dir = NULL;
	cub->south.img = NULL;
	cub->west.dir = NULL;
	cub->west.img = NULL;
	cub->east.dir = NULL;
	cub->east.img = NULL;
	cub->north.addr = NULL;
	cub->south.addr = NULL;
	cub->west.addr = NULL;
	cub->east.addr = NULL;
}

void	color_init(t_data *cub, int i)
{
	while (i < 3)
	{
		cub->color.f[i] = -1;
		cub->color.c[i] = -1;
		i++;
	}
}

void	struct_init(t_data *cub)
{
	cub->full_map = NULL;
	cub->map = NULL;
	cub->tmp_map = NULL;
	cub->map_name = NULL;
	cub->direction = '\0';
	cub->line = 0;
	cub->map_line_num = 0;
	cub->character_x = 0;
	cub->character_y = 0;
	texture_init(cub);
	color_init(cub, 0);
	game_init(cub);
	cub->mlx.ptr = NULL;
	cub->mlx.win_ptr = NULL;
	cub->mlx.img = NULL;
	cub->mlx.addr = NULL;
	cub->mlx.bits_per_pixel = 0;
	cub->mlx.size_line = 0;
	cub->mlx.endian = 0;
}
