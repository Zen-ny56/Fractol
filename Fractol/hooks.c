/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:53:46 by naadam            #+#    #+#             */
/*   Updated: 2023/11/26 14:42:36 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keypress(int keycode, t_fractal *img)
{
	if (keycode == 53)
	{
		if (exit_window(img) == 0)
			exit(0);
	}
	if (keycode >= 123 && keycode <= 126)
		move(keycode, img);
	if (keycode == 3)
		change_color(img);
	if (keycode == 15)
		reset(img);
	return (0);
}

int	exit_window(t_fractal *img)
{
	mlx_clear_window(img->mlx, img->window);
	mlx_destroy_window(img->mlx, img->window);
	ft_putstr_fd("Window exited\n", 1);
	exit(0);
}

void	move(int keycode, t_fractal *img)
{
	if (keycode == 123)
	{
		img->x_pos -= (15.2 * img->scale);
		redraw(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 124)
	{
		img->x_pos += (15.2 * img->scale);
		redraw(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 125)
	{
		img->y_pos += (15.2 * img->scale);
		redraw(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
	if (keycode == 126)
	{
		img->y_pos -= (15.2 * img->scale);
		redraw(img);
		mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
	}
}

void	change_color(t_fractal *img)
{
	img->color *= 45;
	redraw(img);
	mlx_put_image_to_window(img->mlx, img->window, img->img, 0, 0);
}

void	redraw(t_fractal *img)
{
	mlx_clear_window(img->mlx, img->window);
	if (ft_strncmp(img->name, "Julia", 6) == 0)
		draw_julia(img);
	if (ft_strncmp(img->name, "Mandelbrot", 13) == 0)
		draw_mandel(img);
}
