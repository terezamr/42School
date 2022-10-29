/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:24:58 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/25 17:24:58 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	a;

	a = 0;
	while (string[a] != '\0')
	{
		if (string[a] == c)
			return ((char *)string + a);
		a = a + 1;
	}
	if (c == '\0' && string[a] == '\0')
		return ((char *)string + a);
	return (0);
}
