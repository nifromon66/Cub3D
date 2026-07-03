/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprites_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:09:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/10 00:24:24 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to manager sprites
void	cub_sprites_manager(t_game *game, t_sprite **sprite, t_player *player)
{
	int	i;

	i = 0;
	if ((game->cubval->nb_col + game->cubval->nb_foe) == 0)
		return ;
	while (i < (*sprite)[0].nbr_sprites)
	{
		if ((*sprite)[i].status == 1 && (*sprite)[i].lives > 0)
		{
			cub_foe_pursuit(game, &((*sprite)[i]), player);
			cub_update_sprites(game, &((*sprite)[i]), player);
			cub_setup_sprites(&((*sprite)[i]), player);
			cub_render_sprites(game, &((*sprite)[i]));
		}
		i++;
	}
}

// Function to check interaction with sprites
void	cub_update_sprites(t_game *game, t_sprite *sprite, t_player *player)
{
	if (sprite->type == 'O' && sprite->status == 1
		&& player->pos.x < sprite->pos.x + 30
		&& player->pos.x > sprite->pos.x - 30
		&& player->pos.y < sprite->pos.y + 30
		&& player->pos.y > sprite->pos.y - 30)
	{
		sprite->status = 0;
		player->collected++;
	}
	if (sprite->type == 'A' && sprite->status == 1
		&& player->pos.x < sprite->pos.x + 30
		&& player->pos.x > sprite->pos.x - 30
		&& player->pos.y < sprite->pos.y + 30
		&& player->pos.y > sprite->pos.y - 30)
		game->status = 3;
}

// Function to setup the sprite
void	cub_setup_sprites(t_sprite *sprite, t_player *player)
{
	sprite->screen.x = sprite->pos.x - player->pos.x;
	sprite->screen.y = sprite->pos.y - player->pos.y;
	sprite->screen.z = sprite->pos.z;
	sprite->cosinus = cos(cub_degtorad(player->angle));
	sprite->sinus = sin(cub_degtorad(player->angle));
	sprite->a = sprite->screen.y * sprite->cosinus
		+ sprite->screen.x * sprite->sinus;
	sprite->b = sprite->screen.x * sprite->cosinus
		- sprite->screen.y * sprite->sinus;
	sprite->screen.x = sprite->a;
	sprite->screen.y = sprite->b;
	sprite->screen.x = (sprite->screen.x * 108.0 / sprite->screen.y)
		+ (120 / 2);
	sprite->screen.y = (sprite->screen.z * 108.0 / sprite->screen.y)
		+ (80 / 2);
	sprite->scale = 32 * 80 / sprite->b;
	if (sprite->scale < 0)
		sprite->scale = 0;
	if (sprite->scale > 120)
		sprite->scale = 120;
}

// Function to render the sprites
void	cub_render_sprites(t_game *game, t_sprite *sprite)
{
	sprite->tex.x = 0;
	sprite->in_sight = 0;
	sprite->tex.y = 31.0;
	sprite->tex_step.x = 31.5 / (float)sprite->scale;
	sprite->tex_step.y = 32.0 / (float)sprite->scale;
	sprite->pos2.x = (sprite->screen.x - sprite->scale / 2) - 1;
	while (++sprite->pos2.x < sprite->screen.x + sprite->scale / 2)
	{
		sprite->tex.y = 31.0;
		sprite->pos2.y = -1;
		while (++sprite->pos2.y < sprite->scale)
			cub_render_sprites_loop(game, sprite);
		sprite->tex.x += sprite->tex_step.x;
	}
}

// Function to help render the sprites
void	cub_render_sprites_loop(t_game *game, t_sprite *sprite)
{
	if (sprite->pos2.x > 0 && sprite->pos2.x < 120 \
		&& sprite->b < game->depth[sprite->pos2.x])
	{
		sprite->pixel = ((int)sprite->tex.y * 32 + (int)sprite->tex.x) * 3 \
			+ (sprite->tex_index * (TEX_SIZE));
		sprite->rgb.red = sprite->texture[sprite->pixel + 0];
		sprite->rgb.green = sprite->texture[sprite->pixel + 1];
		sprite->rgb.blue = sprite->texture[sprite->pixel + 2];
		sprite->pos_draw.x = sprite->pos2.x * 8;
		sprite->pos_draw.y = (sprite->screen.y * 8) - (sprite->pos2.y * 8);
		if (!cub_is_transparent(sprite->rgb.red, sprite->rgb.green, \
			sprite->rgb.blue))
		{
			cub_draw_point(&game->img, sprite->pos_draw, 8, \
				cub_convert_glrgb(sprite->rgb.red, sprite->rgb.green, \
					sprite->rgb.blue, 1));
		}
		sprite->tex.y -= sprite->tex_step.y;
		if (sprite->tex.y < 0)
			sprite->tex.y = 0;
		if (sprite->pos2.x == 60)
			sprite->in_sight++;
	}
}
