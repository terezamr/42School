/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:12:45 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/16 16:09:38 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*to_lower(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
			string[i] = string[i] + 32;
		i++;
	}
	return (string);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	s1 = to_lower(s1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	decimal_times(const char *nptr, int decimal, int *i)
{	
	int	a;

	a = *i;
	a++;
	while (nptr[a] == 48)
	{
		decimal = decimal * 10;
		a++;
	}
	i = &a;
	return (decimal);
}

float	ft_atoi(const char *nptr)
{
	int		i;
	float	number;
	int		sig;
	int		decimal;

	i = 0;
	number = 0;
	sig = 1;
	decimal = 1;
	if (nptr[i++] == '-')
		sig = -1;
	while (nptr[i] == 48)
		i++;
	while ((nptr[i] >= 48 && nptr[i] <= 57) || nptr[i] == 46)
	{
		if (nptr[i] == 46)
			decimal = decimal_times(nptr, decimal, &i);
		else
		{
			number = number * 10 + (nptr[i] - 48);
			decimal = decimal * 10;
		}
		i++;
	}
	return (sig * number / decimal);
}

void	error_message(void)
{
	write(2, "------------------------------", 30);
	write(2, "\nPlease type the arguments in the following format:\n\n", 54);
	write(2, "Mandelbrot set: ./fractol [2]\n", 31);
	write(2, "[2]: 'Mandelbrot' or '1'\n\n", 26);
	write(2, "Julia set: ./fractol [2] [3] [4]\n", 33);
	write(2, "[2]: 'Julia' or '2' \n", 21);
	write(2, "[3]: Coordinate x\n", 18);
	write(2, "[4]: Coordinate y\n\n", 19);
	write(2, "If [3] and [4] aren't specified,", 32);
	write(2, " the program uses the following values: ", 41);
	write(2, "x = 0.26; y = 0.0015.\n", 22);
	write(2, "-----------------------------\n", 30);
	exit(0);
}
