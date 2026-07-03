/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_minimap_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:39:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/03 01:05:49 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to draw the player in 2D
void	cub_render_minimap_player(t_game *game, t_pos center, int radius,
			int color)
{
	t_segment	segment;
	t_pos		player_screen;
	t_pos		draw_end;
	int			dx;
	int			dy;

	player_screen.x = center.x;
	player_screen.y = center.y;
	dx = player_screen.x - center.x;
	dy = player_screen.y - center.y;
	if (dx * dx + dy * dy <= radius * radius)
		cub_draw_point(&game->img, player_screen, MINI_PLAYER, color);
	draw_end.x = center.x + game->player.delta.x * 10;
	draw_end.y = center.y + game->player.delta.y * 10;
	segment.start = center;
	segment.end = draw_end;
	cub_draw_thick_line(&game->img, &segment, MINI_PLAYER / 3, color);
}

// Function to draw the minimap
void	cub_render_minimap(t_game *game, t_map *map, t_minimap *minimap,
			int color)
{
	minimap->pos_map.y = -1;
	while (++minimap->pos_map.y < map->height)
	{
		minimap->pos_map.x = -1;
		while (++minimap->pos_map.x < map->width)
		{
			cub_render_setup_minimap(game, minimap, map);
			if (minimap->within_radius)
				cub_render_minimap_loop(game, minimap, map, color);
		}
	}
	cub_render_minimap_player(game, minimap->center, minimap->radius, \
		cub_convert_glrgb(0, 255, 255, 1));
	cub_draw_empty_circle(&game->img, minimap->center, minimap->radius, \
		cub_convert_glrgb(255, 255, 255, 1));
}

// Function to help render the minimap
void	cub_render_minimap_loop(t_game *game, t_minimap *minimap, t_map *map,
			int color)
{
	if (map->map[(int)minimap->mp] == '1')
		cub_draw_filled_square(&game->img, \
			minimap->pos_screen, MINI_BLOCK, color);
	else if (minimap->map.map[(int)minimap->mp] == 'D' \
		&& map->map[(int)minimap->mp] == 'D')
		cub_draw_filled_square(&game->img, \
			minimap->pos_screen, MINI_BLOCK, cub_convert_glrgb(255, 0, 0, 1));
	else if (minimap->map.map[(int)minimap->mp] == 'D' \
		&& map->map[(int)minimap->mp] == '0')
		cub_draw_empty_square(&game->img, \
			minimap->pos_screen, MINI_BLOCK, cub_convert_glrgb(0, 255, 0, 1));
	else if (map->map[(int)minimap->mp] == 'L')
		cub_draw_filled_square(&game->img, \
			minimap->pos_screen, MINI_BLOCK, cub_convert_glrgb(255, 255, 0, 1));
}

// Function to setup the minimap
void	cub_render_setup_minimap(t_game *game, t_minimap *minimap, t_map *map)
{
	int	i;
	int	j;

	minimap->mp = minimap->pos_map.y * map->width + minimap->pos_map.x;
	minimap->pos_screen.x = minimap->center.x \
		+ (minimap->pos_map.x - game->player.pos.x / 64) * MINI_BLOCK;
	minimap->pos_screen.y = minimap->center.y \
		+ (minimap->pos_map.y - game->player.pos.y / 64) * MINI_BLOCK;
	minimap->within_radius = 1;
	j = 0;
	while (j <= MINI_BLOCK)
	{
		i = 0;
		while (i <= MINI_BLOCK)
		{
			minimap->dir.x = minimap->pos_screen.x + j - minimap->center.x;
			minimap->dir.y = minimap->pos_screen.y + i - minimap->center.y;
			if (pow(minimap->dir.x, 2) + pow(minimap->dir.y, 2) \
				> pow(minimap->radius, 2))
				minimap->within_radius = 0;
			i += MINI_BLOCK;
		}
		j += MINI_BLOCK;
	}
}
