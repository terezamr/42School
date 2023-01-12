/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:12:45 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/12 12:08:57 by mvicente         ###   ########.fr       */
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
