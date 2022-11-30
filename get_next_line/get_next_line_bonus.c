/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:17:36 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/30 12:49:06 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	fill_buffer(char *buffer, int len)
{
	int	i;
	int	remain_b;

	remain_b = BUFFER_SIZE - len;
	i = 0;
	while (buffer[i])
	{
		if (i < remain_b)
			buffer[i] = buffer[i + len];
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
	new_temp = NULL;
	count = get_count(&temp) + 1;
	new_temp = malloc(count + len + 1);
	if (!new_temp)
		return (NULL);
	i = -1;
	while (temp[++i] != 0)
		new_temp[i] = temp[i];
	while (d < len)
		new_temp[i++] = buffer[d++];
	new_temp[i] = '\0';
	fill_buffer(buffer, len);
	free(temp);
	return (new_temp);
}

char	*get_line_aux(char *buffer, char *temp, int *flag, int fd)
{
	int	r;
	int	len;

	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0 && !buffer[0])
		{
			if (temp[0] == 0)
			{
				free(temp);
				temp = NULL;
			}
			break ;
		}
		len = check_n(buffer, flag);
		temp = new_join(temp, buffer, len + 1);
		if (*flag == 1)
			break ;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	int			flag;
	int			len;
	char		*temp;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	flag = 0;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX || read(fd, 0, 0) < 0)
	{
		while (fd > 0 && fd < FOPEN_MAX && flag < BUFFER_SIZE)
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
	temp = get_line_aux(buffer[fd], temp, &flag, fd);
	return (temp);
}
