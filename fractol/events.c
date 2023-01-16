/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:40:05 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/16 17:07:00 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_data *data)
{
	if (data->img.start_pixel == BLUE_PIXEL)
	{
		data->img.end_pixel = VIOLET_PIXEL;
		data->img.start_pixel = LIME_PIXEL;
	}
	else if (data->img.start_pixel == LIME_PIXEL)
	{
		data->img.end_pixel = GREEN_PIXEL;
		data->img.start_pixel = BLUE_PIXEL;
	}
}

void	zoom(t_data *data, float move, float scale)
{
	data->img.change_move *= move;
	data->img.scale *= scale;
}

int	exit_fractol(t_data *data)
{
	if (!data)
		exit(0);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	float	c1;
	float	c2;

	c1 = 0;
	c2 = 0;
	if (button == MOUSE_UP)
		zoom(data, 0.75, 0.7);
	else if (button == MOUSE_DOWN)
		zoom(data, 1.4, 2);
	else if (button == 3)
		change_color(data);
	else if (button == 1 && data->set_type == JULIA)
	{
		c2 = (-4 * data->img.scale * ((float)y / WINDOW_HEIGHT)
				+ data->img.offset_i);
		c1 = (4 * data->img.scale * ((float)x / WINDOW_WIDTH)
				+ data->img.offset_r);
		data->julia_r = c1;
		data->julia_i = c2;
	}
	return (0);
}

int	handle_key(int key, t_data *data)
{
	if (key == 65307)
		exit_fractol(data);
	else if (key == KEY_LEFT)
		data->img.offset_r -= 0.2 * data->img.change_move;
	else if (key == KEY_RIGHT)
		data->img.offset_r += 0.2 * data->img.change_move;
	else if (key == KEY_UP)
		data->img.offset_i += 0.2 * data->img.change_move;
	else if (key == KEY_DOWN)
		data->img.offset_i -= 0.2 * data->img.change_move;
	else if (key == KEY_PLUS)
		zoom(data, 0.75, 0.7);
	else if (key == KEY_MINUS)
		zoom(data, 1.4, 2);
	else if (key == INC_IT)
		data->max_iter += 1;
	else if (key == DEC_IT && data->max_iter > 1)
		data->max_iter -= 1;
	return (0);
}
