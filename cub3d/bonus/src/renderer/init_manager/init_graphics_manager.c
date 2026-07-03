/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:37:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/03 09:26:06 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to init all the graphics
void	cub_init_graphics_manager(t_game *game, t_cubval *cubval)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->walls.tex_north = cub_create_textures(cubval->path_n, TEX_SIZE);
	game->walls.tex_south = cub_create_textures(cubval->path_s, TEX_SIZE);
	game->walls.tex_east = cub_create_textures(cubval->path_e, TEX_SIZE);
	game->walls.tex_west = cub_create_textures(cubval->path_w, TEX_SIZE);
	game->walls.tex_door = cub_create_textures(DOOR, TEX_SIZE);
	game->walls.tex_leave = cub_create_textures(LEAVE_WALL, TEX_SIZE);
	game->sky.tex_layers[0] = cub_create_textures(SKY_BACKGROUND, SKY_SIZE);
	game->sky.tex_layers[1] = cub_create_textures(SKY_MOON, SKY_SIZE);
	game->sky.tex_layers[2] = cub_create_textures(SKY_CLOUDS, SKY_SIZE);
	game->sky.tex = cub_join_textures(game->sky.tex_layers, SKY_SIZE, \
		SKY_LAYERS);
	game->screen.tex_layers[0] = cub_create_textures(SCREEN_START, \
		SCREEN_TEX_SIZE);
	game->screen.tex_layers[1] = cub_create_textures(SCREEN_LOSE, \
		SCREEN_TEX_SIZE);
	game->screen.tex_layers[2] = cub_create_textures(SCREEN_WIN, \
		SCREEN_TEX_SIZE);
	game->screen.tex = cub_join_textures(game->screen.tex_layers, \
		SCREEN_TEX_SIZE, 3);
	game->joists.tex_leave = cub_create_textures(LEAVE, TEX_SIZE);
	game->joists.rgb_floor = cub_init_colors(cubval->f);
	game->joists.rgb_ceiling = cub_init_colors(cubval->c);
	game->glock.texture = cub_create_textures(GLOCK, WEAPON_SIZE * 7);
}

// Function to create al textures
int	*cub_create_textures(const char *file, int size)
{
	int		*texture;
	int		fd;
	char	*line;
	int		t;

	texture = ft_calloc(size, sizeof(int));
	if (!texture)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), texture);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(2, RED"Couldn't open file\n"RESET, 20), texture);
	t = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		texture[++t] = ft_atoi(line);
		free(line);
	}
	close(fd);
	return (texture);
}

// Function to join all textures in one
int	*cub_join_textures(int **textures, int size, int nbr)
{
	int	*joined;
	int	i;
	int	j;
	int	k;

	joined = ft_calloc(size * nbr, sizeof(int));
	if (!joined)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), \
			textures[0]);
	j = 0;
	k = 0;
	while (j < nbr)
	{
		i = 0;
		while (i < size)
		{
			joined[k] = textures[j][i];
			i++;
			k++;
		}
		free(textures[j]);
		j++;
	}
	return (joined);
}

// Function to init colors
t_rgb	cub_init_colors(char *source)
{
	t_rgb	dest;
	int		i;

	i = -1;
	dest.red = 0;
	dest.green = 0;
	dest.blue = 0;
	while (source[++i] && source[i] != ',')
		dest.red = dest.red * 10 + source[i] - '0';
	while (source[++i] && source[i] != ',')
		dest.green = dest.green * 10 + source[i] - '0';
	while (source[++i] && source[i] != ',')
		dest.blue = dest.blue * 10 + source[i] - '0';
	return (dest);
}
