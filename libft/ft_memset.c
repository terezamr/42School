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

void *memset(void *ptr, int x, size_t n)
{
    char *a;
    a = (char *)ptr;
    while (n != 0)
    {
        a[n - 1] = x;
        n = n - 1;
    }
    return (ptr);
}

int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);
  
    // Fill 8 characters starting from str[13] with '.'
    memset(str + 13, '.', 8*sizeof(char));
  
    printf("After memset():  %s", str);
    return 0;
}