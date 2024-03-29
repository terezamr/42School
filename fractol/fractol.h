/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:57:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/18 12:56:55 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1400

# define BLACK_PIXEL 0x000000

# define MANDELBROT 1
# define JULIA 2

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define INC_IT 65365
# define DEC_IT 65366

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	float	scale;
	float	offset_r;
	float	offset_i;
	float	change_move;
	int		red;
	int		green;
	int		blue;
}	t_img;

typedef struct s_data
{
	int		max_iter;
	void	*mlx;
	void	*win;
	t_img	img;
	int		set_type;
	float	julia_r;
	float	julia_i;
}	t_data;

int		ft_strcmp(char *s1, char *s2);
float	ft_atoi(const char *nptr);
void	error_message(void);
int		exit_fractol(t_data *data);
int		handle_key(int key, t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
void	vars_init(t_data *data);
int		destroy(int key, t_data *data);
void	color(int n, int x, int y, t_data *data);
int		mandelbrot(t_data *data, double c1, double c2);
int		julia(t_data *data, double z1, double z2);
int		render(t_data *data);

#endif