/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:25:02 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/19 18:40:52 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ASCII_MIN 0
#define ASCII_MAX 127

static void	test_is(int (*is)(int));
static void	test_strlen(char *s);
static void	test_memset(void *s, int c, size_t len);
static void	test_bzero(void *b, size_t len);

int	main(void)
{
	test_is(ft_isprint);
	test_strlen("god");
	test_memset("AAA", '5', 4);
	test_bzero("Hello", 3);
	return (0);
}

static void	test_is(int (*is)(int))
{
	char	n[8];
	char	grn[16];
	char	red[17];
	int		i;

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
	printf("\n🌲 \e[4;36mTests for ft_%s:\n\e[0;0m", n);
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
	printf("ASCII_MIN - 1:\t%s\t\e[0;0m\n",
			is(ASCII_MIN - 1) ? grn : red);
	printf("ASCII_MAX + 1:\t%s\t\e[0;0m\n",
			is(ASCII_MAX + 1) ? grn : red);
	printf("INT_MIN:\t%s\t\e[0;0m\n",
			is(INT_MIN) ? grn : red);
	printf("INT_MAX:\t%s\t\e[0;0m\n",
			is(INT_MAX) ? grn : red);
}

static void	test_strlen(char *s)
{
	printf("\n🌲 \e[4;36mTests for ft_strlen:\n\e[0;0m");
	printf("str:\t\"%s\"\nor: \t'%zu'\nft: \t'%zu'\nres:\t%s\n\e[0;0m\n", s,
			ft_strlen(s), strlen(s),
			(ft_strlen(s) == strlen(s)) ? "\e[0;32m OK" : "\e[0;33m KO");
	s = "";
	printf("str:\t\"%s\"\nor: \t'%zu'\nft: \t'%zu'\nres:\t%s\n\e[0;0m\n", s,
			ft_strlen(s), strlen(s),
			(ft_strlen(s) == strlen(s)) ? "\e[0;32m OK" : "\e[0;33m KO");
	s = "Hello!";
	printf("str:\t\"%s\"\nor: \t'%zu'\nft: \t'%zu'\nres:\t%s\n\e[0;0m\n", s,
			ft_strlen(s), strlen(s),
			(ft_strlen(s) == strlen(s)) ? "\e[0;32m OK" : "\e[0;33m KO");
}

static void	test_memset(void *s, int c, size_t len)
{
	char	*or_s;
	char	*ft_s;

	or_s = strdup(s);
	ft_s = strdup(s);
	printf("\n🌲 \e[4;36mTests for ft_memset:\n\e[0;0m");
	printf("'%c' --> \"%s\" (%zu)\nor: \t\"%s\"\nft: \t\"%s\"\nres:\t%s\e[0;0m\n",
			c,
			(char *)s,
			len,
			(char *)memset(or_s, c, len),
			(char *)ft_memset(ft_s, c, len),
			strcmp(or_s, ft_s) == 0 ? "\e[0;32m OK" : "\e[0;31m KO");
	free(or_s);
	free(ft_s);
}

static void	test_bzero(void *b, size_t len)
{
	char	*or_s;
	char	*ft_s;

	or_s = strdup(b);
	ft_s = strdup(b);
	bzero(or_s, len);
	bzero(ft_s, len);
	printf("\n🌲 \e[4;36mTests for ft_bzero:\n\e[0;0m");
	printf("'\\0' --> \"%s\" (%zu)\e[0;0m\n",
			(char *)b,
			len);
	printf("or:\t\"");
	for (size_t i = 0, n = ft_strlen((char *)b); i < n; i++)
	{
		if (or_s[i])
			printf("%c", or_s[i]);
		else
			printf("\\0");
	}
	printf("\"\nft:\t\"");
	for (size_t i = 0, n = ft_strlen((char *)b); i < n; i++)
	{
		if (ft_s[i])
			printf("%c", or_s[i]);
		else
			printf("\\0");
	}
	printf("\"\n");
	printf("res:\t%s\e[0;0m\n", memcmp(or_s, ft_s, strlen((char *)b)
				+ 1) == 0 ? "\e[0;32m OK" : "\e[0;31m KO");
	puts("");
	free(or_s);
	free(ft_s);
}
static void	test_memcpy(void)
{
	printf("\n🌲 \e[4;36mTests for ft_memcpy:\n\e[0;0m");
}
static void	test_strlcpy(void)
{
	printf("\n🌲 \e[4;36mTests for ft_memmove:\n\e[0;0m");
}
static void	test_strlcat(void)
{
	printf("\n🌲 \e[4;36mTests for ft_strlcpy:\n\e[0;0m");
}
