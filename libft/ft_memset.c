/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:38:14 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/25 11:38:14 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Ft_memset() takes a pointer to a memory area
 * a byte value, and a size_t length, and fills the
 * memory area with the byte value
 * 
 * @param s The pointer to the memory area to be filled.
 * @param c the character to fill the memory with
 * @param n the number of bytes to be set to the value c
 * 
 * @return The address of the first byte of the memory area s.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	char	*a;

	a = (char *)s;
	while (n != 0)
	{
		a[n - 1] = c;
		n--;
	}
	return (s);
}
