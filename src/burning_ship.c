/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:33:11 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/15 12:50:38 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ship_sucesion(double coords_x, double coords_y, t_fractal *data)
{
	t_comp	z;
	t_comp	c;
	int		count;
	double	temp;

	z.x = 0.0;
	z.y = 0.0;
	c.x = coords_x / data->zoom - data->ords_x;
	c.y = coords_y / data->zoom - data->ords_y;
	count = 0;
	while (count < 50)
	{
		temp = fabs(z.x);
		z.x = pow(fabs(z.x), 2) - pow(fabs(z.y), 2) + c.x;
		z.y = 2 * temp * fabs(z.y) + c.y;
		if (pow(z.x, 2) + pow(z.y, 2) > INT32_MAX)
			break ;
		count++;
	}
	return (count);
}

void	burning_ship(t_fractal *data, t_img *img, int width, int height)
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
			result = ship_sucesion(coord.x, coord.y, data);
			if (result == 50)
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
