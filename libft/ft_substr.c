/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:19:02 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/10 13:03:50 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Ft_substr() returns a pointer to a new string which is a substring of the string pointed to by s,
 * starting at index start and of length len.
 * 
 * @param s The string to be split.
 * @param start the index of the first character to include in the substring.
 * @param len the length of the substring
 * 
 * @return A pointer to a new string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;

	a = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(((int)len + 1) * sizeof(char));
	if (!ptr || !s)
		return (NULL);
	while (a < len)
	{
		ptr[a] = s[start + a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
