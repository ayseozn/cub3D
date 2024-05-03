/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buryilma_aysozen <buryilma_aysozen@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:27:40 by buryilma_ay       #+#    #+#             */
/*   Updated: 2024/03/29 10:16:33 by buryilma_ay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 720
# define HEIGHT 550
# define TEXWIDTH 64
# define TEXHEIGHT 64

# include <stdbool.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx;

typedef struct s_texture
{
	int		*addr;
	void	*img;
	char	*dir;
}	t_texture;

typedef struct s_color
{
	int	f[3];
	int	c[3];
	int	color_f;
	int	color_c;
}	t_color;

typedef struct s_cub3D
{
	char		**full_map;
	char		**map;
	char		**tmp_map;
	char		*map_name;
	char		direction;
	int			line;
	int			map_line_num;
	int			character_x;
	int			character_y;
	t_mlx		mlx;
	t_color		color;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		location_x;
	float		location_y;
	int			map_x;
	int			map_y;
	double		raydir_x;
	double		raydir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			tex_x;
	int			tex_y;
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		left;
	bool		right;
	float		speed;
	float		rspeed;
	double		camera_x;
	int			side;
	double		perp_wall_dist;
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	double		tex_pos;
	double		step_size;
}	t_data;

//map.c
int		parse_texture_continued(t_data *cub, int i, int j);
void	parse_texture(t_data *cub, int i, int j);
void	map_read(t_data *cub, int i);
int		find_color(int *color, char *str, char c, int j);
void	ft_map(t_data *cub, int line);

//map_control.c
void	character_control(t_data *cub, int i, int j, int k);
char	**copy_map(t_data *cub);
void	check_map(t_data *cub);
void	path_finder(char **map, int y, int x, t_data *cub);
void	wall_control(t_data *cub, int i, int j, int a);

// exit.c
void	ft_free(char **str);
void	ft_free_n(char **str, int i);
void	compass_free(t_data *cub);
void	map_free(t_data *cub);
void	err_msg(t_data *cub, char *str, int flag);

//initialize.c
void	struct_init(t_data *cub);
void	texture_init(t_data *cub);
void	color_init(t_data *cub, int i);
void	game_init(t_data *cub);
void	game_init2(t_data *cub);

//game.c
void	player_init(t_data *cub);
void	init_mlx(t_data *cub, int i, int j);
void	game(t_data *cub);

//utils.c
void	extension_control(char **av, t_data *cub);
void	num_line(t_data *cub);
int		is_character(char *str);
void	ft_line_control(t_data *cub, int line, int i, int j);

//hook.c
int		move_press(int keycode, t_data *cub);
int		move_release(int keycode, t_data *cub);
int		exit_mlx(t_data *cub);

//raycast
int		gamefunc(t_data *cub);
void	movement(t_data *cub);
void	movement_2(t_data *cub);
void	rotate(t_data *cub, double dir, double plane);
void	raycast(t_data *cub);

//ray
void	render_column(t_data *cub, int x, int y);
void	calculate_wall_properties(t_data *cub);
void	calculate_collision_distance(t_data *cub);
void	calculate_step(t_data *cub);
void	calculate_ray_direction_and_distances(t_data *cub, int x);

#endif
