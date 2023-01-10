/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:10:12 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/10 18:24:02 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, t_data *data)
{
	if (key == 65307)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

void	vars_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
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
	else if (n > 0 && n < MAX_ITER / 5)
		*(int *)index = RED_PIXEL;
	else if (n > MAX_ITER / 5 && n < MAX_ITER * 2 / 5)
		*(int *)index = PINK_PIXEL;
	else if (n > MAX_ITER * 2 / 5 && n < MAX_ITER * 3 / 5)
		*(int *)index = VIOLET_PIXEL;
	else if (n > MAX_ITER * 3 / 5 && n < MAX_ITER * 4 / 5)
		*(int *)index = GREEN_PIXEL;
	else
		*(int *)index = YELLOW_PIXEL;
}

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

int	render(t_data *data)
{
	double	x;
	double	y;
	double	c1;
	double	c2;
	int		n;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		c2 = -2 * data->img.scale * (y / WINDOW_HEIGHT) + 1;
		while (x < WINDOW_WIDTH)
		{
			c1 = (x / WINDOW_WIDTH) * 3 * data->img.scale - 2;
			n = mandelbrot(c1, c2);
			color(n, x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (1);
}

// int	zoom(int button, t_data *data)
// {
// 	if (button == 4)
// 	{
// 		printf("check\n");
// 		data->img.scale = 0.5;
// 		mlx_clear_window(data->mlx, data->win);
// 		render(data);
// 	}
// 	return (1);
// }

void	check_arguments(char **argv, t_data *data)
{
	if (argv[0][0] == '1')
		data->img.set_type = 1;
	if (argv[0][0] == '2')
		data->img.set_type = 2;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	vars_init(data);
	data->img.scale = 1;
	check_arguments(argv, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract'ol");
	data->img.mlx_img = mlx_new_image(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);

	mlx_loop_hook(data->mlx, render, data);
	mlx_hook(data->win, 2, 1L << 0, deal_key, data);
	mlx_hook(data->win, 17, 1L << 17, destroy, data);
	//mlx_mouse_hook(data->win, zoom, data);

	mlx_loop(data->mlx);

	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
