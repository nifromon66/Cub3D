/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_line_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:19:51 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/30 21:20:49 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to draw a line between two points using bresenham's line algorithm
void	cub_draw_line(t_img_data *img, t_pos start, t_pos end, int color)
{
	t_pos	delta;
	t_pos	pixel;
	int		lenght;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	lenght = sqrt(pow(delta.x, 2) + pow(delta.y, 2));
	delta.x /= lenght;
	delta.y /= lenght;
	pixel.x = start.x;
	pixel.y = start.y;
	while (lenght)
	{
		cub_draw_pixel(img, pixel.x, pixel.y, color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		lenght--;
	}
}

// Function to draw lines with thickness
void	cub_draw_thick_line(t_img_data *img, t_segment *segment, int size,
			int color)
{
	t_pos	start;
	t_pos	end;
	int		i;
	int		j;
	int		half_size;

	half_size = size / 2;
	j = -half_size - 1;
	while (++j <= half_size)
	{
		i = -half_size - 1;
		while (++i <= half_size)
		{
			start.x = segment->start.x + i;
			start.y = segment->start.y + j;
			end.x = segment->end.x + i;
			end.y = segment->end.y + j;
			cub_draw_line(img, start, end, color);
		}
	}
}
