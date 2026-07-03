/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:23:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/10 01:14:51 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to free all memory
void	cub_free_manager(t_game *game)
{
	if (!game)
		return ;
	if (game->depth)
		free(game->depth);
	if (game->map.map)
		free(game->map.map);
	if (game->minimap.map.map)
		free(game->minimap.map.map);
	cub_free_graphics(game);
	cub_free_sprites(&game->sprite, \
		(game->cubval->nb_col + game->cubval->nb_foe));
	if (game->mlx && game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->cubval)
		clean_tcubval(game->cubval);
}

// Function to free all graphics
void	cub_free_graphics(t_game *game)
{
	if (game->walls.tex_leave)
		free(game->walls.tex_leave);
	if (game->walls.tex_door)
		free(game->walls.tex_door);
	if (game->walls.tex_west)
		free(game->walls.tex_west);
	if (game->walls.tex_east)
		free(game->walls.tex_east);
	if (game->walls.tex_south)
		free(game->walls.tex_south);
	if (game->walls.tex_north)
		free(game->walls.tex_north);
	if (game->sky.tex)
		free(game->sky.tex);
	if (game->screen.tex)
		free(game->screen.tex);
	if (game->joists.tex_leave)
		free(game->joists.tex_leave);
	if (game->glock.texture)
		free(game->glock.texture);
}

// Function to free all sprites
void	cub_free_sprites(t_sprite **sprites, int nbr_sprites)
{
	int	i;

	i = -1;
	if (!sprites || !*sprites)
		return ;
	while (++i < nbr_sprites)
	{
		if ((*sprites)[i].texture)
			free((*sprites)[i].texture);
	}
	free((*sprites));
}
