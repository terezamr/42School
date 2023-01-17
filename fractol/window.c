/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:59:46 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/17 17:59:45 by mvicente         ###   ########.fr       */
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
	if (n == 0 || n == 1)
	{
		*(int *)index = (255 * 65536) + (255 * 256) + 255;
	}
	else if (n <= 400 / data->max_iter)
	{
		*(int *)index = ((data->img.red - 20 * n) * 65536)
			+ (data->img.green * 256) + (data->img.blue);
	}
	else if (n > 400 / data->max_iter && n <= 800 / data->max_iter)
	{
		*(int *)index = (data->img.red * 65536) + (data->img.green * 256) \
		+ (data->img.blue - 20 * (n - 400 / data->max_iter));
	}
	else if (n != data->max_iter && n - 800 / data->max_iter > 0)
	{
		*(int *)index = (data->img.red * 65536) + (data->img.green - 20
				* (n - 800 / data->max_iter) * 256 + (data->img.blue));
	}
	if (n == data->max_iter)
		*(int *)index = BLACK_PIXEL;
}
