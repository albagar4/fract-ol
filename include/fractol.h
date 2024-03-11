/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:47:19 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/08 16:01:24 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include <math.h>

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 450
#define ZOOM 225
#define MLX_ERROR 1

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fractal;

typedef struct s_comp
{
	double	x;
	double	y;
}	t_comp;

void	mandelbrot(t_fractal *data, int width, int height);
int		sucesion(double coords_x, double coords_y);
int		ft_close(int keysym, t_fractal *data);
