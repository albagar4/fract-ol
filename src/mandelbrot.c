/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:26 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/12 19:04:30 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	sucesion(double coords_x, double coords_y)
{
	t_comp	z;
	t_comp	c;
	int		count;
	double	temp;

	z.x = 0.0;
	z.y = 0.0;
	c.x = coords_x / ZOOM - 1.85;
	c.y = coords_y / ZOOM - 1;
	count = 0;
	while (count < 100)
	{
		temp = z.x;
		z.x = pow(z.x, 2) - pow(z.y, 2) + c.x;
		z.y = 2 * temp * z.y + c.y;
		if (pow(z.x, 2) + pow(z.y, 2) > INT32_MAX)
			break ;
		count++;
	}
	return (count);
}

void	mandelbrot(t_fractal *data, t_img *img, int width, int height)
{
	t_comp	coord;
	int		result;
	int		color;

	coord.x = 0.0;
	while (coord.x != width)
	{
		coord.y = 0.0;
		while (coord.y != height)
		{
			result = sucesion(coord.x, coord.y);
			if (result == 100)
				img_pixel_put(img, coord.x, coord.y, 0x000000);
			else
			{
				color = 0xFCBE11 * (result % 255);
				img_pixel_put(img, coord.x, coord.y, color);
			}
			coord.y++;
		}
		coord.x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
}
