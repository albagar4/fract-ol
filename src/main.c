/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:46:35 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/11 18:12:01 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close(int keysym, t_fractal *data)
{
	// if (keysym == XK_Escape)
		// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	(void)data;
	printf("KeyCode: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_fractal	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr =mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "mandelbrot");
	mandelbrot(&data, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_key_hook(data.win_ptr, &ft_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// int	main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	// void	*img_ptr;

// 	mlx_ptr = mlx_init();
// 	if (mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
// 	// img_ptr = mlx_new_image(mlx_ptr, WINDOW_HEIGHT, WINDOW_HEIGHT);
// 	// mlx_put_image_to_window (mlx_ptr, win_ptr, img_ptr, 0, 0);
// 	for (size_t x = 0; x < WINDOW_WIDTH; x++)
// 	{
// 		for (size_t y = 0; y < WINDOW_HEIGHT; y++)
// 		{
// 			if (y >= 100 && y <= 200)
// 				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
// 			else
// 				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x006633);
// 		}
// 	}
// 	if (win_ptr == NULL)
// 	{
// 		free(win_ptr);
// 		return (MLX_ERROR);
// 	}
// 	while (1)
// 		;
// }
