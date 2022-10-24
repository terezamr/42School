/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:38:42 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 17:38:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int ft_isalnum(int num);
int ft_isalpha(int let);
int ft_isascii(int let);
int ft_isdigit(int num);
int ft_isprint(int let);
void *ft_memmove(void *dest, const void *src, size_t count);
void *memset(void *ptr, int x, size_t n);
char *ft_strchr(const char *string, int c);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int ft_strlen(const char *str);
char *ft_strrchr(const char *string, int c);
int ft_tolower(int c);
int ft_toupper(int c);

#endif