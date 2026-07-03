/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:52:19 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/30 23:07:27 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// Get the max x of the map
int	get_x_max(char **map)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
			len++;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

///////////////////////////////////////////////////////////////////////////////
// Get the max y of the map
int	get_y_max(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

///////////////////////////////////////////////////////////////////////////////
// check if the a given position is a spawn
int	is_spawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

/////////////////////////////////////////////////////////////////////////////
// fill function (like flood_fill) for know if all position are accessible
void	fill(char **map, t_point begin, t_point max, char *charset)
{
	if (begin.x >= max.x || begin.y >= max.y || begin.x < 0 || begin.y < 0
		|| ft_strchr(charset, map[begin.y][begin.x]) == NULL)
		return ;
	map[begin.y][begin.x] = 'X';
	fill(map, (t_point){begin.x - 1, begin.y}, max, charset);
	fill(map, (t_point){begin.x + 1, begin.y}, max, charset);
	fill(map, (t_point){begin.x, begin.y - 1}, max, charset);
	fill(map, (t_point){begin.x, begin.y + 1}, max, charset);
}

///////////////////////////////////////////////////////////////////////////////
// convert from char ** to char *
char	*inline_map(char **map)
{
	char	*result;
	int		i;
	int		y;
	int		x;

	result = malloc(sizeof(char) * (get_x_max(map) * get_y_max(map) + 1));
	if (!result)
		return (NULL);
	y = 0;
	i = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			result[i] = map[y][x];
			x++;
			i++;
		}
		y++;
	}
	result[i] = '\0';
	return (result);
}
