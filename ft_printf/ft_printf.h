/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:53:40 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/21 13:15:34 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define BASEH_U "0123456789ABCDEF"
# define BASEH_L "0123456789abcdef"

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int number);
int		ft_putnbr_u(unsigned int number);
char	*ft_strchr(const char *string, int c);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		get_count(int n);
char	*ft_itoa(int n);
int		ft_hex(unsigned int nbr, char *base);
int		ft_ptr(unsigned long long nbr, char *base);

#endif