/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:20:04 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/03 00:02:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// Function to convert degree to radian
float	cub_degtorad(float degree)
{
	return (degree * (M_PI / 180.0));
}

// Function to fix the angle
float	cub_fixang(float angle)
{
	if (angle > 359)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

// Function to calculate the distance between two points
float	cub_calc_dist(t_pos a, t_pos b, float angle)
{
	return (cos(cub_degtorad(angle)) * (b.x - a.x)
		- sin(cub_degtorad(angle)) * (b.y - a.y));
}

// Function to convert gl colors to rgb and rgb into colors
int	cub_convert_glrgb(float red, float green, float blue, int mode)
{
	int	r;
	int	g;
	int	b;

	if (mode == 0)
	{
		r = (int)(red * 255.0);
		g = (int)(green * 255.0);
		b = (int)(blue * 255.0);
		return ((r << 16) | (g << 8) | b);
	}
	return (((int)red << 16) | ((int)green << 8) | (int)blue);
}

// Function to check if background is transparent
int	cub_is_transparent(float red, float green, float blue)
{
	float	tolerance;

	tolerance = 5.0f;
	return (fabsf(red - 255.0f) < tolerance \
		&& fabsf(green - 0.0f) < tolerance \
		&& fabsf(blue - 255.0f) < tolerance);
}
