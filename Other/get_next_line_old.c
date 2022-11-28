/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:17:36 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/25 15:03:00 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(char *string)
{
	int	a;

	a = 0;
	if (string == 0)
		return (-1);
	while (string[a] != '\0')
	{
		if (string[a] == '\n')
			return (a);
		a++;
	}
	return (-1);
}

char	*check_nextl(char *nextl)
{
	int		c;
	char	*temp;

	c = check_n(nextl);
	if (c >= 0)
	{
		temp = ft_substr(nextl, 0, c + 1);
		nextl = ft_substr(nextl + c + 1, 0, BUFFER_SIZE);
		return (temp);
	}
	return (NULL);
}

char	*get_l(char *buffer, char *nextl, size_t len)
{
	char	*temp;
	char	*aux;

	aux = ft_substr(buffer, 0, len);
	temp = ft_strjoin(nextl, aux);
	free(aux);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*nextl;
	size_t		len;
	int			r;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!nextl)
		nextl = ft_calloc(sizeof(char), 2);
	while (1)
	{
		temp = check_nextl(nextl);
		if (temp != NULL)
			return (temp);
		buffer = calloc((BUFFER_SIZE + 1) * sizeof(char), 1);
		if (!buffer)
			return (NULL);
		r = read(fd, buffer, BUFFER_SIZE);
		len = check_n(buffer) + 1;
		if (len > 0)
		{
			aux = temp;
			temp = get_l(buffer, nextl, len);
			free(aux);
			nextl = ft_substr(buffer + len, 0, BUFFER_SIZE);
			free(buffer);
			buffer = NULL;
			return (temp);
		}
		else if (len == 0)
		{
			nextl = ft_strjoin(nextl, buffer);
			free(buffer);
			buffer = NULL;
		}
		if (r == 0 && check_n(nextl) == -1)
		{
			if (nextl[0] != '\0')
				return (nextl);
			free(nextl);
			nextl = NULL;
			return (NULL);
		}
	}
	return (NULL);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*a;

// 	fd = open("./a.txt", O_RDONLY);
// 	printf("gnl 1 %s.\n", a = get_next_line(fd));
// 	free(a);
// }
