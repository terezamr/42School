/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:16:23 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 14:16:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len])
        len = len + 1;
    return len;
}

void *ft_memchr(const void *string, int c, size_t count)
{
    int a;
    const char *s;
    s = (const char *)string;
    a = 0;
    while (string && count != 0)
    {
        if (s[a] == c)
            return ((char *)string + a);
        a = a + 1;
        count = count - 1;
    }
    if (c == '\0' && s[a] == '\0')
		return ((char *)string + a);
    return (NULL);
}

int main()
{
    char *result;
    result = ft_memchr("ola sou a tereza", 's', 4);
    printf( "%s\n", result);
    return 0;
}