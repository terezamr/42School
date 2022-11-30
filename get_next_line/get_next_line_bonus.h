/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:59:12 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/30 12:47:41 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		check_n(char *string, int *flag);
void	*ft_calloc(size_t nmemb, size_t size);
char	*new_join(char *temp, char *buffer, int len);
int		get_count(char **temp);

#endif