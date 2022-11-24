/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:07:12 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/16 17:46:40 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*It takes two strings and joins them together.
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 * @return A pointer to a new string that is the result of the
 * concatenation of s1 and s2.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		a;
	int		b;

	a = 0;
	b = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr || !s1 || !s2)
		return (0);
	while (s1[a] != '\0')
	{
		ptr[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		ptr[a] = s2[b];
		a++;
		b++;
	}
	ptr[a] = '\0';
	return (ptr);
}
