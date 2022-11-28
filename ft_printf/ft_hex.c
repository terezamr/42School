/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:14:03 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/24 14:07:19 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_putnbr_base(unsigned int nbr, char *base, char *sp, int len_nbr)
{
	while (nbr >= 16)
	{
		sp[len_nbr - 1] = base[nbr % 16];
		nbr = nbr / 16;
		len_nbr--;
	}
	sp[len_nbr - 1] = base[nbr];
	return (0);
}

int	get_len(unsigned int number)
{
	int				count;
	int				base_len;

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

int	ft_hex(unsigned int nbr, char *base)
{
	int		len_nbr;
	char	*sp;
	int		i;

	i = 0;
	len_nbr = get_len(nbr);
	sp = malloc(sizeof(char) * len_nbr + 1);
	if (!sp)
		return (0);
	ft_putnbr_base(nbr, base, sp, len_nbr);
	sp[len_nbr] = '\0';
	while (sp[i])
		write(1, &sp[i++], 1);
	free(sp);
	return (i);
}
