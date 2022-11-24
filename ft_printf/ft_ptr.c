/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:14:00 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/24 13:54:28 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_putnbr_base_ptr(unsigned long long nbr, char *b, char *sp, int len)
{
	while (nbr >= 16)
	{
		sp[len-- - 1] = b[nbr % 16];
		nbr = nbr / 16;
	}
	sp[len - 1] = b[nbr];
	return (0);
}

int	get_len_ptr(unsigned long long number)
{
	int					count;
	int					base_len;

	count = 0;
	base_len = 16;
	while (number >= (unsigned)base_len)
	{
		number /= base_len;
		count++;
	}
	count++;
	return (count);
}

int	ft_ptr(unsigned long long nbr, char *base)
{
	int		len_nbr;
	char	*sp;
	int		i;

	i = 0;
	if (nbr == 0)
		return (ft_putstr("(nil)"));
	len_nbr = get_len_ptr(nbr) + 2;
	sp = malloc(sizeof(char) * len_nbr + 1);
	if (!sp)
		return (0);
	ft_putnbr_base_ptr(nbr, base, sp, len_nbr);
	sp[len_nbr] = '\0';
	sp[0] = '0';
	sp[1] = 'x';
	while (sp[i])
		write(1, &sp[i++], 1);
	free(sp);
	return (i);
}
