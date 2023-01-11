/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:26:13 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/11 18:57:43 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double c1, double c2)
{
	double	z1;
	double	z1_new;
	double	z2;
	int		n;

	z1 = 0;
	z1_new = 0;
	z2 = 0;
	n = 0;
	while (n < MAX_ITER)
	{
		z1_new = (z1 * z1) - (z2 * z2) + c1;
		z2 = (2 * z1 * z2) + c2;
		z1 = z1_new;
		if (z1 * z1 + z2 * z2 >= 4)
			return (n);
		n++;
	}
	return (n);
}

int	julia(double z1, double z2, double c1, double c2)
{
	double	z1_new;
	int		n;

	z1_new = 0;
	n = 0;
	while (n < MAX_ITER)
	{
		z1_new = (z1 * z1) - (z2 * z2) + c1;
		z2 = (2 * z1 * z2) + c2;
		z1 = z1_new;
		if (z1 * z1 + z2 * z2 >= 4)
			return (n);
		n++;
	}
	return (n);
}
