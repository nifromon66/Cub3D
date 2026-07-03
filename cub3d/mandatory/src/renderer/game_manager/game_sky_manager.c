/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sky_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:03:53 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/02 22:27:25 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to render the sky
void	cub_render_sky(t_img_data *img, t_sky *sky, t_player *player)
{
	t_pos	pos;

	pos.y = -1;
	while (++pos.y < SKY_HEIGHT)
	{
		pos.x = -1;
		while (++pos.x < SKY_WIDTH)
		{
			sky->offset = (int)player->angle * 0.5 - pos.x;
			if (sky->offset < 0)
				sky->offset += SKY_WIDTH;
			sky->offset %= SKY_WIDTH;
			sky->pixel = (pos.y * SKY_WIDTH + sky->offset) * 3
				+ (0 * SKY_WIDTH * SKY_HEIGHT * 3);
			cub_render_sky_layers(img, sky, pos);
			sky->pixel = (pos.y * SKY_WIDTH + pos.x) * 3
				+ (1 * SKY_WIDTH * SKY_HEIGHT * 3);
			cub_render_sky_layers(img, sky, pos);
			sky->pixel = (pos.y * SKY_WIDTH + sky->offset) * 3
				+ (2 * SKY_WIDTH * SKY_HEIGHT * 3);
			cub_render_sky_layers(img, sky, pos);
		}
	}
}

// Function to render different layers of the sky
void	cub_render_sky_layers(t_img_data *img, t_sky *sky, t_pos pos)
{
	sky->rgb.red = sky->tex[sky->pixel + 0];
	sky->rgb.green = sky->tex[sky->pixel + 1];
	sky->rgb.blue = sky->tex[sky->pixel + 2];
	pos.x = (pos.x * SKY_OFFSET) + SKY_OFFSET_PLUS;
	pos.y = (pos.y * SKY_OFFSET) - SCREEN_HEIGHT / SKY_OFFSET_SCREEN;
	if (cub_convert_glrgb(sky->rgb.red, sky->rgb.green, sky->rgb.blue, 1)
		!= cub_convert_glrgb(255, 0, 255, 1))
		cub_draw_point(img, pos, SKY_OFFSET,
			cub_convert_glrgb(sky->rgb.red, sky->rgb.green, sky->rgb.blue, 1));
	pos.x = (pos.x - SKY_OFFSET_PLUS) / SKY_OFFSET;
	pos.y = (pos.y + SCREEN_HEIGHT / SKY_OFFSET_SCREEN) / SKY_OFFSET;
}
