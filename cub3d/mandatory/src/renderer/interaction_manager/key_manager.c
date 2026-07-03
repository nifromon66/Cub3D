/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:12:17 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/09 19:06:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to handle keys
int	cub_handle_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		cub_free_manager(game);
		exit(0);
	}
	else if (key == KEY_W)
		game->keys.w = 1;
	else if (key == KEY_ARROW_LEFT)
		game->keys.arrow_left = 1;
	else if (key == KEY_S)
		game->keys.s = 1;
	else if (key == KEY_ARROW_RIGHT)
		game->keys.arrow_right = 1;
	else if (key == KEY_A)
		game->keys.a = 1;
	else if (key == KEY_D)
		game->keys.d = 1;
	else if (key == KEY_E)
		cub_action_manager(OPEN_DOOR, &game->player, &game->map);
	return (0);
}

int	cub_handle_key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->keys.w = 0;
	else if (key == KEY_ARROW_LEFT)
		game->keys.arrow_left = 0;
	else if (key == KEY_S)
		game->keys.s = 0;
	else if (key == KEY_ARROW_RIGHT)
		game->keys.arrow_right = 0;
	else if (key == KEY_A)
		game->keys.a = 0;
	else if (key == KEY_D)
		game->keys.d = 0;
	return (0);
}
