/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:46:35 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/14 14:39:21 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void ft_leaks()
{
	system("leaks -q fractol");
}

int	main(void)
{
	t_fractal	data;

	preset_fractal(&data, "mandelbrot");
	init_window(&data, &data.img);
	mlx_key_hook(data.win_ptr, &ft_key_actions, &data);
	mlx_mouse_hook(data.win_ptr, ft_mouse_action, &data);
	mandelbrot(&data, &data.img, WIDTH, HEIGHT);
	ft_leaks();
	mlx_loop(data.mlx_ptr);
	return (0);
}
