/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_weapons_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 08:26:52 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/10 00:41:53 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to manage weapons
void	cub_weapons_manager(t_game *game, t_weapons *glock)
{
	cub_setup_weapons(game, glock);
	cub_render_weapons(game, glock);
}

// Function to setup weapons parameters
void	cub_setup_weapons(t_game *game, t_weapons *glock)
{
	if (glock->firing == 1)
	{
		glock->tex_index += (int)(0.01 * game->fps.fps);
		if (glock->tex_index * WEAPON_SIZE >= WEAPON_SIZE * 7)
		{
			glock->tex_index = 0;
			glock->firing = 0;
		}
	}
}

// Function to render weapons
void	cub_render_weapons(t_game *game, t_weapons *glock)
{
	t_pos	pos;

	pos.y = -1;
	while (++pos.y < 128)
	{
		pos.x = -1;
		while (++pos.x < 128)
		{
			glock->pixel = (pos.y * 128 + pos.x) * 3 \
				+ (glock->tex_index * WEAPON_SIZE);
			glock->rgb.red = glock->texture[glock->pixel + 0];
			glock->rgb.green = glock->texture[glock->pixel + 1];
			glock->rgb.blue = glock->texture[glock->pixel + 2];
			pos.x *= 8;
			pos.y *= 5.5;
			if (cub_convert_glrgb(glock->rgb.red, glock->rgb.green, \
				glock->rgb.blue, 1) != cub_convert_glrgb(255, 0, 255, 1))
				cub_draw_point(&game->img, pos, 8,
					cub_convert_glrgb(glock->rgb.red, glock->rgb.green, \
						glock->rgb.blue, 1));
			pos.x /= 8;
			pos.y /= 5.5;
		}
	}
}

// Function to fire with the weapon
void	cub_fire(t_game *game, t_weapons *glock, t_sprite **sprites)
{
	int	i;

	i = -1;
	glock->firing = 1;
	if ((game->cubval->nb_col + game->cubval->nb_foe) == 0)
		return ;
	while (++i < (*sprites)[0].nbr_sprites)
	{
		if ((*sprites)[i].type != 'A' || (*sprites)[i].status == 0)
			continue ;
		else if ((*sprites)[i].in_sight > 0 && (*sprites)[i].hit == 0)
		{
			(*sprites)[i].hit = 1;
			(*sprites)[i].lives--;
		}
	}
}
