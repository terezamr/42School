/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:59:46 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/16 17:07:08 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vars_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->img.scale = 1;
	data->img.offset_r = -2;
	data->img.offset_i = 2;
	data->img.change_move = 1;
	data->julia_r = 0.26;
	data->julia_i = 0.0015;
	data->max_iter = 36;
	data->img.red = 255;
	data->img.green = 255;
	data->img.blue = 255;
}

int	destroy(int key, t_data *data)
{
	if (key)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

void	color(int n, int x, int y, t_data *data)
{
	char	*index;

	index = data->img.addr + (y * data->img.line_len
			+ x * (data->img.bpp / 8));
	if (n == data->max_iter)
		*(int *)index = BLACK_PIXEL;
	else
	{
		*(int *)index = (data->img.red * 65536 * n / data->max_iter)
			+ (data->img.green * 256 * 0.8 * n / data->max_iter)
			+ (data->img.blue);
	}
}
