/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:16:24 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/07 17:35:08 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num(char const *str, char c)
{
	int	nstr;
	int	i;

	nstr = 0;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] != c)
		{
			while (str[i] != c)
				i++;
			nstr++;
		}
		while (str[i] == c)
			i++;
	}
	return (nstr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		a;
	int		d;

	count = 0;
	a = 0;
	d = 0;
	ptr = (char **)malloc((get_num(s, c) + 1) * sizeof(char *));
	if (!s || !ptr)
		return (NULL);
	while (a < (int)ft_strlen(s))
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
	ptr[get_num(s, c)] = NULL;
	return (ptr);
}

// int	main(void)
// {
// 	char	**ptr =ft_split("Tripouille", ' ');
// 	printf("%s\n", ptr[0]);
// 	printf("%p\n", ptr[1]);
// }