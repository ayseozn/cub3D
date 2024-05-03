/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:18 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/28 05:55:50 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

void	calculate_ray_direction_and_distances(t_data *cub, int x)
{
	cub->camera_x = 2 * x / (double)WIDTH - 1;
	cub->raydir_x = cub->dir_x + cub->plane_x * cub->camera_x;
	cub->raydir_y = cub->dir_y + cub->plane_y * cub->camera_x;
	cub->map_x = (int)cub->location_x;
	cub->map_y = (int)cub->location_y;
	if (cub->raydir_x == 0)
		cub->delta_dist_x = 1e30;
	else
		cub->delta_dist_x = fabs(1 / cub->raydir_x);
	if (cub->raydir_y == 0)
	{
		cub->dir_y = 0.001f;
		cub->delta_dist_y = 1e30;
	}
	else
		cub->delta_dist_y = fabs(1 / cub->raydir_y);
}

void	calculate_step(t_data *c)
{
	if (c->raydir_x < 0)
	{
		c->step_x = -1;
		c->side_dist_x = (c->location_x - c->map_x) * c->delta_dist_x;
	}
	else
	{
		c->step_x = 1;
		c->side_dist_x = (c->map_x + 1.0 - c->location_x) * c->delta_dist_x;
	}
	if (c->raydir_y < 0)
	{
		c->step_y = -1;
		c->side_dist_y = (c->location_y - c->map_y) * c->delta_dist_y;
	}
	else
	{
		c->step_y = 1;
		c->side_dist_y = (c->map_y + 1.0 - c->location_y) * c->delta_dist_y;
	}
}

void	calculate_collision_distance(t_data *cub)
{
	int	nearest_wall;

	while (true)
	{
		if (cub->side_dist_x < cub->side_dist_y)
			nearest_wall = 0;
		else
			nearest_wall = 1;
		if (nearest_wall == 0)
		{
			cub->side_dist_x += cub->delta_dist_x;
			cub->map_x += cub->step_x;
		}
		else
		{
			cub->side_dist_y += cub->delta_dist_y;
			cub->map_y += cub->step_y;
		}
		cub->side = nearest_wall;
		if ((cub->map[cub->map_y][cub->map_x]) == '1')
			break ;
	}
}

void	calculate_wall_properties(t_data *cub)
{
	if (cub->side == 1)
		cub->perp_wall_dist = cub->side_dist_y - cub->delta_dist_y;
	else
		cub->perp_wall_dist = cub->side_dist_x - cub->delta_dist_x;
	cub->line_h = (int)(HEIGHT / cub->perp_wall_dist);
	cub->draw_start = (HEIGHT - cub->line_h) / 2;
	cub->draw_start = (cub->draw_start >= 0) * cub->draw_start;
	cub->draw_end = (HEIGHT + cub->line_h) / 2;
	if (cub->draw_end >= HEIGHT)
		cub->draw_end = HEIGHT - 1;
	if (cub->side == 1)
		cub->wall_x = cub->location_x + cub->perp_wall_dist
			* cub->raydir_x;
	else
		cub->wall_x = cub->location_y + cub->perp_wall_dist
			* cub->raydir_y;
	cub->wall_x = cub->wall_x - (int)cub->wall_x;
	cub->tex_x = (int)(cub->wall_x * TEXWIDTH);
	if (cub->side == 0 && cub->raydir_x < 0)
		cub->tex_x = TEXWIDTH - cub->tex_x - 1;
	if (cub->side == 1 && cub->raydir_y > 0)
		cub->tex_x = TEXWIDTH - cub->tex_x - 1;
	cub->step_size = (double)TEXHEIGHT / cub->line_h;
	cub->tex_pos = (cub->draw_start - HEIGHT / 2 + cub->line_h / 2)
		* cub->step_size;
}

void	render_column(t_data *cub, int x, int y)
{
	while (++y < HEIGHT)
	{
		cub->tex_y = (int)cub->tex_pos;
		if (y < cub->draw_start)
			cub->mlx.addr[y * WIDTH + x] = cub->color.color_c;
		else if (y > cub->draw_end)
			cub->mlx.addr[y * WIDTH + x] = cub->color.color_f;
		else
		{
			if (cub->side == 1 && cub->raydir_y < 0)
				cub->mlx.addr[y * WIDTH + x] = cub->north.addr[TEXHEIGHT
					* cub->tex_y + cub->tex_x];
			else if (cub->side == 1 && cub->raydir_y >= 0)
				cub->mlx.addr[y * WIDTH + x] = cub->south.addr[TEXHEIGHT
					* cub->tex_y + cub->tex_x];
			if (cub->side == 0 && cub->raydir_x < 0)
				cub->mlx.addr[y * WIDTH + x] = cub->west.addr[TEXHEIGHT
					* cub->tex_y + cub->tex_x];
			else if (cub->side == 0 && cub->raydir_x >= 0)
				cub->mlx.addr[y * WIDTH + x] = cub->east.addr[TEXHEIGHT
					* cub->tex_y + cub->tex_x];
			cub->tex_pos += cub->step_size;
		}
	}
}
