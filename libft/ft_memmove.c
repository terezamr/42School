/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:34:42 by marvin            #+#    #+#             */
/*   Updated: 2022/10/02 13:34:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t count)
{
    char *a;
    char *b;
    a = (char *)src;
    b = (char *)dest;
    while (count != 0)
    {
        b[count - 1] = a[count - 1];
        count = count - 1;
    }
    return dest;
}

int main( void )
{
  char target[21] = "a shiny white sphere";
  char * p = target + 8;  /* p points at the starting character
                          of the word we want to replace */
  char * source = target + 2; /* start of "shiny" */
 
  printf( "Before memmove, target is \"%s\"\n", target );
  ft_memmove( p, source, 5 );
  printf( "After memmove, target becomes \"%s\"\n", target );
}