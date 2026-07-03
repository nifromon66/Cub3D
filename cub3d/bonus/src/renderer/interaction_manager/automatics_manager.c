/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automatics_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:27:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/02 23:18:24 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to automatically close the door behind the player
void	cub_automatics_close_door(t_game *game, t_map *map, t_map *minimap)
{
	t_point	pos_map;

	if (map->door_opened == 0)
		return ;
	pos_map.y = -1;
	while (++pos_map.y < map->height)
	{
		pos_map.x = -1;
		while (++pos_map.x < map->width)
		{
			if (cub_automatics_close_door_loop(game, map, minimap, &pos_map) \
				== 1)
			{
				map->map[(int)(pos_map.y * map->width + pos_map.x)] = 'D';
				map->door_opened = 0;
			}
		}
	}
}

// Function to help automatics close doors
int	cub_automatics_close_door_loop(t_game *game, t_map *map, t_map *minimap,
		t_point *pos_map)
{
	int	i;

	i = 0;
	if (minimap->map[(int)(pos_map->y * map->width + pos_map->x)] == 'D' \
		&& map->map[(int)(pos_map->y * map->width + pos_map->x)] == '0')
	{
		if (cub_automatics_detect_player(&game->player, map, pos_map) == 1)
		{
			while (i < game->sprite[i].nbr_sprites)
			{
				if (cub_automatics_detect_foe(&((game->sprite)[i]), map, \
					pos_map) == 0)
					return (0);
				i++;
			}
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

// Function to detect if there is a player neer the door
int	cub_automatics_detect_player(t_player *player, t_map *map,
			t_point *pos_map)
{
	int		mp_player;

	mp_player = (int)(player->pos.y / 64) * map->width \
		+ (int)(player->pos.x / 64);
	if (mp_player != pos_map->y * map->width + pos_map->x
		&& mp_player != (int)((pos_map->y - 1) * map->width + pos_map->x)
		&& mp_player != (int)((pos_map->y + 1) * map->width + pos_map->x)
		&& mp_player != (int)(pos_map->y * map->width + (pos_map->x + 1))
		&& mp_player != (int)(pos_map->y * map->width + (pos_map->x - 1)))
		return (1);
	return (0);
}

// Function to detect if there is a foe neer the door
int	cub_automatics_detect_foe(t_sprite *sprite, t_map *map,
			t_point *pos_map)
{
	int		mp_foe;

	if (sprite->status == 0 || sprite->type == 'O')
		return (1);
	mp_foe = ((((int)sprite->pos.y >> 6)) * map->width \
		+ (((int)sprite->pos.x >> 6)));
	if (mp_foe != pos_map->y * map->width + pos_map->x
		&& mp_foe != (int)((pos_map->y - 1) * map->width + pos_map->x)
		&& mp_foe != (int)((pos_map->y + 1) * map->width + pos_map->x)
		&& mp_foe != (int)(pos_map->y * map->width + (pos_map->x + 1))
		&& mp_foe != (int)(pos_map->y * map->width + (pos_map->x - 1)))
		return (1);
	return (0);
}
