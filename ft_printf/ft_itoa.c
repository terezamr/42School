/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:50:55 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/20 17:44:02 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*fill_ptr(char *ptr, int count, int a, int n)
{
	int	sig;

	sig = 1;
	if (a == 1)
		sig = -1;
	ptr[count] = '\0';
	count--;
	while (count >= 0)
	{
		ptr[count] = '0' + (sig * (n % 10));
		n = n / 10;
		count--;
	}
	return (ptr);
}

char	*check_f(char *ptr, int a)
{
	if (a == 1)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		count;
	int		a;

	a = 0;
	count = get_count(n);
	if (n < 0)
	{
		count++;
		a = 1;
	}
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	fill_ptr(ptr, count, a, n);
	check_f(ptr, a);
	return (ptr);
}

