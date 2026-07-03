/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:36:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/07 20:45:11 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to manage the raycasting
void	cub_raycasting_manager(t_game *game, t_rays *rays, t_player *player)
{
	rays->angle = cub_fixang(player->angle + RAYS_STARTING_ANGLE);
	rays->index = -1;
	while (++rays->index < FOV)
	{
		rays->exit = 0;
		rays->exit_dir = 0;
		rays->tex_index_v = 0;
		rays->tex_index_h = 0;
		cub_rays_cast_vertical(rays, player);
		cub_rays_detect_vertical(rays, player, &rays->dist, &game->map);
		cub_rays_cast_horizontal(rays, player);
		cub_rays_detect_horizontal(rays, player, &rays->dist, &game->map);
		cub_rays_setup_draw(game, rays, player);
		cub_rays_draw(game, rays);
		rays->angle = cub_fixang(rays->angle - RAYS_SPACING);
	}
}
