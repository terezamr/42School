/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_comments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:23:48 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/28 17:43:06 by mvicente         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	int			r;
	int			flag;
	int			len;
	char		*temp;
	static char	buffer[BUFFER_SIZE];

	flag = 0;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer[0] = 0;
		return (0);
	}
	if (buffer[0])
	{
		len = check_n(buffer, &flag);
		temp = new_join(temp, buffer, len + 1);
		if (flag == 1)
			return (temp);
	}
	while (1)
	{
		if (buffer[0] == 0)
		{
			r = read(fd, buffer, BUFFER_SIZE);
			if (r == 0 && !buffer[0])
				return (temp);
		}
		len = check_n(buffer, &flag);
		temp = new_join(temp, buffer, len + 1);
		if (flag == 1 || (r == 0 && check_n(buffer, &flag) == -1))
			break ;
	}
	return (temp);
}

int	main(void)
{
	int	fd;

	fd = open("a.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
