/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:39 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/15 15:38:15 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close(t_fractal *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	ft_key_actions(int keysym, t_fractal *data)
{
	if (keysym == 126 || keysym == 13)
		data->ords_y -= 75 / data->zoom;
	if (keysym == 125 || keysym == 1)
		data->ords_y += 75 / data->zoom;
	if (keysym == 124 || keysym == 2)
		data->ords_x += 75 / data->zoom;
	if (keysym == 123 || keysym == 0)
		data->ords_x -= 75 / data->zoom;
	if (keysym == 53)
		ft_close(data);
	if (keysym == 8)
		data->color += 1000;
	if (keysym == 15)
		preset_fractal(data, data->name);
	select_fractal(data);
	return (0);
}

void	ft_zoom(t_fractal *data, int x, int y, int nbr)
{
	double	zoom_scale;

	zoom_scale = 1.5;
	if (nbr == 1)
	{
		data->ords_x = (x / data->zoom + data->ords_x)
			- (x / (data->zoom * zoom_scale));
		data->ords_y = (y / data->zoom + data->ords_y)
			- (y / (data->zoom * zoom_scale));
		data->zoom *= zoom_scale;
	}
	else if (nbr == -1)
	{
		data->ords_x = (x / data->zoom + data->ords_x)
			- (x / (data->zoom / zoom_scale));
		data->ords_y = (y / data->zoom + data->ords_y)
			- (y / (data->zoom / zoom_scale));
		data->zoom /= zoom_scale;
	}
	return ;
}

int	ft_mouse_action(int keysym, int x, int y, t_fractal *data)
{
	if (keysym == SCROLL_UP)
		ft_zoom(data, x, y, 1);
	else if (keysym == SCROLL_DOWN)
		ft_zoom(data, x, y, -1);
	select_fractal(data);
	return (0);
}
