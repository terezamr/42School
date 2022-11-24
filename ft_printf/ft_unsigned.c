/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:03:48 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/24 13:50:41 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_count_u(unsigned int n)
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

char	*fill_ptr_u(char *ptr, int count, int a, unsigned int n)
{
	ptr[count] = '\0';
	count--;
	while (count >= 0)
	{
		ptr[count--] = '0' + (a * (n % 10));
		n = n / 10;
	}
	return (ptr);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	int		count;
	int		a;

	a = 1;
	count = get_count_u(n);
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	fill_ptr_u(ptr, count, a, n);
	if (a == -1)
		ptr[0] = '-';
	return (ptr);
}

int	ft_putnbr_u(unsigned int number)
{
	char	*s;
	int		i;

	s = ft_uitoa(number);
	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
	free(s);
	return (i);
}
