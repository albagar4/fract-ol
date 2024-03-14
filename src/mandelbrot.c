/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:26 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/14 11:55:49 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	sucesion(double coords_x, double coords_y, int zoom)
{
	t_comp	z;
	t_comp	c;
	int		count;
	double	temp;

	z.x = 0.0;
	z.y = 0.0;
	c.x = coords_x / zoom - 1.85;
	c.y = coords_y / zoom - 1;
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

	printf("me estoy metiendo aqui\n");
	coord.x = 0.0;
	printf("1\n");
	while (coord.x != width)
	{
		printf("2\n");
		coord.y = 0.0;
		while (coord.y != height)
		{
			printf("3\n");
			result = sucesion(coord.x, coord.y, data->zoom);
			printf("4\n");
			if (result == 100)
				img_pixel_put(img, coord.x, coord.y, 0x000000);
			else
			{
				printf("5\n");
				color = 0xFCBE11 * (result % 255);
				img_pixel_put(img, coord.x, coord.y, color);
			}
			printf("6\n");
			coord.y++;
		}
		printf("7\n");
		coord.x++;
	}
	printf("termino\n");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
}
