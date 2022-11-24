/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:23:48 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/23 20:50:20 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s && s[len])
		len = len + 1;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s2)
		s2 = ft_calloc(1, 1);
	ptr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!ptr)
		return (0);	
	while (s1[a] != '\0')
	{
		ptr[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
		ptr[a++] = s2[b++];
	ptr[a] = '\0';
	free((char *)s1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	a;

	a = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	ptr = malloc(((int)len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (a < len)
	{
		ptr[a] = s[start + a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}

int	ft_strchr(const char *string)
{
	int	a;

	a = 0;
	while (string[a] != '\0')
	{
		if (string[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		size;
	int		c;

	c = 0;
	size = (int)ft_strlen(s) + 1;
	ptr = (char *)malloc(size + 1);
	if (!ptr || !s)
		return (NULL);
	while (c < size)
	{
		ptr[c] = s[c];
		c++;
	}
	return (ptr);
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
