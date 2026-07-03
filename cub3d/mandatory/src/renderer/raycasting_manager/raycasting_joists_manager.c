/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_joists_manager.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:22:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/10 01:10:53 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to render the floors and ceilins
void	cub_rays_draw_joists(t_game *game, t_rays *rays, t_joists *joists)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		rays->draw_index = (rays->line_offset + rays->line_height) - 1;
		while (++rays->draw_index < SCALING)
		{
			cub_rays_setup_joists(rays, &game->player, joists);
			if (game->map.map[(int)(joists->ty / 32.0) * game->map.width
				+ (int)(joists->tx / 32.0)] == 'L')
				cub_rays_draw_floors_tex(game, rays, joists, \
					game->joists.tex_leave);
			else
				cub_rays_draw_floors_rgb(&game->img, rays, \
					game->joists.rgb_floor);
			cub_rays_draw_ceilings_rgb(&game->img, rays, \
				game->joists.rgb_ceiling);
			joists->ty += joists->step;
		}
		rays->draw.x++;
	}
}

// Function to setup the drawing of floors and ceilins
void	cub_rays_setup_joists(t_rays *rays, t_player *player, t_joists *joists)
{
	joists->dy = rays->draw_index - (SCALING / 2.0);
	joists->deg = cub_degtorad(rays->angle);
	joists->fix = cos(cub_degtorad(cub_fixang(player->angle - rays->angle)));
	joists->tx = player->pos.x / 2 + cos(joists->deg) * 158 * 2 * 32
		/ joists->dy / joists->fix;
	joists->ty = player->pos.y / 2 - sin(joists->deg) * 158 * 2 * 32
		/ joists->dy / joists->fix;
}
