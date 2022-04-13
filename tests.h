/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:39:32 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/12 21:47:57 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

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
void	atoi_test(const char *str);

#endif
