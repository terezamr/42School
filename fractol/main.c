/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:10:12 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/09 14:01:59 by mvicente         ###   ########.fr       */
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

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	vars_init(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 500, 500, "Title");
	mlx_hook(data->win, 2, 1L << 0, deal_key, data);
	mlx_hook(data->win, 17, 1L << 17, destroy, data);
	mlx_loop(data->mlx);

	//mlx_destroy_display(data.mlx);
	// free(data->mlx);
	// free(data->win);
}
