/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:34:42 by marvin            #+#    #+#             */
/*   Updated: 2022/10/02 13:34:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;
	char	c;

	a = (char *)src;
	b = (char *)dest;
	if (!dest && !src)
		return (0);
	while (n != 0)
	{
		c = a[n - 1];
		b[n - 1] = c;
		n = n - 1;
	}
	return (dest);
}
