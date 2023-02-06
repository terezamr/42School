/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:25:23 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/06 12:50:32 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	printf("Error\n");
	exit(0);
}

void	check_char(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		if ((nptr[i] < 48 || nptr[i] > 57) && nptr[i] != '-' && nptr[i] != '+')
			error();
		i++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	number;
	int	sig;

	i = 0;
	number = 0;
	sig = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	if (nptr[i] < 48 || nptr[i] > 57)
		error();
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	if (sig * number > 2147483646 || sig * number < -2147483647)
		error();
	return (sig * number);
}

t_list	*go_back(t_list *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}
