/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:18:19 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/19 11:40:17 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	preset_fractal(t_fractal *data, char *fractal_name)
{
	data->ords_x = -2.00;
	data->ords_y = -1.5;
	data->zoom = 250;
	data->color = 0xFCBE11;
	data->julia_x = -0.4;
	data->julia_y = 0.6;
	data->name = fractal_name;
}

void	init_window(t_fractal *data, t_img *img)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		exit(0);
	}
	img->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (img->mlx_img == NULL)
	{
		free(data->mlx_ptr);
		free(data->win_ptr);
		exit(0);
	}
	img->addr = mlx_get_data_addr(img->mlx_img,
			&img->bpp, &img->line_len, &img->endian);
}
