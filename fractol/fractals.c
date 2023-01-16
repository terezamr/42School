/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:26:13 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/16 16:15:35 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data, double c1, double c2)
{
	double	z1;
	double	z1_new;
	double	z2;
	int		n;

	z1 = 0;
	z1_new = 0;
	z2 = 0;
	n = 0;
	while (n < data->max_iter)
	{
		z1_new = pow(z1, 2) - pow(z2, 2) + c1;
		z2 = (2 * z1 * z2) + c2;
		z1 = z1_new;
		if (pow(z1, 2) + pow(z2, 2) >= 4)
			return (n);
		n++;
	}
	return (n);
}

int	julia(t_data *data, double z1, double z2)
{
	double	z1_new;
	int		n;
	double	c1;
	double	c2;

	z1_new = 0;
	n = 0;
	c1 = data->julia_r;
	c2 = data->julia_i;
	while (n < data->max_iter)
	{
		z1_new = pow(z1, 2) - pow(z2, 2) + c1;
		z2 = (2 * z1 * z2) + c2;
		z1 = z1_new;
		if (pow(z1, 2) + pow(z2, 2) >= 4)
			return (n);
		n++;
	}
	return (n);
}
