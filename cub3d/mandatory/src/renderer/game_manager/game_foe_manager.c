/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_foe_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:22:38 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/05 16:19:30 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to make the foe follow the player
void	cub_foe_pursuit(t_game *game, t_sprite *sprite, t_player *player)
{
	if (sprite->type != 'A' || sprite->status == 0)
		return ;
	sprite->tex_index += (int)(0.01 * game->fps.fps);
	cub_foe_setup_animations(sprite);
	if (sprite->hit == 1 || sprite->lives <= 0)
		return ;
	cub_foe_setup_pursuit(sprite, &sprite->pos_foe, &sprite->offset_add, \
		&sprite->offset_sub);
	cub_foe_perform_pursuit(game, sprite, player);
}

// Function to setup the animations
void	cub_foe_setup_animations(t_sprite *sprite)
{
	if (sprite->hit == 0 && sprite->tex_index * TEX_SIZE >= (TEX_SIZE * 7))
		sprite->tex_index = 0;
	if (sprite->hit == 1 && sprite->tex_index * TEX_SIZE <= (TEX_SIZE * 6))
		sprite->tex_index = 7;
	if (sprite->hit == 1 && sprite->tex_index * TEX_SIZE >= (TEX_SIZE * 10))
	{
		sprite->tex_index = 7;
		sprite->hit_time++;
		if (sprite->hit_time == 3)
		{
			sprite->tex_index = 0;
			sprite->hit = 0;
			sprite->hit_time = 0;
		}
	}
	if (sprite->lives <= 0 && sprite->tex_index * TEX_SIZE <= (TEX_SIZE * 9))
		sprite->tex_index = 10;
	if (sprite->lives <= 0 && sprite->tex_index * TEX_SIZE >= (TEX_SIZE * 14))
	{
		sprite->tex_index = 14;
		sprite->status = 0;
	}
}

// Function to setup the pursuit
void	cub_foe_setup_pursuit(t_sprite *sprite, t_point *pos,
			t_point *offset_add, t_point *offset_sub)
{
	pos->x = (int)sprite->pos.x >> 6;
	pos->y = (int)sprite->pos.y >> 6;
	offset_add->x = ((int)sprite->pos.x + 15) >> 6;
	offset_add->y = ((int)sprite->pos.y + 15) >> 6;
	offset_sub->x = ((int)sprite->pos.x - 15) >> 6;
	offset_sub->y = ((int)sprite->pos.y - 15) >> 6;
}

// Function to perform the pursuit
void	cub_foe_perform_pursuit(t_game *game, t_sprite *sprite,
			t_player *player)
{
	if (game->map.map[sprite->pos_foe.y * game->map.width \
		+ sprite->offset_sub.x] == '0' && sprite->pos.x > player->pos.x)
		sprite->pos.x -= FOE_SPEED * game->fps.fps;
	if (game->map.map[sprite->pos_foe.y * game->map.width + \
		sprite->offset_add.x] == '0' && sprite->pos.x < player->pos.x)
		sprite->pos.x += FOE_SPEED * game->fps.fps;
	if (game->map.map[sprite->offset_sub.y * game->map.width \
		+ sprite->pos_foe.x] == '0' && sprite->pos.y > player->pos.y)
		sprite->pos.y -= FOE_SPEED * game->fps.fps;
	if (game->map.map[sprite->offset_add.y * game->map.width \
		+ sprite->pos_foe.x] == '0' && sprite->pos.y < player->pos.y)
		sprite->pos.y += FOE_SPEED * game->fps.fps;
}
