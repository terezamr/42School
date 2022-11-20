/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:05:52 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/29 13:55:11 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;
	size_t	c;

	a = (char *)src;
	b = (char *)dest;
	c = 0;
	if (!dest && !src)
		return (NULL);
	while (c != n)
	{
		b[c] = a[c];
		c++;
	}
	return (dest);
}
