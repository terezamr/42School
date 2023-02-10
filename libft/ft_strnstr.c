/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:06:54 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/10 14:31:50 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * 
 * 
 * @param big the string to be searched
 * @param little the string to be found
 * @param len the maximum number of characters to search
 * 
 * @return A pointer to the first occurrence of the substring little in the string big, or NULL if the
 * substring is not found.
 */
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
