/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:25:45 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/25 17:25:45 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It copies the string src to the end of dest.
 * 
 * @param dest The destination string.
 * @param src The string to be appended.
 * @param size the size of the destination buffer
 * 
 * @return The length of the string it tried to create.
 */
size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	tdest;
	size_t	tsrc;
	size_t	g;

	tdest = ft_strlen(dest);
	tsrc = ft_strlen(src);
	if (size == 0)
		return (tsrc);
	if (size <= tdest)
		return (size + tsrc);
	g = 0;
	while (src[g] && g < size - tdest - 1)
	{
		dest[tdest + g] = src[g];
		g++;
	}
	dest[tdest + g] = '\0';
	return (tdest + tsrc);
}
