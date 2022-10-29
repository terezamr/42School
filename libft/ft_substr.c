/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:19:02 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/29 15:10:55 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;

	a = 0;
	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr || !s)
		return (NULL);
	while (a < len && start < ft_strlen(s))
	{
		ptr[a] = s[start + a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
