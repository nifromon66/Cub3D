/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:14 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/30 23:10:33 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
# elif __APPLE__
#  include <ApplicationServices/ApplicationServices.h>
# endif

# include "../../mlx/mlx.h"

/* libs */
# include "../../libft/headers/get_next_line_H/get_next_line.h"
# include "../../libft/headers/ft_printf_H/ft_printf.h"
# include "../../libft/headers/libft_H/libft.h"
# include "struct.h"
# include "utils.h"
# include "parser.h"
# include "renderer/renderer.h"

#endif