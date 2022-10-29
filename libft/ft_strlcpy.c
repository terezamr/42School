/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:25:05 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/25 17:25:05 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	g;
	unsigned int	i;

	i = ft_strlen(src);
	if (size == 0)
		return (i);
	g = 0;
	while (src[g] != '\0' && g < size - 1)
	{
		dest[g] = src[g];
		g++;
	}
	dest[g] = '\0';
	return (i);
}
