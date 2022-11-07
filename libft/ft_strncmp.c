/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:24:44 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/07 12:35:53 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*a;
	unsigned char	*b;

	count = 0;
	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (a[count] == b[count] && count < n
		&& a[count] != '\0' && b[count] != '\0')
		count++;
	if (count == n)
		count--;
	return (a[count] - b[count]);
}
