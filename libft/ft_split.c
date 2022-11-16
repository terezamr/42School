/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:16:24 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/16 16:11:45 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
