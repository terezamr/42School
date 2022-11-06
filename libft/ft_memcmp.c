/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:30:02 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/06 16:09:12 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	count = 0;
	while (a[count] == b[count] && count < n)
		count++;
	if (count == n)
		count--;
	return (a[count] - b[count]);
}


// int main()
// {
// 	size_t size = 10;
// 	char *b1 = electric_alloc(size);
// 	char *b2 = electric_alloc(size);

// 	strcpy(b1, ".........");
// 	strcpy(b2, ".........");
// 	ft_memcmp(b1, b2, size);
// }