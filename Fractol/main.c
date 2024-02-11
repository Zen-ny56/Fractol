/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:25:22 by naadam            #+#    #+#             */
/*   Updated: 2023/11/25 15:14:47 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	double	one;
	double	two;

	if (ac != 2 && ac != 4)
		exit(1);
	if (ac == 2 && 
		(ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1]))) == 0)
		mandel();
	if (ft_strncmp(av[1], "Julia", ft_strlen(av[1])) == 0)
	{
		if (ac == 4)
		{
			one = choose_conversion(av[2]);
			two = choose_conversion(av[3]);
			if ((one >= -2.0 && one <= 2.0) && (two >= -2.0 && two <= 2.0))
				julia(one, two);
			else if ((one < -2.0 || one > 2.0) || (two < -2.0 || two > 2.0))
				write(1, "Coordinates passed in are not valid", 36);
			else
				write(1, "Takes two arguments", 20);
		}
	}
	return (0);
}
