/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:19:02 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/07 18:30:59 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;
	size_t	count;

	a = 0;
	count = ft_strlen(s);
	if (start > count)
		len = 0;
	else if (len >= count)
	{
		len = count - start;
	}
	ptr = malloc(((int)len + 1) * sizeof(char));
	if (!ptr || !s)
		return (NULL);
	while (a < len && start < count)
	{
		ptr[a] = s[start + a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
