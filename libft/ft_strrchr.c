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

char *ft_strrchr(const char *string, int c)
{
    int b;
    b = ft_strlen(string);
    if (c == '\0' && string[b] == '\0')
		return ((char *)string + b);
    b = b - 1;
    while (b != 0)
    {
        if (string[b] == c)
            return ((char *)string + b);
        b = b - 1;
    }
    return (NULL);
}

int main()
{
    char buffer1[40] = "computer program";
  char * ptr;
  int    ch = 'p';
 
  ptr = ft_strrchr( buffer1, ch );
  printf( "The last occurrence of %c in '%s' is '%s'\n",
            ch, buffer1, ptr );
}