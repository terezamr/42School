/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:26:41 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/28 18:08:54 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ini;
	int	number;
	int	sig;

	ini = 0;
	number = 0;
	sig = 1;
	while ((nptr[ini] >= 9 && nptr[ini] <= 13) || nptr[ini] == 32)
		ini++;
	if (nptr[ini] == '-' || nptr[ini] == '+')
	{
		if (nptr[ini] == '-')
			sig = -1;
		ini++;
	}
	while (nptr[ini] >= 48 && nptr[ini] <= 57)
	{
		number = number * 10 + (nptr[ini] - 48);
		ini++;
	}
	return (sig * number);
}
