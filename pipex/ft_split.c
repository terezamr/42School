/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:19:50 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/10 15:18:47 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
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

char	*ft_strnstr(const char *big, const char *little)
{
	size_t	count;
	size_t	a;

	count = 0;
	if (!little[0] || !little)
		return ((char *)big);
	while (little && count < ft_strlen(big))
	{
		a = 0;
		while (big[count + a] == little[a] && big)
		{
			a++;
			if (little[a] == '\0' && big[count + a] == '='
				&& big[0] == little[0])
				return ((char *)big + count + ft_strlen(little) + 1);
		}
		count++;
	}
	return (NULL);
}

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

int	get_num(char const *str, char c)
{
	int	nstr;
	int	i;

	nstr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			nstr++;
		}
		while (str[i] == c && str[i])
			i++;
	}
	return (nstr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		len;

	count = 0;
	ptr = (char **)malloc((get_num(s, c) + 1) * sizeof(char *));
	if (!s || !ptr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				s++;
				len++;
			}
			ptr[count++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	ptr[count] = NULL;
	return (ptr);
}
