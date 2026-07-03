/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:06 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/01 14:24:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub.h"

/* structure des coordonées */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/* structure des infos en sortie de .cub */
typedef struct s_cubval
{
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_e;
	char	*f;
	char	*c;
	char	**map;
	char	*map_str;
	t_point	spawn;
	t_point	max_xy;
	int		nb_col;
	int		nb_foe;
}	t_cubval;

#endif