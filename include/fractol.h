/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:47:19 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/12 19:31:21 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
// #include "minilibx_linux/mlx.h"
#include "minilibx_mac/mlx.h"
#include <math.h>


#define WIDTH 750
#define HEIGHT 450
#define ZOOM 225
#define MLX_ERROR 1

typedef struct s_img
{
	void	*mlx_img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_fractal;

typedef struct s_comp
{
	double	x;
	double	y;
}	t_comp;

void	init_window(t_fractal *data, t_img *img);
void	mandelbrot(t_fractal *data, t_img *img, int width, int height);
int		sucesion(double coords_x, double coords_y);
int		ft_close(int keysym, t_fractal *data);
void	img_pixel_put(t_img *img, int x, int y, int color);
