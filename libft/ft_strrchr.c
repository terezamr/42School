/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:24:51 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/25 17:24:51 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	b;

	b = ft_strlen(string);
	if ((char)c == '\0' && string[b] == '\0')
		return ((char *)string + b);
	if (!string)
		return (0);
	b--;
	while (b >= 0)
	{
		if (string[b] == (char)c)
			return ((char *)string + b);
		b--;
	}
	return (0);
}
