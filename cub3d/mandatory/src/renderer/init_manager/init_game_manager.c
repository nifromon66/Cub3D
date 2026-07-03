/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/10 00:22:34 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to init game
void	cub_init_game_manager(t_game *game, t_cubval *cubval)
{
	cub_init_game_zero(game, cubval);
	cub_init_game_values(game, cubval);
	cub_init_graphics_manager(game, cubval);
	game->map = cub_init_map(cubval->map_str, cubval->max_xy, &game->player, \
		&game->sprite);
	game->minimap.map = cub_init_map(cubval->map_str, cubval->max_xy, \
		&game->player, &game->sprite);
	cub_init_minimap(&game->minimap);
}

// Function to set game initial values
void	cub_init_game_values(t_game *game, t_cubval *cubval)
{
	int	i;

	i = -1;
	while (++i < cubval->nb_col + cubval->nb_foe)
	{
		game->sprite[i].nbr_collectibles = cubval->nb_col;
		game->sprite[i].nbr_foes = cubval->nb_foe;
		game->sprite[i].nbr_sprites = cubval->nb_col + cubval->nb_foe;
	}
	game->glock.tex_index = 0;
	game->glock.firing = 0;
	game->status = 1;
	game->fps.fps = 0;
	game->player.collected = 0;
	game->fps.frame = cub_get_time_ms();
}

// Function to init game to zero
void	cub_init_game_zero(t_game *game, t_cubval *cubval)
{
	ft_memset(game, 0, sizeof(t_game));
	game->cubval = cubval;
	game->sprite = ft_calloc((cubval->nb_col + cubval->nb_foe), \
		sizeof(t_sprite));
	if (!game->sprite)
		return ((void)write(2, RED"Failed to allocate memory\n"RESET, 27));
	game->depth = ft_calloc(120, sizeof(int));
	if (!game->depth)
		return ((void)write(2, RED"Failed to allocate memory\n"RESET, 27));
}

// Function to print a map
void	cub_print_map(t_map *map)
{
	int	i;
	int	div;

	i = -1;
	div = 1;
	while (++i < map->width * map->height)
	{
		if (i / div == map->width)
		{
			printf("\n");
			div++;
		}
		printf("%c", map->map[i]);
	}
}
