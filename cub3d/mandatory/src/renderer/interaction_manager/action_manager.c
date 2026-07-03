/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 02:38:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 06:42:30 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to manage actions
void	cub_action_manager(int action, t_player *player, t_map *map)
{
	if (action == OPEN_DOOR && player->collected > 0)
		cub_action_open_door(player, map);
}

// Function to open the door
void	cub_action_open_door(t_player *player, t_map *map)
{
	t_collision	sensor;

	(void)map;
	sensor.xo = 30;
	sensor.yo = 30;
	if (player->delta.x < 0)
		sensor.xo = -30;
	if (player->delta.y < 0)
		sensor.yo = -30;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
	sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
	if (map->map[sensor.ipy_plus_yo * map->width + sensor.ipx_plus_xo] == 'D')
	{
		map->map[sensor.ipy_plus_yo * map->width + sensor.ipx_plus_xo] = '0';
		map->door_opened = 1;
	}
}
