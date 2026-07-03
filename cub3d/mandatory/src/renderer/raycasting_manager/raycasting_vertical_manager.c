/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_vertical_manager.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:07:06 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/10 00:16:15 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to cast rays on vertical lines
void	cub_rays_cast_vertical(t_rays *rays, t_player *player)
{
	rays->dof = 0;
	rays->tangent = tan(cub_degtorad(rays->angle));
	if (cos(cub_degtorad(rays->angle)) > 0.001)
	{
		rays->pos.x = (((int)player->pos.x >> 6) << 6) + 64;
		rays->pos.y = (player->pos.x - rays->pos.x) * rays->tangent
			+ player->pos.y;
		rays->offset.x = 64;
		rays->offset.y = -rays->offset.x * rays->tangent;
		rays->exit_dir = -1;
	}
	else if (cos(cub_degtorad(rays->angle)) < -0.001)
	{
		rays->pos.x = (((int)player->pos.x >> 6) << 6) - 0.0001;
		rays->pos.y = (player->pos.x - rays->pos.x) * rays->tangent
			+ player->pos.y;
		rays->offset.x = -64;
		rays->offset.y = -rays->offset.x * rays->tangent;
		rays->exit_dir = 1;
	}
	else
	{
		rays->pos = player->pos;
		rays->dof = 1000;
	}
}

// Function to detect if a vertical line was hit
void	cub_rays_detect_vertical(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map)
{
	dist->dist_v = 100000;
	while (rays->dof < 1000)
	{
		rays->map.x = (int)(rays->pos.x) >> 6;
		rays->map.y = (int)(rays->pos.y) >> 6;
		rays->mp = rays->map.y * map->width + rays->map.x;
		if (rays->mp > 0 && rays->mp < map->width * map->height
			&& (map->map[rays->mp] != '0' && map->map[rays->mp] != 'L'))
		{
			dist->pos_v = rays->pos;
			dist->dist_v = cub_calc_dist(player->pos, dist->pos_v, rays->angle);
			rays->dof = 1000;
			rays->tex_index_v = map->map[rays->mp];
			if (map->map[(int)(rays->map.y * map->width \
				+ (rays->map.x + rays->exit_dir))] == 'L')
				rays->exit = 1;
		}
		else
		{
			rays->pos.x += rays->offset.x;
			rays->pos.y += rays->offset.y;
			rays->dof++;
		}
	}
}

// Function to setup drawing on vertical
void	cub_rays_setup_draw_v(t_game *game, t_rays *rays)
{
	rays->dist.dist_t = rays->dist.dist_v;
	rays->pos.x = rays->dist.pos_v.x;
	rays->pos.y = rays->dist.pos_v.y;
	rays->color = cub_convert_glrgb(0.502, 0, 0.502, 0);
	game->walls.tx = (int)(rays->pos.y / 2) % 32;
	if (rays->angle > 90 && rays->angle < 270)
		game->walls.tx = 31 - game->walls.tx;
	rays->tex_index = rays->tex_index_v;
	rays->shade = 0.5;
}
