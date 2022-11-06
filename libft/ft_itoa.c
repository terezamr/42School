/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:50:55 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/06 18:24:56 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_count(int aux)
{
	int	count;

	count = 0;
	if (aux < 0)
		aux = aux * -1;
	while (aux >= 10)
	{
		aux = aux / 10;
		count++;
	}
	return (count);
}

char	*fill_ptr(char *ptr, int count, int a, int n, int sig)
{
	while (count >= a)
	{
		ptr[count] = n % 10 + '0';
		n = n / 10;
		count--;
	}
	if (sig == -1)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		count;
	int		sig;
	int		a;

	count = 0;
	a = 0;
	sig = 0;
	count = get_count(n) + 1;
	if (n < 0)
	{
		count++;
		a = 1;
		sig = -1;
		n = n * -1;
	}
	if (n == -2147483648)
	{
		ptr = malloc(12);
		ptr = "-2147483648";
		return (ptr);
	}
	if (!(ptr = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ptr[count--] = '\0';
	fill_ptr(ptr, count, a, n, sig);
	return (ptr);
}
