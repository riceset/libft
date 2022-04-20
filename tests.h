/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:53:05 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/19 23:22:05 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "colors.h"

# define ASCII_MIN 0
# define ASCII_MAX 127

static void	test_is(int (*is)(int));
static void	test_strlen(char *s);
static void	test_memset(void *s, int c, size_t len);
static void	test_bzero(void *b, size_t len);
static void	test_memcpy(const void *src, size_t n);

#endif
