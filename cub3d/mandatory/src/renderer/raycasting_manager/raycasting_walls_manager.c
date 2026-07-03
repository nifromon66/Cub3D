/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_walls_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:24:33 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/09 18:43:31 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to render the walls
void	cub_rays_draw_walls(t_img_data *img, t_rays *rays, t_walls *walls,
			int *texture)
{
	rays->draw_index = -1;
	walls->ty = walls->offset * walls->step;
	while (++rays->draw_index < rays->line_height)
	{
		walls->pixel = (((int)walls->ty * 32) + (int)walls->tx) * 3;
		walls->rgb.red = texture[walls->pixel + 0];
		walls->rgb.green = texture[walls->pixel + 1];
		walls->rgb.blue = texture[walls->pixel + 2];
		cub_draw_pixel(img, rays->draw.x - 8, \
			rays->draw_index + rays->draw.y, \
				cub_convert_glrgb(walls->rgb.red, walls->rgb.green, \
					walls->rgb.blue, 1));
		walls->ty += walls->step;
	}
}
