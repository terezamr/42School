/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:06:13 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/24 13:38:28 by mvicente         ###   ########.fr       */
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
		return (ft_hex(va_arg(arguments, unsigned int), BASEH_L));
	if (str == 'X')
		return (ft_hex(va_arg(arguments, unsigned int), BASEH_U));
	if (str == 'p')
		return (ft_ptr(va_arg(arguments, unsigned long long), BASEH_L));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		arguments;
	int			len;
	int			i;

	i = 0;
	len = 0;
	va_start(arguments, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%%", str[i++ + 1]))
		{
			len = len + check_format(str[i], arguments);
			i++;
		}
		else
		{
			len = len + write(1, &str[i], 1);
			i++;
		}
	}
	va_end(arguments);
	return (len);
}

// int main()
// {
// 	ft_printf("%x\n", -10);
// 	printf("%x", -10);
// }