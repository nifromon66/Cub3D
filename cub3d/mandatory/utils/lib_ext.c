/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:36:36 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/06 13:35:04 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// function for check if a char * contain an other char *
int	contain(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!str || !to_find)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return (1);
		i++;
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// check if c is a whitespace
int	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

///////////////////////////////////////////////////////////////////////////////
// pull and free gnl
void	pull_gnl(int fd, char *line)
{
	char	*temp;

	free(line);
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}
