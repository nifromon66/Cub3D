/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_fullscreens_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:02:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 00:14:34 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to render the full screens
void	cub_render_fullscreens(t_game *game, t_screen *screen, int status)
{
	screen->tex_index = 0;
	if (status == 0)
		return ;
	else if (status == 3)
		screen->tex_index = SCREEN_TEX_SIZE;
	else if (status == 2)
		screen->tex_index = SCREEN_TEX_SIZE * 2;
	screen->pos.y = -1;
	while (++screen->pos.y < SCREEN_TEX_HEIGHT)
	{
		screen->pos.x = -1;
		while (++screen->pos.x < SCREEN_TEX_WIDTH)
			cub_render_fullscreens_loop(&game->img, screen);
	}
}

// Function to help render the fullscreens
void	cub_render_fullscreens_loop(t_img_data *img, t_screen *screen)
{
	screen->pixel = (screen->pos.y * SCREEN_TEX_WIDTH + screen->pos.x) \
		* 3 + screen->tex_index;
	screen->rgb.red = screen->tex[screen->pixel + 0];
	screen->rgb.green = screen->tex[screen->pixel + 1];
	screen->rgb.blue = screen->tex[screen->pixel + 2];
	screen->pos.x *= 1.6;
	screen->pos.y *= 1.9;
	cub_draw_point(img, screen->pos, 2, \
		cub_convert_glrgb(screen->rgb.red, screen->rgb.green, screen->rgb.blue, \
			1));
	screen->pos.x /= 1.6;
	screen->pos.y /= 1.9;
}
