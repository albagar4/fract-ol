/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:26 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/08 15:16:53 by albagar4         ###   ########.fr       */
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
		if (pow(z.x, 2) + pow(z.y, 2) > 4)
			break ;
		count++;
	}
	return (count);
}

void	mandelbrot(t_fractal *data, int width, int height)
{
	t_comp	coord;
	int		result;

	coord.x = 0.0;
	while (coord.x != width)
	{
		coord.y = 0.0;
		while (coord.y != height)
		{
			result = sucesion(coord.x, coord.y);
			if (result == 100)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, coord.x, coord.y, 0x000000);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, coord.x, coord.y, 0xFFFFFF);
			coord.y++;
		}
		coord.x++;
	}
}
