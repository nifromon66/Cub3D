/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:12:56 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/30 23:07:29 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// count nb a char for newStr of fixParam
int	count_clean(char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (!is_ws(s[i]))
			len++;
		i++;
	}
	return (len);
}

///////////////////////////////////////////////////////////////////////////////
// check if exit for bonus (like in so_long)
int	check_exit(t_cubval *cubval)
{
	int	counter;
	int	x;
	int	y;

	counter = 0;
	y = 0;
	while (cubval->map[y])
	{
		x = 0;
		while (x < cubval->map[y][x])
		{
			if (cubval->map[y][x] == 'L')
			{
				counter++;
			}
			x++;
		}
		y++;
	}
	if (counter == 1)
		return (1);
	return (0);
}
