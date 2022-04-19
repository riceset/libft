/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:25:02 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/19 00:13:26 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ASCII_MIN 0
#define ASCII_MAX 127

static void	test_is(int (*is)(int));

int	main(void)
{
	test_is(ft_isprint);
	return (0);
}

static void	test_is(int (*is)(int))
{
	char	n[8];

	if (is == ft_isalpha)
		strcpy(n, "isalpha");
	else if (is == ft_isdigit)
		strcpy(n, "isdigit");
	else if (is == ft_isalnum)
		strcpy(n, "isalnum");
	else if (is == ft_isascii)
		strcpy(n, "isascii");
	else if (is == ft_isprint)
		strcpy(n, "isprint");
	else
		return ;
	printf("🌲 \e[0;35m Tests for \"ft_%s\"\n", n);
	for (int i = ASCII_MIN; i <= ASCII_MAX; i++)
	{
		if (is(i))
		{
			if (isprint(i))
				printf("\e[0;32m '%c'\t%s\n", i, n);
			else
				printf("\e[0;32m '%02X'\t%s\n", i, n);
		}
		else
		{
			if (isprint(i))
				printf("\e[0;31m '%c'\t!%s\n", i, n);
			else
				printf("\e[0;31m '%02X'\t!%s\n", i, n);
		}
	}
}

static void	test_isdigit(void)
{
}
static void	test_isalnum(void)
{
}

static void	test_isascii(void)
{
}
static void	test_isprint(void)
{
}

static void	test_strlen(void)
{
}
static void	test_memset(void)
{
}

static void	test_bzero(void)
{
}
static void	test_memcpy(void)
{
}

static void	test_strlcpy(void)
{
}
static void	test_strlcat(void)
{
}
