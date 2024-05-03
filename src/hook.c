/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:27:55 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:29:13 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_mlx(t_data *cub)
{
	err_msg(cub, "finish", 3);
	return (0);
}

int	move_press(int keycode, t_data *cub)
{
	if (keycode == 53)
		err_msg(cub, "finish", 3);
	if (keycode == 13)
		cub->w = true;
	if (keycode == 1)
		cub->s = true;
	if (keycode == 0)
		cub->a = true;
	if (keycode == 2)
		cub->d = true;
	if (keycode == 124)
		cub->right = true;
	if (keycode == 123)
		cub->left = true;
	return (0);
}

int	move_release(int keycode, t_data *cub)
{
	if (keycode == 13)
		cub->w = false;
	if (keycode == 1)
		cub->s = false;
	if (keycode == 0)
		cub->a = false;
	if (keycode == 2)
		cub->d = false;
	if (keycode == 124)
		cub->right = false;
	if (keycode == 123)
		cub->left = false;
	return (0);
}
