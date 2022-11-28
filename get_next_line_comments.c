/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:23:48 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/28 12:35:36 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s || s[0] == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	check_n(char *string, int *flag)
{
	int	a;

	a = -1;
	while (string[++a] != 0)
	{
		if (string[a] == '\n')
		{
			*flag = 1;
			return (a);
		}
	}
	return (a);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

char	*new_join(char *temp, char *buffer, int len)
{
	int		count;
	char	*new_temp;
	int		i;
	int		d;

	count = 0;
	i = 0;
	d = 0;
	new_temp = NULL;
	// se existir temp calcular o .len()
	if (!temp)
		temp = ft_calloc(1, 1);
	if (temp[0] != '\0')
		count = ft_strlen(temp);
	// alocar new_temp
	if (!new_temp)
		free(new_temp);
	new_temp = malloc(count + len + 1);
	if (!new_temp)
		return (NULL);
	// se existir e enquanto, copiar temp a new_temp
	while (temp[i] != '\0')
	{
		new_temp[i] = temp[i];
		i++;
	}
	// enquanto i <= len -> copiar buffer a new_temp
	while (d < len)
		new_temp[i++] = buffer[d++];
	new_temp[i] = '\0';
	// shiftar o buffer, mas e importante como e que o fazes deves correr de 0 ate BUFFERSIZE - 1
	i = 0;
	len--;
	while (buffer[i])
	{
		if (i < BUFFER_SIZE - len - 1)
		{
			buffer[i] = buffer[i + len + 1];
			i++;
		}
		else
			buffer[i++] = '\0';
	}
	free(temp);
	return (new_temp);
}
