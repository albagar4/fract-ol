/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:31:23 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/14 18:38:20 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*pixel = color;
}

void	assign_constants(t_fractal *data, char *nbr)
{
	if (!ft_strncmp(nbr, "1", 1))
	{
		data->julia_x = 0.29;
		data->julia_y = 0.01;
	}
	else if (!ft_strncmp(nbr, "2", 1))
	{
		data->julia_x = -0.8;
		data->julia_y = 0.16;
	}
	else if (!ft_strncmp(nbr, "3", 1))
	{
		data->julia_x = -0.8;
		data->julia_y = 0;
	}
	else
	{
		ft_putendl_fd("Usage : ./fractol <fractal> <1-3 (just julia)>", 1);
		ft_putendl_fd("Fractal options : mandelbrot julia", 1);
		exit(0);
	}
}
