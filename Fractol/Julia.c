/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:51:35 by naadam            #+#    #+#             */
/*   Updated: 2023/11/03 15:42:01 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	cal_itr_j(t_fractal *img)
{
	double	temp;
	double	x;
	double	y;
	int		i;

	i = 0;
	x = img->real;
	y = img->imag;
	while (x * x + y * y <= 4 && i < img->max_itr)
	{
		temp = (x * x) - (y * y);
		y = (2 * x * y) + img->z_i;
		x = temp + img->z_r;
		i++;
	}
	return (i);
}

void	draw_julia(t_fractal *img)
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
			itr = cal_itr_j(img);
			if (itr == img->max_itr)
				my_mlx_pixel_put(img, img->x, img->y, 0x000000);
			else
				my_mlx_pixel_put(img, img->x, img->y, img->color * itr);
			img->x++;
		}
		img->y++;
	}
}
