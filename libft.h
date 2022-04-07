/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:20:12 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/06 12:41:34 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>

typedef unsigned long	t_size;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
t_size	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, t_size len);
void	ft_bzero(void *s, t_size n);
void	*ft_memcpy(void *dst, const void *src, t_size n);
void	*memmove(void *dest, const void *src, t_size n);

void	issmth_test(int (*smth)(int), int c);
void	strlen_test(const char *s);
void	memset_test(void);
void	bzero_test(void);
void	memcpy_test(const char *src);
void	memmove_test(void);
void	strlcpy_test(void);
void	strlcat_test(void);
void	toupper_test(void);
void	tolower_test(void);
void	strchr_test(void);
void	strrchr_test(void);
void	strncmp_test(void);
void	memchr_test(void);
void	memcmp_test(void);
void	strnstr_test(void);
void	atoi_test(void);

#endif
