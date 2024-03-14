/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:46:35 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/14 12:01:00 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void ft_leaks()
{
	system("leaks -q fractol");
}

void	init_window(t_fractal *data, t_img *img)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fractal");
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

int	main(void)
{
	t_fractal	data;
	// t_img		img;

	data.zoom = 250;
	init_window(&data, &data.img);
	mlx_key_hook(data.win_ptr, &ft_close, &data);
	mlx_mouse_hook(data.win_ptr, ft_mouse_action, &data);
	mandelbrot(&data, &data.img, WIDTH, HEIGHT);
	ft_leaks();
	mlx_loop(data.mlx_ptr);
	return (0);
}
