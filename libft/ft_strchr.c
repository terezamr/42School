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

char *ft_strchr(const char *string, int c)
{
    int a;
    a = 0;
    while (string)
    {
        if (string[a] == c)
            return ((char *)string + a);
        a = a + 1;
    }
    if (c == '\0' && string[a] == '\0')
		return ((char *)string + a);
    return (NULL);
}

int main()
{
    char buffer1[40] = "computer program";
  char * ptr;
  int    ch = 'p';
 
  ptr = ft_strchr( buffer1, ch );
  printf( "The first occurrence of %c in '%s' is '%s'\n",
            ch, buffer1, ptr );
}