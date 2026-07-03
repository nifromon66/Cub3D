/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/06 13:26:14 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// check if there is not more and lot less than 1 spawn in map
static int	check_spawn(t_cubval *cubval)
{
	int	counter;
	int	x;
	int	y;

	counter = 0;
	y = 0;
	while (y < cubval->max_xy.y)
	{
		x = 0;
		while (x < cubval->max_xy.x)
		{
			if (is_spawn(cubval->map[y][x]))
			{
				counter++;
				cubval->spawn.x = x;
				cubval->spawn.y = y;
			}
			x++;
		}
		y++;
	}
	if (counter == 1)
		return (1);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// check if the border of map are corretly closed
static int	checkis_closed(t_cubval *cubval, char **t_map)
{
	int	y;
	int	x;

	y = 0;
	while (t_map[y])
	{
		x = 0;
		while (t_map[y][x])
		{
			if (cubval->map[y][x] == ' ' && t_map[y][x] == 'X')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// check if a string is a valid rgb str.
static int	is_valid_rgb_format(char *s)
{
	int	i;
	int	nb;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		nb = 0;
		if (s[i] < '0' || s[i] > '9')
			return (0);
		while (s[i] >= '0' && s[i] <= '9')
		{
			nb = nb * 10 + (s[i] - '0');
			if (nb > 255)
				return (0);
			i++;
		}
		if (++count < 3 && s[i++] != ',')
			return (0);
	}
	return (count == 3);
}

///////////////////////////////////////////////////////////////////////////////
// Check the conformity of map before printing
///////////////////////////////////////////////////////////////////////////////
// Check the conformity of map before printing
static int	check_all(t_cubval *cubval)
{
	char	**temp;
	int		result;

	result = 1;
	if (!is_valid_rgb_format(cubval->c))
		return (ft_printf("Error: bad RGB colors.\n"), 0);
	if (!is_valid_rgb_format(cubval->f))
		return (ft_printf("Error: bad RGB colors.\n"), 0);
	if (!are_all_ppm(cubval))
		return (ft_printf("Error: with textures.\n"), 0);
	if (!check_spawn(cubval))
		return (ft_printf("Error: nbSpawn < 1 or > 1 !\n"), 0);
	if (!check_exit(cubval))
		return (ft_printf("Error: nbExit < 1 or > 1 !\n"), 0);
	temp = square_map(cubval->map);
	count_item(cubval, 'O', 'A');
	fill(temp, cubval->spawn, cubval->max_xy, "NSWE0DLOA ");
	result = checkis_closed(cubval, temp);
	free_tab(temp);
	if (!result)
		return (ft_printf("Error: the map is not properly closed !\n"), 0);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Get params and map, check them and give them to printer
t_cubval	*get_map_param(char *path)
{
	t_cubval	*temp;
	t_cubval	*result;
	char		**map;

	temp = open_and_conf(path);
	if (!temp)
		return (NULL);
	result = fix_all(temp);
	if (!result)
		return (clean_tcubval(result), NULL);
	map = result->map;
	if (!map)
		return (clean_tcubval(result), NULL);
	result->max_xy = (t_point){get_x_max(map), get_y_max(map)};
	result->map_str = inline_map(map);
	if (check_all(result))
		return (result);
	return (clean_tcubval(result), NULL);
}
