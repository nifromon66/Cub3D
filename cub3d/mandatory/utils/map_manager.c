/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:08:03 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/05 14:45:59 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// Function for clean a char **
void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

///////////////////////////////////////////////////////////////////////////////
// function for add a char * to a char ** (.add in javascript)
char	**add_to_tab(char **tab, char *new_line)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = new_line;
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}

///////////////////////////////////////////////////////////////////////////////
// Function for edit a line of map and return it
static char	*fill_line(char *line, int width)
{
	char	*new_line;
	int		i;

	new_line = malloc(sizeof(char) * (width + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n' && i < width)
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < width - 1)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

///////////////////////////////////////////////////////////////////////////////
// Function to normalize a map (adds spaces to equalize all line lengths)
char	**square_map(char **map)
{
	char	**new_map;
	int		x_max;
	int		y_max;
	int		i;

	y_max = get_y_max(map);
	x_max = get_x_max(map);
	new_map = malloc(sizeof(char *) * (y_max + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < y_max)
	{
		new_map[i] = fill_line(map[i], x_max);
		if (!new_map[i])
			return (NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
