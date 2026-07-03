/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/10 01:11:05 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to loop and render the game
int	cub_game_manager(t_game *game)
{
	cub_game_fps(&game->fps);
	game->player.speed = SPEED * game->fps.fps;
	game->img.ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	cub_game_running(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.ptr);
	return (0);
}

// Function to run the game
void	cub_game_running(t_game *game)
{
	if (game->map.map[(int)(((int)(game->player.pos.y / 64) * game->map.width \
		+ (int)(game->player.pos.x / 64)))] == 'L')
		game->status = 2;
	if (game->status == 1)
	{
		cub_render_fullscreens(game, &game->screen, game->status);
		game->screen.timer += 1 * game->fps.fps;
		if (game->screen.timer > 3000)
			game->status = 0;
	}
	else if (game->status == 0)
	{
		cub_movement_update(&game->keys, &game->player, &game->map);
		cub_automatics_close_door(game, &game->map, &game->minimap.map);
		cub_raycasting_manager(game, &game->rays, &game->player);
		cub_render_minimap(game, &game->map, &game->minimap,
			cub_convert_glrgb(255, 255, 255, 1));
		cub_sprites_manager(game, &game->sprite, &game->player);
		cub_weapons_manager(game, &game->glock);
	}
	else if (game->status == 2 || game->status == 3)
		cub_render_fullscreens(game, &game->screen, game->status);
}

// Function to calculate fps
void	cub_game_fps(t_fps *fps)
{
	fps->old_frame = fps->frame;
	fps->frame = cub_get_time_ms();
	fps->fps = fps->frame - fps->old_frame;
}
