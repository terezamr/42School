/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:17:36 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/29 16:22:17 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_s(char **temp, char **new_temp)
{
	int		count;

	count = 0;
	new_temp = NULL;
	if (temp != (void *)0)
		count = (int)ft_strlen(*temp);
	if (!new_temp)
		free(new_temp);
	return (count);
}

void	fill_buffer(char *buffer, int len)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (i < BUFFER_SIZE - len - 1)
			buffer[i] = buffer[i + len + 1];
		else
			buffer[i] = '\0';
		i++;
	}
}

char	*new_join(char *temp, char *buffer, int len)
{
	char	*new_temp;
	int		i;
	int		d;
	int		count;

	d = 0;
	if (!temp)
		temp = ft_calloc(1, 1);
	count = check_s(&temp, &new_temp);
	new_temp = malloc(count + len + 1);
	if (!new_temp)
		return (NULL);
	i = -1;
	while (temp[++i] != 0)
		new_temp[i] = temp[i];
	while (d < len)
		new_temp[i++] = buffer[d++];
	new_temp[i] = '\0';
	len--;
	fill_buffer(buffer, len);
	free(temp);
	return (new_temp);
}

char	*get_next_line(int fd)
{
	int			r;
	int			flag;
	int			len;
	char		*temp;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	flag = 0;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		while (fd > 0 && fd <= FOPEN_MAX && flag < BUFFER_SIZE)
			buffer[fd][flag++] = 0;
		return (0);
	}
	flag = 0;
	if (buffer[fd])
	{
		len = check_n(buffer[fd], &flag);
		temp = new_join(temp, buffer[fd], len + 1);
		if (flag == 1)
			return (temp);
	}
	while (1)
	{
		if (buffer[fd][0] == 0)
		{
			r = read(fd, buffer[fd], BUFFER_SIZE);
			if (r == 0 && !buffer[fd][0])
			{
				if (!temp[0])
				{
					free(temp);
					return (NULL);
				}
				return (temp);
			}
		}
		len = check_n(buffer[fd], &flag);
		temp = new_join(temp, buffer[fd], len + 1);
		if (flag == 1 || (r == 0 && check_n(buffer[fd], &flag) == -1))
			break ;
	}
	return (temp);
}

