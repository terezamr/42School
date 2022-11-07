/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:26:01 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/25 17:26:01 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int c, size_t count)
{
	int			a;
	const char	*s;

	s = (const char *)string;
	a = 0;
	if (count == 0)
		return (NULL);
	while (string && count != 0)
	{
		if (s[a] == (char)c)
			return ((char *)string + a);
		a++;
		count--;
	}
	if (c == '\0' && s[a] == '\0')
		return ((char *)string + a);
	return (NULL);
}
