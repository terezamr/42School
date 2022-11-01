/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:16:24 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/01 16:33:52 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_num(char const *str, char c)
{
	size_t		nstr;
	size_t		a;

	nstr = 0;
	a = 0;
	while (a < ft_strlen(str))
	{
		if (str[a] != c)
		{
			while (str[a] != c)
				a++;
			nstr++;
		}
		while (str[a] == c)
			a++;
	}
	return (nstr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	size_t	a;
	size_t	d;

	count = 0;
	a = 0;
	d = 0;
	if (!s || !(ptr = (char **)malloc((get_num(s, c) + 1) * sizeof(char *))))
		return (NULL);
	ptr[get_num(s, c)] = NULL;
	while (a < ft_strlen(s))
	{
		while (s[a] != '\0' && s[a] == c)
		{
			a++;
			d++;
		}
		if (s[a] != '\0' && s[a] != c)
		{
			while (s[a] != '\0' && s[a] != c)
				a++;
			ptr[count] = ft_substr(s, d, a - d);
			count++;
			a++;
			d = a;
		}
	}
	return (ptr);
}

