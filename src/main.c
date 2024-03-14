/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:46:35 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/14 18:17:48 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void ft_leaks()
{
	system("leaks -q fractol");
}

void	select_fractal(t_fractal *data)
{
	if (!ft_strncmp(data->name, "julia", 5))
		julia(data, &data->img, WIDTH, HEIGHT);
	else if (!ft_strncmp(data->name, "mandelbrot", 10))
		mandelbrot(data, &data->img, WIDTH, HEIGHT);
	else
	{
		printf("data->name es = %s\n", data->name);
		printf("data->julia_x es = %f\n", data->julia_x);
		printf("data->julia_y es = %f\n", data->julia_y);
		ft_putendl_fd("Usage : ./fractol <fractal> <1-3 (just julia)>", 1);
		ft_putendl_fd("Fractal options : mandelbrot julia", 1);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_fractal	data;

	if (argc != 2)
	{
		if (argc == 3 && !ft_strncmp(argv[1], "julia", 5))
			assign_constants(&data, argv[2]);
		else
		{
			ft_putendl_fd("Usage : ./fractol <fractal> <1-3 (just julia)>", 1);
			ft_putendl_fd("Fractal options : mandelbrot julia", 1);
			return (0);
		}
	}
	preset_fractal(&data, argv[1]);
	init_window(&data, &data.img);
	mlx_key_hook(data.win_ptr, &ft_key_actions, &data);
	mlx_mouse_hook(data.win_ptr, ft_mouse_action, &data);
	select_fractal(&data);
	// ft_leaks();
	mlx_loop(data.mlx_ptr);
	return (0);
}
