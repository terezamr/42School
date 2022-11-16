/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:59:06 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/16 17:36:31 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
