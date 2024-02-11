/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 02:00:11 by naadam            #+#    #+#             */
/*   Updated: 2023/11/25 14:28:41 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	float_conversion(char *str)
{
	char	*a;
	size_t	i;
	char	*b;
	double	value;
	double	sign;

	i = 0;
	sign = 1.000;
	error_handling(str);
	if (str[i] == '-')
		sign = -1.000;
	while (str[i] != '.')
		i++;
	a = (char *)ft_calloc(sizeof(char), i);
	b = (char *)ft_calloc(sizeof(char), (ft_strlen(str) - i + 1));
	value = (double)get_before_decimal(str, a);
	value += get_after_decimal(str, b);
	return (value * sign);
}

double	ft_atoi_d(char *str)
{
	int			i;
	double		result;

	i = ft_strlen(str);
	result = 0;
	while (--i >= 0 && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 0.1) + (double)(str[i] - '0');
	}
	result *= 0.1;
	return (result);
}

int	get_before_decimal(char *str, char *a)
{
	int	before;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		a[i] = str[i];
		if (str[i] == '.')
			break ;
		i++;
	}
	before = ft_atoi(a);
	free(a);
	return (before);
}

double	get_after_decimal(char *str, char *b)
{
	double	after;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] != '.')
		i++;
	i += 1;
	while (str[i] != '\0')
	{
		b[k] = str[i];
		i++;
		k++;
	}
	b[k] = '\0';
	after = ft_atoi_d(b);
	free(b);
	return (after);
}
