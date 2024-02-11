/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:53:19 by naadam            #+#    #+#             */
/*   Updated: 2023/11/27 19:24:23 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_m(t_fractal *img)
{
	img->x_pos = 0.0;
	img->y_pos = 0.0;
	img->height = 720;
	img->width = 720;
	img->max_itr = 150;
	img->color = 0xFFFFFF;
	img->scale = 0.01;
	img->name = "Mandelbrot";
}

void	init_j(t_fractal *img, float real, float imag)
{
	img->x_pos = 0.0;
	img->y_pos = 0.0;
	img->height = 720;
	img->width = 720;
	img->max_itr = 150;
	img->color = 0xFFFFFF;
	img->z_r = real;
	img->z_i = imag;
	img->scale = 0.01;
	img->name = "Julia";
}

void	mandel(void)
{
	t_fractal	img;

	init_m(&img);
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, img.width, img.height, "Mandelbrot");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
			&img.endian);
	draw_mandel(&img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_hook(img.window, 02, 1L << 0, keypress, &img);
	mlx_hook(img.window, 4, 0, zoom, &img);
	mlx_hook(img.window, 17, 1L << 0, exit_window, &img);
	mlx_loop(img.mlx);
}

void	julia(float real, float imag)
{
	t_fractal	img;

	init_j(&img, real, imag);
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, img.width, img.height, "Julia");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
			&img.endian);
	draw_julia(&img);
	mlx_put_image_to_window(img.mlx, img.window, img.img, 0, 0);
	mlx_hook(img.window, 02, 1L << 0, keypress, &img);
	mlx_hook(img.window, 4, 0, zoom, &img);
	mlx_hook(img.window, 17, 1L << 0, exit_window, &img);
	mlx_loop(img.mlx);
}
