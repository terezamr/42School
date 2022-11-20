/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:06:13 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/20 18:21:01 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char str, va_list arguments)
{
	if (str == 37)
		return (ft_putchar('%'));
	if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(arguments, int)));
	if (str == 'u')
		return (ft_putnbr_u(va_arg(arguments, unsigned int)));
	if (str == 'c')
		return (ft_putchar(va_arg(arguments, int)));
	if (str == 's')
		return (ft_putstr(va_arg(arguments, char *)));
	if (str == 'x')
		return (ft_hex(va_arg(arguments, unsigned long), "0123456789abcdef"));
	if (str == 'X')
		return (ft_hex(va_arg(arguments, unsigned long), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		arguments;
	int			len;
	int			i;

	// format = malloc(sizeof(t_format));
	// if (!format)
	// 	return (0);
	// format->len = 0;
	i = 0;
	len = 0;
	va_start(arguments, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%%", str[i + 1]))
		{
			len = len + check_format(str[++i], arguments);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len++;
			i++;
		}
	}
	va_end(arguments);
	return (len);
}

// #include <stdio.h>

// int main()
// {
// 	int	a;
// 	int	b;

// 	a = ft_printf("N %s\n", NULL);
// 	b = printf("N %s\n", NULL);
// 	printf("%d %d\n", a, b);
// }