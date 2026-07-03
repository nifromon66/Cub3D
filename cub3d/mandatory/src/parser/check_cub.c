/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:27:25 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/05 16:47:15 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// check if the line is a map line
int	is_map_line(char *line)
{
	int	i;
	int	has_map_char;

	i = 0;
	has_map_char = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			has_map_char = 1;
		else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (has_map_char);
}

///////////////////////////////////////////////////////////////////////////////
// check if the line contains only whitespace char
static int	line_is_not_empty(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// set the static int for map
static int	check_6pass(char *line, int is_ok[7], int *result)
{
	if (is_map_line(line))
	{
		if (!is_ok[6])
		{
			if (is_ok[0] && is_ok[1] && is_ok[2]
				&& is_ok[3] && is_ok[4] && is_ok[5])
				is_ok[6] = 1;
			else
				*result = 0;
		}
		return (1);
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// Set to PASS or return error form params
static int	set_config_flag(char *line, int is_ok[8])
{
	if (contain(line, "NO") && !is_ok[0])
		is_ok[0] = 1;
	else if (contain(line, "SO") && !is_ok[1])
		is_ok[1] = 1;
	else if (contain(line, "WE") && !is_ok[2])
		is_ok[2] = 1;
	else if (contain(line, "EA") && !is_ok[3])
		is_ok[3] = 1;
	else if (contain(line, "F") && !is_ok[4])
		is_ok[4] = 1;
	else if (contain(line, "C") && !is_ok[5])
		is_ok[5] = 1;
	else
		return (0);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// check and set to "PASS" a step (NO, SO, MAP etc) if present in line.
// if step already set to 1 or if during map parsing return Error
int	is_valid_cub(char *line)
{
	static int	is_ok[8];
	int			result;

	result = 1;
	if (check_6pass(line, is_ok, &result))
	{
		if (is_ok[7])
			return (0);
		else
			return (result);
	}
	if (!line_is_not_empty(line))
	{
		if (is_ok[6])
			is_ok[7] = 1;
		return (1);
	}
	if (is_ok[6])
		return (0);
	if (!set_config_flag(line, is_ok))
		result = 0;
	return (result);
}
