/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw_manager.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:26:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/07 22:19:41 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to set the scene in 3d
void	cub_rays_setup_draw(t_game *game, t_rays *rays, t_player *player)
{
	rays->shade = 1;
	cub_rays_setup_draw_h(game, rays);
	if (rays->dist.dist_v < rays->dist.dist_h)
		cub_rays_setup_draw_v(game, rays);
	rays->fish_eye = cub_fixang(player->angle - rays->angle);
	rays->dist.dist_t *= cos(cub_degtorad(rays->fish_eye));
	rays->line_height = (64 * SCALING) / rays->dist.dist_t;
	game->walls.offset = 0;
	game->walls.step = 32.0 / (float)rays->line_height;
	if (rays->line_height > SCALING)
	{
		game->walls.offset = (rays->line_height - SCALING) / 2.0;
		rays->line_height = SCALING;
	}
	rays->line_offset = (SCALING / 2) - (rays->line_height >> 1);
	rays->draw.x = rays->index;
	rays->draw.y = rays->line_offset;
	game->depth[rays->index / 8] = rays->dist.dist_t;
}

// Function to draw the scene
void	cub_rays_draw(t_game *game, t_rays *rays)
{
	cub_rays_draw_joists(game, rays, &game->joists);
	if (rays->tex_index == '1')
	{
		if (rays->dist.dist_h < rays->dist.dist_v)
			cub_rays_draw_h(game, rays);
		else if (rays->dist.dist_v < rays->dist.dist_h)
			cub_rays_draw_v(game, rays);
	}
	else if (rays->tex_index == 'D')
		cub_rays_draw_walls(&game->img, rays, &game->walls, \
			game->walls.tex_door);
}

// Function to draw on horizontal tiles
void	cub_rays_draw_h(t_game *game, t_rays *rays)
{
	if (rays->exit == 1)
		cub_rays_draw_walls(&game->img, rays, &game->walls, \
			game->walls.tex_leave);
	else if (sin(cub_degtorad(cub_fixang(rays->angle))) > 0.001)
		cub_rays_draw_walls(&game->img, rays, &game->walls, \
			game->walls.tex_north);
	else if (sin(cub_degtorad(cub_fixang(rays->angle))) < -0.001)
		cub_rays_draw_walls(&game->img, rays, &game->walls, \
			game->walls.tex_south);
}

// Function to draw on vertical tiles
void	cub_rays_draw_v(t_game *game, t_rays *rays)
{
	if (rays->exit == 1)
		cub_rays_draw_walls(&game->img, rays, &game->walls, \
			game->walls.tex_leave);
	if (cos(cub_degtorad(cub_fixang(rays->angle))) > 0.001)
		cub_rays_draw_walls(&game->img, rays, &game->walls, \
			game->walls.tex_west);
	else if (cos(cub_degtorad(cub_fixang(rays->angle))) < -0.001)
		cub_rays_draw_walls(&game->img, rays, &game->walls, \
			game->walls.tex_east);
}
