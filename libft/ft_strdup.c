/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:31:52 by mvicente          #+#    #+#             */
/*   Updated: 2022/10/29 12:15:50 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, size + 1);
	return (ptr);
}
