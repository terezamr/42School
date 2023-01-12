/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:40:05 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/12 15:02:20 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_data *data)
{
	if (x && y)
	{
		if (button == MOUSE_UP)
		{
			data->img.change_move *= 3 / 4;
			data->img.scale *= 0.7;
		}
		else if (button == MOUSE_DOWN)
		{
			data->img.change_move *= 4 / 3;
			data->img.scale *= 2;
		}
	}
	return (0);
}

int	handle_key(int key, t_data *data)
{
	if (key == 65307)
		mlx_destroy_window(data->mlx, data->win);
	else if (key == KEY_LEFT)
		data->img.offset_r -= 0.2 * data->img.change_move;
	else if (key == KEY_RIGHT)
		data->img.offset_r += 0.2 * data->img.change_move;
	else if (key == KEY_UP)
		data->img.offset_i += 0.2 * data->img.change_move;
	else if (key == KEY_DOWN)
		data->img.offset_i -= 0.2 * data->img.change_move;
	else if (key == KEY_PLUS)
	{
		data->img.change_move *= 0.75;
		data->img.scale *= 0.7;
	}
	else if (key == KEY_MINUS)
	{
		data->img.change_move *= 1.3;
		data->img.scale *= 2;
	}
	return (0);
}
