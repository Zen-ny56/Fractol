/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:49:31 by naadam            #+#    #+#             */
/*   Updated: 2023/11/02 09:18:54 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	cal_itr(t_fractal *img)
{
	int		i;
	float	x_temp;
	double	x;
	double	y;

	i = 0;
	y = 0.0;
	x = 0.0;
	while ((x * x + y * y <= 4) && i < img->max_itr)
	{
		x_temp = (x * x) - (y * y) + img->real;
		y = (2 * x * y) + img->imag;
		x = x_temp;
		i++;
	}
	return (i);
}

void	draw_mandel(t_fractal *img)
{
	int	itr;

	mlx_clear_window(img->mlx, img->window);
	img->y = 0;
	while (img->y < img->height)
	{
		img->x = 0;
		while (img->x < img->width)
		{
			img->real = img->x_pos + (img->x - img->width / (2.0)) * img->scale;
			img->imag = img->y_pos + (img->y - img->height / (2.0))
				* img->scale;
			itr = cal_itr(img);
			if (itr == img->max_itr)
				my_mlx_pixel_put(img, img->x, img->y, 0x000000);
			else
				my_mlx_pixel_put(img, img->x, img->y, img->color * itr);
			img->x++;
		}
		img->y++;
	}
}
