/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:22:18 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 15:22:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	count(char *list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	g;
	unsigned int	i;

	i = count(dest);
	if (size == 0 || size <= i)
	{
		return (size + i);
	}
	g = 0;
	while (src[g] && g < size - 1)
	{
		dest[g] = src[g];
		g++;
		i++;
	}
	dest[g] = '\0';
	return (g);
}

int	main(void)
{
	char a[9] = "hello";
	char b[] = "world";
	unsigned int	i;
	i = ft_strlcat(a, b, 3);
	printf("%i", i);
	return (0);
}