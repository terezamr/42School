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

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	tdest;
	size_t	tsrc;
	size_t	g;

	tdest = ft_strlen(dest);
	tsrc = ft_strlen(src);
	if (size <= tdest || size == 0)
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
