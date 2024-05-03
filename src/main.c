/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:03 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:21:19 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	t_data	cub;

	if (ac != 2)
	{
		write(2, "Error: Number of arguments must be two\n", 38);
		return (0);
	}
	struct_init(&cub);
	extension_control(av, &cub);
	map_read(&cub, 0);
	game(&cub);
	return (0);
}
