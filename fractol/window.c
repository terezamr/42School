/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:59:46 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/11 17:13:31 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, t_data *data)
{
	if (button == MOUSE_UP)
		data->img.scale *= 0.8;
	else if (button == MOUSE_DOWN)
		data->img.scale *= 1.5;
	return (0);
}

int	handle_key(int key, t_data *data)
{
	if (key == 65307)
		mlx_destroy_window(data->mlx, data->win);
	else if (key == KEY_LEFT)
		data->img.offset_r -= 1;
	else if (key == KEY_RIGHT)
		data->img.offset_r += 1;
	else if (key == KEY_UP)
		data->img.offset_i += 1;
	else if (key == KEY_DOWN)
		data->img.offset_i -= 1;
	else if (key == KEY_PLUS)
		data->img.scale *= 0.8;
	else if (key == KEY_MINUS)
		data->img.scale *= 1.5;
	return (0);
}

void	vars_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->img.scale = 1;
	data->img.offset_r = -2;
	data->img.offset_i = 1;
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
	if (n == MAX_ITER)
		*(int *)index = BLACK_PIXEL;
	// else if (n > 0 && n < MAX_ITER / 5)
	// 	*(int *)index = RED_PIXEL;
	// else if (n > MAX_ITER / 5 && n < MAX_ITER * 2 / 5)
	// 	*(int *)index = PINK_PIXEL;
	// else if (n > MAX_ITER * 2 / 5 && n < MAX_ITER * 3 / 5)
	// 	*(int *)index = VIOLET_PIXEL;
	// else if (n > MAX_ITER * 3 / 5 && n < MAX_ITER * 4 / 5)
	// 	*(int *)index = GREEN_PIXEL;
	else
	 	*(int *)index = YELLOW_PIXEL;
}
