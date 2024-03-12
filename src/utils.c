/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:31:23 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/12 18:55:19 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*pixel = color;
}
