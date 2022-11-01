/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:19:02 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/01 14:44:05 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;

	a = 0;
	ptr = malloc((len + 1) * sizeof(char));
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

