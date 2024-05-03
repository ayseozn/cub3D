/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:22 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:33:07 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../mlx/mlx.h"
#include <math.h>

void	rotate(t_data *c, double dir, double plane)
{
	if (c->right)
	{
		dir = c->dir_x;
		c->dir_x = c->dir_x * cos(c->rspeed) - c->dir_y * sin(c->rspeed);
		c->dir_y = dir * sin(c->rspeed) + c->dir_y * cos(c->rspeed);
		plane = c->plane_x;
		c->plane_x = c->plane_x * cos(c->rspeed) - c->plane_y * sin(c->rspeed);
		c->plane_y = plane * sin(c->rspeed) + c->plane_y * cos(c->rspeed);
	}
	if (c->left)
	{
		dir = c->dir_x;
		c->dir_x = c->dir_x * cos(c->rspeed) + c->dir_y * sin(c->rspeed);
		c->dir_y = -dir * sin(c->rspeed) + c->dir_y * cos(c->rspeed);
		plane = c->plane_x;
		c->plane_x = c->plane_x * cos(c->rspeed) + c->plane_y * sin(c->rspeed);
		c->plane_y = -plane * sin(c->rspeed) + c->plane_y * cos(c->rspeed);
	}
}

void	movement_2(t_data *cub)
{
	if (cub->d)
	{
		if (cub->map[(int)(cub->location_y)][(int)(cub->location_x
			+ cub->plane_x * cub->speed)] != '1')
			cub->location_x += cub->plane_x * cub->speed;
		if (cub->map[(int)(cub->location_y + cub->plane_y
				* cub->speed)][(int)(cub->location_x)] != '1')
			cub->location_y += cub->plane_y * cub->speed;
	}
	if (cub->a)
	{
		if (cub->map[(int)(cub->location_y)][(int)(cub->location_x
			- cub->plane_x * cub->speed)] != '1')
			cub->location_x -= cub->plane_x * cub->speed;
		if (cub->map[(int)(cub->location_y - cub->plane_y
				* cub->speed)][(int)(cub->location_x)] != '1')
			cub->location_y -= cub->plane_y * cub->speed;
	}
}

void	movement(t_data *cub)
{
	if (cub->w)
	{
		if (cub->map[(int)(cub->location_y)][(int)(cub->location_x
			+ cub->dir_x * cub->speed)] != '1')
			cub->location_x += cub->dir_x * cub->speed;
		if (cub->map[(int)(cub->location_y + cub->dir_y
				* cub->speed)][(int)(cub->location_x)] != '1')
			cub->location_y += cub->dir_y * cub->speed;
	}
	if (cub->s)
	{
		if (cub->map[(int)(cub->location_y)][(int)(cub->location_x
			- cub->dir_x * cub->speed)] != '1')
			cub->location_x -= cub->dir_x * cub->speed;
		if (cub->map[(int)(cub->location_y - cub->dir_y
				* cub->speed)][(int)(cub->location_x)] != '1')
			cub->location_y -= cub->dir_y * cub->speed;
	}
	movement_2(cub);
}

void	raycast(t_data *cub)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		calculate_ray_direction_and_distances(cub, x);
		calculate_step(cub);
		calculate_collision_distance(cub);
		calculate_wall_properties(cub);
		render_column(cub, x, -1);
	}
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win_ptr, cub->mlx.img, 0, 0);
}

int	gamefunc(t_data *cub)
{
	movement(cub);
	rotate(cub, 0, 0);
	raycast(cub);
	return (0);
}
