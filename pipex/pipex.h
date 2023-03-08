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

typedef struct s_list
{
	char			*command;
	char			**param;
	char			*path;
	char			*inputf;
	char			*outputf;
	struct s_list	*next;
	//struct s_list	*prev;
}					t_list;

void	command1(int *fd, char **right_path, char **param, char **envp);
void	command2(int *fd, char **right_path, char **param, char **envp);
void	pipex(char **param1, char **param2, char **right_path, char **envp);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_num(char const *str, char c);
char	**ft_split(char const *s, char c);

void	ft_strn(char *str);
void	error(int status);
char	**get_paths(char **envp);
void	free_double(char **path1, char **path2, char **path3);
void	free_path(char **right_path);

char	*check_path(char **paths, char *command);
void	get_rightp(char **right_path, char **paths, char **com, char **argv);
void	get_commands(char **param1, char **param2, char **commands);
//char	**get_path_bonus(char **param, char **paths, char **right_paths, int max);
//oid	get_files_bonus(char **paths, char **argv, int command_number);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char **str, char **paths, int i, int commands);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*go_back(t_list *stack);

#endif