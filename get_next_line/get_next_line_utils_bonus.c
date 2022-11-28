/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:23:48 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/28 17:25:00 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s || s[0] == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	check_n(char *string, int *flag)
{
	int	a;

	a = -1;
	while (string[++a] != 0)
	{
		if (string[a] == '\n')
		{
			*flag = 1;
			return (a);
		}
	}
	return (a);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

