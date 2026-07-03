/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:52:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/02 23:24:27 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to draw a pixel on the image
void	cub_draw_pixel(t_img_data *img, int x, int y, int color)
{
	int	pixel;

	if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || x < 0 || y < 0)
		return ;
	pixel = y * img->line_len + x * (img->bpp / 8);
	img->addr[pixel] = color & 0xFF;
	img->addr[pixel + 1] = (color >> 8) & 0xFF;
	img->addr[pixel + 2] = (color >> 16) & 0xFF;
}

// Function to draw a point of fixed size
void	cub_draw_point(t_img_data *img, t_pos pos, int size, int color)
{
	int	half_size;
	int	i;
	int	j;

	half_size = size / 2;
	j = -half_size - 1;
	while (++j <= half_size)
	{
		i = -half_size - 1;
		while (++i <= half_size)
			cub_draw_pixel(img, pos.x + i, pos.y + j, color);
	}
}

// Function to draw a square
void	cub_draw_empty_square(t_img_data *img, t_pos pos, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x + i, pos.y, color);
	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x, pos.y + i, color);
	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x + size, pos.y + i, color);
	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x + i, pos.y + size, color);
}

// Function to draw a filled square
void	cub_draw_filled_square(t_img_data *img, t_pos pos, int size, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			cub_draw_pixel(img, pos.x + x, pos.y + y, color);
	}
}
