/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:06:54 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/07 12:51:51 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	a;

	count = 0;
	if (!little[0] || !little)
		return ((char *)big);
	while (count < len && little && count < ft_strlen(big))
	{
		a = 0;
		while (big[count + a] == little[a] && big)
		{
			a++;
			if (count + a > len)
				return (NULL);
			if (little[a] == '\0')
				return ((char *)big + count);
		}
		count++;
	}
	return (NULL);
}
