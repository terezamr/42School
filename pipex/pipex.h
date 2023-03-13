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
}					t_list;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*check_path(char **paths, char *command);
char	**get_paths(char **envp);
void	check_files(char *str);

void	ft_strn(char *str);
void	error(int status);
t_list	*ft_lstlast(t_list *lst);
void	free_double(char **path1);
void	free_lst(t_list *lst);

int		get_num_words(char *str, char c);
char	*get_word(char *str, char c);
char	**ft_split(char *str, char c);

void	initialize_lst(t_list **new);
t_list	*ft_lstnew(char **str, char **paths, int i, int commands);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*create_list(char **argv, int commands, t_list *lst, char **paths);

void	do_dups(int fin, int fout, int fd_close);
int		open_f(t_list *node, int flag);
void	command(int *fd, t_list *lst, char **envp, int i);
void	pipex(t_list *lst, char **envp);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little);

#endif