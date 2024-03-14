/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:39 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/14 14:45:28 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close(t_fractal *data)
{
	// mlx_destroy_image(data->win_ptr, img->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	// printf("KeyCode: %d\n", keysym);
	return (0);
}

int	ft_key_actions(int keysym, t_fractal *data)
{
	if (keysym == 126 || keysym == 13)
		data->ords_y += 0.1;
	if (keysym == 125 || keysym == 1)
		data->ords_y -= 0.1;
	if (keysym == 124 || keysym == 2)
		data->ords_x -= 0.1;
	if (keysym == 123 || keysym == 0)
		data->ords_x += 0.1;
	if (keysym == 53)
		ft_close(data);
	mandelbrot(data, &data->img, WIDTH, HEIGHT);
	return (0);
}

int	ft_mouse_action(int keysym, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (keysym == SCROLL_UP)
		fractal->zoom *= 1.5;
	else if (keysym == SCROLL_DOWN)
		fractal->zoom *= 0.5;
	mandelbrot(fractal, &fractal->img, WIDTH, HEIGHT);
	return (0);
}
