/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:25:02 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/19 01:59:26 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
	char	grn[16];
	char	red[17];

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
	printf("🌲 \e[4;36mTests for ft_%s:\n", n);
	for (int i = ASCII_MIN; i <= ASCII_MAX; i++)
	{
		if (is(i))
		{
			if (isprint(i))
				printf("\e[0;0m'%c'\t\e[0;32m%s\n", i, n);
			else
				printf("\e[0;0m'%02X'\t\e[0;32m%s\n", i, n);
		}
		else
		{
			if (isprint(i))
				printf("\e[0;0m'%c'\t\e[0;31m!%s\n", i, n);
			else
				printf("\e[0;0m'%02X'\t\e[0;31m!%s\n", i, n);
		}
	}
	strcpy(grn, "\e[0;32m ");
	strcat(grn, n);
	strcpy(red, "\e[0;31m !");
	strcat(red, n);
	printf("\n🌳 \e[4;36mOTHER TESTS:\n\e[0;0m");
	printf("ASCII_MIN:\t%s\t\e[0;0m\n",
			is(ASCII_MIN) ? grn : red);
	printf("ASCII_MAX:\t%s\t\e[0;0m\n",
			is(ASCII_MAX) ? grn : red);
	printf("INT_MIN:\t%s\t\e[0;0m\n",
			is(INT_MIN) ? grn : red);
	printf("INT_MAX:\t%s\t\e[0;0m\n",
			is(INT_MAX) ? grn : red);
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
