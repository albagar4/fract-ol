/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:39 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/13 17:39:45 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close(int keysym, t_fractal *data)
{
	if (keysym == 53)
	{
		// mlx_destroy_image(data->win_ptr, img->mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	// printf("KeyCode: %d\n", keysym);
	return (0);
}

int	ft_mouse_action(int keysym, int x, int y, t_fractal *coord)
{
	(void)x;
	(void)y;
	if (keysym == SCROLL_UP)
		coord->zoom += 50;
	else if (keysym == SCROLL_DOWN)
		coord->zoom -= 50;
	mandelbrot(coord, &coord->img, WIDTH, HEIGHT);
	return (0);
}
