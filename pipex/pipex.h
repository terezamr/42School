/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:27 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/10 13:08:27 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <fcntl.h> 
# include <sys/wait.h>

char	*check_path(char **paths, char *command);
void	command1(int *fd, char **right_path, char **param, char **envp);
void	command2(int *fd, char **right_path, char **param, char **envp);
void	pipex(char **param1, char **param2, char **right_path, char **envp);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_num(char const *str, char c);
char	**ft_split(char const *s, char c);

void	error(void);
char	**get_paths(char **envp);
void	free_double(char **path1, char **path2, char **path3);
void	free_path(char **right_path);

#endif