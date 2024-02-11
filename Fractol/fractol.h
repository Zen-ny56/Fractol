/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:55:41 by naadam            #+#    #+#             */
/*   Updated: 2023/10/14 01:26:38 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*window;
	char	*addr;
	char	*name;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		max_itr;
	int		length;
	int		x;
	int		y;
	float	x_pos;
	float	y_pos;
	double	scale;
	double	real;
	double	imag;
	double	z_r;
	double	z_i;
	double	zoom;
	int		color;
}			t_fractal;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int a);
int		ft_atoi(char *str);
double	ft_atoi_d(char *str);
void	check_dots(char *str);
double	float_conversion(char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int c, size_t len);
int		get_before_decimal(char *str, char *a);
double	get_after_decimal(char *str, char *b);
void	error_handling(char *str);
void	init_m(t_fractal *img);
void	mandel(void);
void	draw_mandel(t_fractal *img);
int		cal_itr(t_fractal *img);
void	my_mlx_pixel_put(t_fractal *img, int x, int y, int color);
void	ft_putstr_fd(char *s, int fd);
int		keypress(int keycode, t_fractal *img);
int		exit_window(t_fractal *img);
void	move(int keycode, t_fractal *img);
void	redraw(t_fractal *img);
void	reset(t_fractal *img);
void	julia(float real, float imag);
void	init_j(t_fractal *img, float real, float imag);
void	change_color(t_fractal *img);
int		cal_itr_j(t_fractal *img);
void	draw_julia(t_fractal *img);
int		zoom(int button, int x, int y, t_fractal *img);
int		no_dots(char *str);
double	simple_conversion(char *str);
double	choose_conversion(char *str);

#endif
