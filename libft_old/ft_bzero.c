/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:37:59 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/17 09:52:50 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_bzero() takes a pointer to a memory area and a size in bytes as parameters, and writes zeroes to
 * the memory area
 * 
 * @param s This is the pointer to the memory that needs to be filled with zeros.
 * @param n The number of bytes to be set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*a;

	a = (char *)s;
	while (n != 0)
	{
		a[n - 1] = '\0';
		n = n - 1;
	}
}
