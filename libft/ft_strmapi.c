/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:59:06 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/17 10:30:25 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_strmapi() applies the function f to each character of the string given as argument
 * by giving its index as first argument to create a “fresh” new string (with malloc(3)) resulting from
 * the successive applications of f
 * 
 * @param s The string to be mapped.
 * @param f The function to be applied to each character of s and its index.
 * 
 * @return A pointer to a new string.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*ptr;

	a = 0;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr || !s)
		return (NULL);
	while (s[a] != '\0')
	{
		ptr[a] = f(a, s[a]);
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
