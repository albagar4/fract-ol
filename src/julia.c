/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:36:35 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/15 15:33:35 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia_sucesion(double coords_x, double coords_y, t_fractal *data)
{
	t_comp	z;
	t_comp	c;
	int		count;
	double	temp;

	c.x = data->julia_x;
	c.y = data->julia_y;
	z.x = coords_x / data->zoom + data->ords_x;
	z.y = coords_y / data->zoom + data->ords_y;
	count = 0;
	while (count < 75)
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

void	julia(t_fractal *data, t_img *img, int width, int height)
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
			result = julia_sucesion(coord.x, coord.y, data);
			if (result == 75)
				img_pixel_put(img, coord.x, coord.y, 0x000000);
			else
			{
				color = data->color * (result % 255);
				img_pixel_put(img, coord.x, coord.y, color);
			}
			coord.y++;
		}
		coord.x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
}
