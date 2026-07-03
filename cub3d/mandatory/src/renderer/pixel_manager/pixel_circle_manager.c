/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_circle_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:20:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/02 23:24:11 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Draw the circle of the minimap border
void	cub_draw_empty_circle(t_img_data *img, t_pos center, int radius,
			int color)
{
	t_point	pos;
	t_point	dir;
	int		r2;
	int		thickness;
	int		dist2;

	r2 = radius * radius;
	thickness = 2;
	pos.y = (-radius) - 1;
	while (++pos.y <= radius)
	{
		pos.x = (-radius) - 1;
		while (++pos.x <= radius)
		{
			dir.x = center.x + pos.x;
			dir.y = center.y + pos.y;
			dist2 = pos.x * pos.x + pos.y * pos.y;
			if (dist2 >= r2 - thickness * radius && dist2 <= r2 \
				+ thickness * radius)
				cub_draw_pixel(img, dir.x, dir.y, color);
		}
	}
}
