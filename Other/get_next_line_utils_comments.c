/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_comments.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:23:48 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/28 17:42:07 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
