/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:13 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/07 22:25:41 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to handle movements
void	cub_movement_manager(t_player *player, int move, float speed,
			t_map *map)
{
	if (move == MOVE_FORWARD)
		cub_move_forward(player, speed, map);
	else if (move == MOVE_BACKWARD)
		cub_move_backward(player, speed, map);
	else if (move == MOVE_LEFT)
		cub_move_left(player, speed, map);
	else if (move == MOVE_RIGHT)
		cub_move_right(player, speed, map);
}

// Function to move forward
void	cub_move_forward(t_player *player, float speed, t_map *map)
{
	t_collision	sensor;

	sensor.xo = 25;
	sensor.yo = 25;
	if (player->delta.x < 0)
		sensor.xo = -25;
	if (player->delta.y < 0)
		sensor.yo = -25;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
	sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
	if (map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == '0'
		|| map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == 'L')
		player->pos.x += player->delta.x * speed;
	if (map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == '0'
		|| map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == 'L')
		player->pos.y += player->delta.y * speed;
}

// Function to move backward
void	cub_move_backward(t_player *player, float speed, t_map *map)
{
	t_collision	sensor;

	sensor.xo = 25;
	sensor.yo = 25;
	if (player->delta.x < 0)
		sensor.xo = -25;
	if (player->delta.y < 0)
		sensor.yo = -25;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_minus_xo = ((int)player->pos.x - sensor.xo) >> 6;
	sensor.ipy_minus_yo = ((int)player->pos.y - sensor.yo) >> 6;
	if (map->map[sensor.ipy * map->width + sensor.ipx_minus_xo] == '0'
		|| map->map[sensor.ipy * map->width + sensor.ipx_minus_xo] == 'L')
		player->pos.x -= player->delta.x * speed;
	if (map->map[sensor.ipy_minus_yo * map->width + sensor.ipx] == '0'
		|| map->map[sensor.ipy_minus_yo * map->width + sensor.ipx] == 'L')
		player->pos.y -= player->delta.y * speed;
}

// Function to move left
void	cub_move_left(t_player *player, float speed, t_map *map)
{
	t_collision	sensor;

	sensor.xo = player->delta.y * 25;
	sensor.yo = -player->delta.x * 25;
	if (sensor.xo < 0)
		sensor.xo = -25;
	else
		sensor.xo = 25;
	if (sensor.yo < 0)
		sensor.yo = -25;
	else
		sensor.yo = 25;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
	sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
	if (map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == '0'
		|| map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == 'L')
		player->pos.x += player->delta.y * speed;
	if (map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == '0'
		|| map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == 'L')
		player->pos.y -= player->delta.x * speed;
}

// Function to move right
void	cub_move_right(t_player *player, float speed, t_map *map)
{
	t_collision	sensor;

	sensor.xo = -player->delta.y * 25;
	sensor.yo = player->delta.x * 25;
	if (sensor.xo < 0)
		sensor.xo = -25;
	else
		sensor.xo = 25;
	if (sensor.yo < 0)
		sensor.yo = -25;
	else
		sensor.yo = 25;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
	sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
	if (map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == '0'
		|| map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == 'L')
		player->pos.x -= player->delta.y * speed;
	if (map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == '0'
		|| map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == 'L')
		player->pos.y += player->delta.x * speed;
}
