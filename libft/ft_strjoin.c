/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:07:12 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/29 13:34:00 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		a;
	int		b;

	a = 0;
	b = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr || !s1 || !s2)
		return (NULL);
	while (s1[a])
	{
		ptr[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		ptr[a] = s2[b];
		a++;
		b++;
	}
	ptr[a] = '\0';
	return (ptr);
}
