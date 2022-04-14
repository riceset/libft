/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:39:32 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/14 16:39:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define CMDS 33

typedef enum e_tests
{
	o_isalpha = 1,
	o_isdigit,
	o_isalnum,
	o_isascii,
	o_isprint,
	o_strlen,
	o_memset,
	o_bzero,
	o_memcpy,
	o_memmove,
	o_strlcpy,
	o_strlcat,
	o_toupper,
	o_tolower,
	o_strchr,
	o_strrchr,
	o_strncmp,
	o_memchr,
	o_memcmp,
	o_strnstr,
	o_atoi,
	o_calloc,
	o_strdup,
	o_substr,
	o_strjoin,
	o_strtrim,
	o_split,
	o_itoa,
	o_strmapi,
	o_striteri,
	o_putchar_fd,
	o_putstr_fd,
	o_putendl_fd,
	o_putnbr_fd
} t_func;

t_func	decide(char *arg);
void	chr_test(int (*smth)(int), int c);
void	strlen_test(const char *s);
void	memset_test(char *b, int c, size_t len);
void	bzero_test(char *b, size_t len);
void	memcpy_test(const char *src);
void	memmove_test(const char *src);
void	strlcpy_test(char *dst, const char *src, size_t cpysize);
void	strlcat_test(char *dst, const char *src, size_t f_dst_s);
void	strchr_test(char *(*f)(const char *s, int c), const char *s, int c);
void	strncmp_test(const char *s1, const char *s2, size_t n);
void	memchr_test(const void *s, int c, size_t n);
void	memcmp_test(const void *v1, const void *v2, size_t n);
void	strnstr_test(const char *str, const char *substr, size_t len);
void	calloc_test(size_t count, size_t size);
void	atoi_test(const char *str);
void	substr_test(char const *s, unsigned int start, size_t len);
void	strjoin_test(char const *s1, char const *s2);
void	strtrim_test(char const *s1, char const *set);
void	split_test(char const *s, char c);
void	itoa_test(int n);
void	strmapi_test(char const *s, char (*f)(unsigned int, char));
void	putchar_fd_test(char c, int fd);
void	putstr_fd_test(char *s, int fd);
void	putnbr_fd_test(int n, int fd);

#endif
