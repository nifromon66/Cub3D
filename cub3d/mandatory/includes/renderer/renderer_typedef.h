/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_typedef.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:57:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/05 15:16:34 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_TYPEDEF_H
# define RENDERER_TYPEDEF_H

# include "renderer_define.h"
# include "../cub.h"

// Enums
typedef enum e_movement
{
	MOVE_FORWARD,
	MOVE_BACKWARD,
	MOVE_RIGHT,
	MOVE_LEFT,
	ROTATE_RIGHT,
	ROTATE_LEFT,
	OPEN_DOOR
}	t_movement;

// Structures
	// Positions
typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_point_xyz
{
	int	x;
	int	y;
	int	z;
}		t_point_xyz;

typedef struct s_pos_xyz
{
	float	x;
	float	y;
	float	z;
}			t_pos_xyz;

typedef struct s_distance
{
	float	dist_v;
	t_pos	pos_v;
	float	dist_h;
	t_pos	pos_h;
	float	dist_t;
}			t_distance;

typedef struct s_segment
{
	t_pos	start;
	t_pos	end;
}			t_segment;
	// Colors
typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;
	// Actors
typedef struct s_player
{
	t_pos	pos;
	float	angle;
	t_pos	delta;
	float	speed;
	int		collected;
}			t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	arrow_left;
	int	arrow_right;
}		t_keys;

typedef struct s_collision
{
	int	xo;
	int	yo;
	int	ipx;
	int	ipy;
	int	ipx_plus_xo;
	int	ipy_plus_yo;
	int	ipx_minus_xo;
	int	ipy_minus_yo;
}		t_collision;

typedef struct s_sprite
{
	int			type;
	int			status;
	int			map;
	t_pos_xyz	pos;
	t_pos_xyz	screen;
	float		cosinus;
	float		sinus;
	float		a;
	float		b;
	t_point		pos2;
	t_pos		pos_draw;
	int			scale;
	int			*texture;
	t_pos		tex;
	t_pos		tex_step;
	int			tex_index;
	int			pixel;
	t_rgb		rgb;
	int			nbr_foes;
	int			nbr_collectibles;
	int			nbr_sprites;
	int			in_sight;
	int			hit;
	int			hit_time;
	int			lives;
	t_point		pos_foe;
	t_point		offset_add;
	t_point		offset_sub;
}				t_sprite;

typedef struct s_weapons
{
	int		*texture;
	int		tex_index;
	int		pixel;
	t_rgb	rgb;
	int		firing;
}			t_weapons;
	// Elements
typedef struct s_walls
{
	float	ty;
	float	tx;
	float	offset;
	float	step;
	int		pixel;
	t_rgb	rgb;
	int		*tex_north;
	int		*tex_south;
	int		*tex_east;
	int		*tex_west;
	int		*tex_door;
	int		*tex_leave;
}			t_walls;

typedef struct s_joists
{
	float	dy;
	float	ty;
	float	tx;
	float	offset;
	float	step;
	float	deg;
	float	fix;
	int		pixel;
	t_rgb	rgb;
	t_rgb	rgb_floor;
	t_rgb	rgb_ceiling;
	int		*tex_leave;
}			t_joists;

typedef struct s_sky
{
	int		sx;
	int		sy;
	int		offset;
	int		pixel;
	t_rgb	rgb;
	int		*tex;
	int		*tex_layers[3];
}			t_sky;

typedef struct s_screen
{
	int		sx;
	int		sy;
	int		offset;
	int		pixel;
	t_pos	pos;
	t_rgb	rgb;
	int		tex_index;
	int		timer;
	int		*tex;
	int		*tex_layers[3];
}			t_screen;
	// Rays
typedef struct s_rays
{
	int			index;
	t_pos		map;
	int			mp;
	int			dof;
	t_pos		pos;
	float		angle;
	t_pos		offset;
	float		tangent;
	int			fish_eye;
	t_distance	dist;
	t_pos		draw;
	int			draw_index;
	int			line_height;
	int			line_offset;
	int			tex_index;
	int			tex_index_v;
	int			tex_index_h;
	int			color;
	float		shade;
	int			exit_dir;
	int			exit;
}				t_rays;

	// Fps
typedef struct s_fps
{
	float	frame;
	float	old_frame;
	float	fps;
}			t_fps;
	// Maps
typedef struct s_map
{
	int		width;
	int		height;
	char	*map;
	int		door_opened;
}			t_map;

typedef struct s_minimap
{
	t_map	map;
	t_pos	pos_map;
	t_pos	pos_screen;
	t_pos	center;
	t_point	dir;
	float	mp;
	int		radius;
	int		within_radius;
}			t_minimap;

	// Images
typedef struct s_img_data
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img_data;
	// Game
typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			status;
	t_player	player;
	t_img_data	img;
	t_keys		keys;
	t_rays		rays;
	t_fps		fps;
	t_walls		walls;
	t_joists	joists;
	t_sky		sky;
	t_screen	screen;
	t_map		map;
	t_minimap	minimap;
	t_sprite	*sprite;
	t_weapons	glock;
	int			*depth;
	t_cubval	*cubval;
}				t_game;

#endif