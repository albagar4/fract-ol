/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:47:19 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/13 20:03:56 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx_linux/mlx.h"
// #include "minilibx_mac/mlx.h"
#include <math.h>
#include <stdint.h>


#define WIDTH 750
#define HEIGHT 450
#define MLX_ERROR 1

// MOUSE KEYS
#define SCROLL_UP 5
#define SCROLL_DOWN 4

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
	int		zoom;
	t_img	img;
}	t_fractal;

typedef struct s_comp
{
	double	x;
	double	y;
}	t_comp;

void	init_window(t_fractal *data, t_img *img);
void	mandelbrot(t_fractal *data, t_img *img, int width, int height);
int		sucesion(double coords_x, double coords_y, int zoom);
int		ft_mouse_action(int keysym, int x, int y, t_fractal *coord);
int		ft_close(int keysym, t_fractal *data);
void	img_pixel_put(t_img *img, int x, int y, int color);
