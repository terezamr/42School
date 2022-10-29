/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:34:26 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/29 16:06:18 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		b;
	int		i;
	int		f;
	int		size;

	b = 0;
	i = 0;
	f = ft_strlen(s1) - 1;
	while (set[b] != '\0')
	{
		if (s1[i] == set[b])
			i++;
		b++;
	}
	b = 0;
	while (set[b] != '\0')
	{
		if (s1[f] == set[b])
			f--;
		b++;
	}
	size = f - i + 1;
	ptr = malloc(sizeof(char) * size + 1);
	ft_memcpy(ptr, s1 + i, size);
	return (ptr);
}
