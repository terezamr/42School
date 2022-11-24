/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:34:26 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/24 13:53:07 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		f;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	f = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == f)
		i = 0;
	while (f != 0 && ft_strchr(set, s1[f - 1]))
		f--;
	ptr = ft_substr(s1, i, f - i);
	return (ptr);
}
