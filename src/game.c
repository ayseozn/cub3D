/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:27:51 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:32:27 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "../mlx/mlx.h"

void	player_init(t_data *cub)
{
	if (cub->direction == 'N')
	{
		cub->dir_y = -1;
		cub->plane_x = 0.66;
	}
	if (cub->direction == 'S')
	{
		cub->dir_y = 1;
		cub->plane_x = -0.66;
	}
	if (cub->direction == 'W')
	{
		cub->dir_x = -1;
		cub->plane_y = -0.66;
	}
	if (cub->direction == 'E')
	{
		cub->dir_x = 1;
		cub->plane_y = 0.66;
	}
	cub->location_x = cub->character_x + 0.5;
	cub->location_y = cub->character_y + 0.5;
	cub->speed = 0.065;
	cub->rspeed = 0.035;
}

void	init_mlx(t_data *c, int i, int j)
{
	c->mlx.ptr = mlx_init();
	if (!c->mlx.ptr)
		err_msg(c, "Error: failed xpm\n", 3);
	c->mlx.win_ptr = mlx_new_window(c->mlx.ptr, WIDTH, HEIGHT, "cub3D");
	if (!c->mlx.win_ptr)
		err_msg(c, "Error: failed xpm\n", 3);
	c->mlx.img = mlx_new_image(c->mlx.ptr, WIDTH, HEIGHT);
	c->north.img = mlx_xpm_file_to_image(c->mlx.ptr, c->north.dir, &i, &i);
	c->south.img = mlx_xpm_file_to_image(c->mlx.ptr, c->south.dir, &i, &i);
	c->west.img = mlx_xpm_file_to_image(c->mlx.ptr, c->west.dir, &i, &i);
	c->east.img = mlx_xpm_file_to_image(c->mlx.ptr, c->east.dir, &i, &i);
	if (!c->north.img || !c->south.img || !c->west.img
		|| !c->east.img || !c->mlx.img)
		err_msg(c, "Error: failed xpm\n", 3);
	c->mlx.addr = (int *)mlx_get_data_addr(c->mlx.img,
			&c->mlx.bits_per_pixel, &c->mlx.size_line, &c->mlx.endian);
	c->north.addr = (int *)mlx_get_data_addr(c->north.img, &j, &j, &j);
	c->south.addr = (int *)mlx_get_data_addr(c->south.img, &j, &j, &j);
	c->west.addr = (int *)mlx_get_data_addr(c->west.img, &j, &j, &j);
	c->east.addr = (int *)mlx_get_data_addr(c->east.img, &j, &j, &j);
	if (!c->north.addr || !c->south.addr || !c->west.addr
		|| !c->east.addr || !c->mlx.addr)
		err_msg(c, "Error: failed xpm\n", 3);
}

void	game(t_data *cub)
{
	cub->color.color_c = (0 << 24 | cub->color.c[0] << 16
			| cub->color.c[1] << 8 | cub->color.c[2]);
	cub->color.color_f = (0 << 24 | cub->color.f[0] << 16
			| cub->color.f[1] << 8 | cub->color.f[2]);
	player_init(cub);
	init_mlx(cub, 0, 0);
	mlx_hook(cub->mlx.win_ptr, 2, 0, move_press, cub);
	mlx_hook(cub->mlx.win_ptr, 3, 0, move_release, cub);
	mlx_hook(cub->mlx.win_ptr, 17, 0, exit_mlx, cub);
	mlx_loop_hook(cub->mlx.ptr, &gamefunc, cub);
	mlx_loop(cub->mlx.ptr);
}
