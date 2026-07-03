/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapping_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:38:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/07 22:34:02 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to init the minimap
void	cub_init_minimap(t_minimap *minimap)
{
	minimap->radius = MINI_RADIUS;
	minimap->center.x = SCREEN_WIDTH - minimap->radius - 10;
	minimap->center.y = minimap->radius + 10;
}

// Function to init a map
t_map	cub_init_map(char *source, t_point max, t_player *player,
			t_sprite **sprite)
{
	t_map	dest;
	int		i;

	dest.door_opened = 0;
	dest.width = max.x;
	dest.height = max.y;
	dest.map = ft_calloc((max.x * max.y) + 1, sizeof(char));
	if (!dest.map)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), dest);
	i = -1;
	while (++i < (max.x * max.y))
	{
		if (source[i] == 'N' || source[i] == 'S'
			|| source[i] == 'W' || source[i] == 'E'
			|| source[i] == 'A' || source[i] == 'O')
		{
			cub_init_sprites(i, max.x, source[i], sprite);
			cub_init_player_position(i, max.x, source[i], player);
			dest.map[i] = '0';
		}
		else
			dest.map[i] = source[i];
	}
	dest.map[i] = '\0';
	return (dest);
}

// Function to init the player position
void	cub_init_player_position(int pos, int width, char orientation,
			t_player *player)
{
	if (orientation == 'N')
		player->angle = 0 + 90;
	else if (orientation == 'S')
		player->angle = 180 + 90;
	else if (orientation == 'W')
		player->angle = 270 + 90;
	else if (orientation == 'E')
		player->angle = 90 + 90;
	else
		return ;
	player->pos.x = (((pos % width) + 0.5) * 64);
	player->pos.y = (((pos / width) + 0.5) * 64);
	player->delta.x = cos(cub_degtorad(player->angle));
	player->delta.y = -sin(cub_degtorad(player->angle));
}

// Function to init the sprites position
void	cub_init_sprites(int pos, int width, int type, t_sprite **sprite)
{
	static int	index = 0;

	if ((type != 'O' && type != 'A')
		|| index > (*sprite)[0].nbr_sprites - 1)
		return ;
	if (type == 'O')
		(*sprite)[index].texture = cub_create_textures(KEY, TEX_SIZE);
	else
		(*sprite)[index].texture = cub_create_textures(CLOWN_RUN, \
			TEX_SIZE * 14);
	(*sprite)[index].type = type;
	(*sprite)[index].hit = 0;
	(*sprite)[index].hit_time = 0;
	(*sprite)[index].lives = 3;
	(*sprite)[index].in_sight = 0;
	(*sprite)[index].tex_index = 0;
	(*sprite)[index].status = 1;
	(*sprite)[index].map = 0;
	(*sprite)[index].pos.x = (((pos % width) + 0.5) * 64);
	(*sprite)[index].pos.y = (((pos / width) + 0.5) * 64);
	(*sprite)[index].pos.z = 20;
	index++;
}
