/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:47:19 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/14 14:39:44 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
// #include "minilibx_linux/mlx.h"
#include "minilibx_mac/mlx.h"
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
	double	zoom;
	double	ords_x;
	double	ords_y;
	char	*name;
	t_img	img;
}	t_fractal;

typedef struct s_comp
{
	double	x;
	double	y;
}	t_comp;

// Preset fractol
void	preset_fractal(t_fractal *data, char *fractal_name);
void	init_window(t_fractal *data, t_img *img);
// Mandelbrot
void	mandelbrot(t_fractal *data, t_img *img, int width, int height);
int		sucesion(double coords_x, double coords_y, t_fractal *data);
// Key and mouse actions
int		ft_key_actions(int keysym, t_fractal *data);
int		ft_mouse_action(int keysym, int x, int y, t_fractal *fractal);
int		ft_close(t_fractal *data);
// Utils
void	img_pixel_put(t_img *img, int x, int y, int color);
