/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:14:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/06 13:16:02 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// Check if the path point to .cub file
static int	is_ext_file(char *path, char *ext)
{
	size_t	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < ft_strlen(ext))
		return (0);
	return (ft_strcmp(path + len - ft_strlen(ext), ext) == 0);
}

///////////////////////////////////////////////////////////////////////////////
// Open map and set predatas (unFixed datas)
t_cubval	*open_and_conf(char *path)
{
	char		*line;
	int			fd;
	t_cubval	*predat;

	if (!is_ext_file(path, ".cub"))
		return (printf("Error: file is not .cub\n"), NULL);
	predat = malloc(sizeof(t_cubval));
	if (!predat)
		return (NULL);
	*predat = (t_cubval){};
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (printf("Error: file can't be open.\n"), \
			clean_tcubval(predat), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_valid_cub(line))
			return (printf("Error: format isn't valid !\n"), \
				pull_gnl(fd, line), clean_tcubval(predat), close(fd), NULL);
		get_all(line, predat);
		line = get_next_line(fd);
	}
	close(fd);
	return (predat);
}

static int	is_one_ppm(char *path)
{
	int	fd;

	if (!is_ext_file(path, ".ppm"))
		return (printf("Error: textures need to be .ppm !\n"), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (printf("Error: there is no .ppm at : %s\n", path), 0);
	close(fd);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Function for check if all texture is RGB .ppm file
int	are_all_ppm(t_cubval *cubval)
{
	if (!is_one_ppm(cubval->path_n))
		return (0);
	if (!is_one_ppm(cubval->path_s))
		return (0);
	if (!is_one_ppm(cubval->path_w))
		return (0);
	if (!is_one_ppm(cubval->path_w))
		return (0);
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// Clean t_cubVal after usage
void	clean_tcubval(t_cubval *cubval)
{
	if (!cubval)
		return ;
	if (cubval->c)
		free(cubval->c);
	if (cubval->f)
		free(cubval->f);
	if (cubval->path_n)
		free(cubval->path_n);
	if (cubval->path_s)
		free(cubval->path_s);
	if (cubval->path_e)
		free(cubval->path_e);
	if (cubval->path_w)
		free(cubval->path_w);
	if (cubval->map_str)
		free(cubval->map_str);
	free_tab(cubval->map);
	free(cubval);
}
