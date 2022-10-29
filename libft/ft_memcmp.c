/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:30:02 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/26 15:08:57 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s2;
	count = 0;
	while (a[count] == b[count] && count < n)
		count++;
	if (count == n)
		count--;
	return (a[count] - b[count]);
}

