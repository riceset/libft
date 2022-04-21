/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:53:05 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/21 02:08:59 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "colors.h"
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define ASCII_MIN 0
# define ASCII_MAX 127

static void	test_is(int (*is)(int));
static void	test_strlen(char *s);
static void	test_memset(void *s, int c, size_t len);
static void	test_bzero(void *b, size_t len);
static void	test_memcpy(const void *src, size_t n);
static void	test_memmove(const void *src, size_t n);
static void	test_memcpy_memmove(void *(*f)(void *, const void *, size_t),
								const void *src,
								size_t n);
static void test_strlcpy(char *src, size_t cpysize);
static void test_strlcat(char *dst, const char *src, size_t f_dst_s);
static void test_to_upper_lower(int (*f)(int c), int c);
static void test_strchr_strrchr(char *(*f)(const char *, int), const char *s, int c);

void	h_reset_memcpy_memmove(char ** or, char **ft);
void print_w_nul_nonprnt(char *title, char *s, size_t n);
static void test_strncmp(const char *s1, const char *s2, size_t n);

#endif
