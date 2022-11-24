/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:30:02 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/07 15:07:47 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*a;
	unsigned char	*b;

	if (n != 0)
	{	
		a = (unsigned char *)s1;
		b = (unsigned char *)s2;
		count = 0;
		while (a[count] == b[count] && count < n - 1)
			count++;
		return (a[count] - b[count]);
	}
	return (0);
}
