/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:53:40 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/20 17:59:49 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

// typedef struct s_format
// {
// 	int	len;
// }		t_format;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int number);
int		ft_putnbr_u(unsigned int number);
char	*ft_strchr(const char *string, int c);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		get_count(int n);
char	*ft_itoa(int n);
int		ft_hex(unsigned long nbr, char *base);

#endif