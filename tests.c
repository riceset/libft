/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:25:02 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/19 23:08:52 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft.h"

int	main(void)
{
	test_is(ft_isprint);
	test_strlen("god");
	test_memset("AAA", '5', 4);
	test_bzero("hello world", 2);
	test_memcpy("Hello", 20);
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
	printf("\n" UCYN "Tests for ft_%s:\n" CRESET, n);
	for (int i = ASCII_MIN; i <= ASCII_MAX; i++)
	{
		if (is(i))
		{
			if (isprint(i))
				printf("'%c'\t" GRN "%s\n" CRESET, i, n);
			else
				printf("'%02X'\t" GRN "%s\n" CRESET, i, n);
		}
		else
		{
			if (isprint(i))
				printf("'%c'\t" RED "%s\n" CRESET, i, n);
			else
				printf("'%02X'\t" RED "%s\n" CRESET, i, n);
		}
	}
	strcpy(grn, GRN " ");
	strcat(grn, n);
	strcpy(red, RED " !");
	strcat(red, n);
	printf("\n" UCYN"\nOTHER TESTS:\n" CRESET);
	printf("ASCII_MIN - 1:\t%s\n" CRESET,
			is(ASCII_MIN - 1) ? grn : red);
	printf("ASCII_MAX + 1:\t%s\n" CRESET,
			is(ASCII_MAX + 1) ? grn : red);
	printf("INT_MIN:\t%s\n" CRESET,
			is(INT_MIN) ? grn : red);
	printf("INT_MAX:\t%s\n" CRESET,
			is(INT_MAX) ? grn : red);
}

static void	test_strlen(char *s)
{
	printf(UCYN "\nTests for ft_strlen:\n" CRESET);
	printf("str:\t\"%s\"\nor: \t'%zu'\nft: \t'%zu'\nres:\t%s\n\n" CRESET, s,
			ft_strlen(s), strlen(s),
			(ft_strlen(s) == strlen(s)) ? GRN "OK" : RED "KO");
	s = "";
	printf("str:\t\"%s\"\nor: \t'%zu'\nft: \t'%zu'\nres:\t%s\n\n" CRESET, s,
			ft_strlen(s), strlen(s),
			(ft_strlen(s) == strlen(s)) ? GRN "OK" : RED "KO");
	s = "Hello!";
	printf("str:\t\"%s\"\nor: \t'%zu'\nft: \t'%zu'\nres:\t%s\n\n" CRESET, s,
			ft_strlen(s), strlen(s),
			(ft_strlen(s) == strlen(s)) ? GRN "OK" : RED "KO");
}

static void	test_memset(void *s, int c, size_t len)
{
	char	*or_s;
	char	*ft_s;

	or_s = strdup(s);
	ft_s = strdup(s);
	printf(UCYN "\nTests for ft_memset:\n" CRESET);
	printf("'%c' --> \"%s\" (%zu)\nor: \t\"%s\"\nft: \t\"%s\"\nres:\t%s\n" CRESET,
			c,
			(char *)s,
			len,
			(char *)memset(or_s, c, len),
			(char *)ft_memset(ft_s, c, len),
			strcmp(or_s, ft_s) == 0 ? GRN "OK" : RED "KO");
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
	printf(UCYN "\nTests for ft_bzero:\n" CRESET);
	printf("'\\0' --> \"%s\" (%zu)\n" CRESET,
			(char *)b,
			len);
	printf("or:\t\"");
	for (size_t i = 0, n = ft_strlen((char *)b); i < ((n > len) ? n
				+ 1 : len); i++)
	{
		if (or_s[i])
			printf("%c", or_s[i]);
		else
			printf(REDHB "\\0" CRESET);
	}
	printf("\"\nft:\t\"");
	for (size_t i = 0, n = ft_strlen((char *)b); i < ((n > len) ? n
				+ 1 : len); i++)
	{
		if (ft_s[i])
			printf("%c", ft_s[i]);
		else
			printf(REDHB "\\0" CRESET);
	}
	printf("\"\nres:\t%s\n" CRESET, memcmp(or_s, ft_s, strlen((char *)b)
				+ 1) == 0 ? GRN "OK" : RED "KO");
	free(or_s);
	free(ft_s);
}
static void	test_memcpy(const void *src, size_t n)
{
	char	*or_s;
	char	*ft_s;

	or_s = malloc(strlen(src) + 1);
	ft_s = malloc(strlen(src) + 1);
	memset(or_s, '.', strlen(src) + 1);
	memset(ft_s, '.', strlen(src) + 1);
	printf(UCYN "\nTests for ft_memcpy:\n" CRESET);
	printf("src:\t\"%s\" (%zu)\n", (char *)src, n);
	printf("or:\t\"%s\"\nft:\t\"%s\"\n", or_s, ft_s);
	memcpy(or_s, src, n);
	ft_memcpy(ft_s, src, n);
	printf("or:\t\"");
	for (size_t i = 0; i < n; i++)
	{
		if (isprint(or_s[i]))
			printf("%c", or_s[i]);
		else if (or_s[i] == '\0')
			printf(REDHB "\\0" CRESET);
		else
			printf(BLKHB "\\😈" CRESET);
	}
	printf("\"\nft:\t\"");
	for (size_t i = 0; i < n; i++)
	{
		if (isprint(ft_s[i]))
			printf("%c", ft_s[i]);
		else if (ft_s[i] == '\0')
			printf(REDHB "\\0" CRESET);
		else
			printf(BLKHB "\\😈" CRESET);
	}
	printf("\"\nres:\t%s\n" CRESET, memcmp(or_s, ft_s, strlen((char *)src)
				+ 1) == 0 ? GRN "OK" : RED "KO");
	free(or_s);
	free(ft_s);
}
static void	test_strlcpy(void)
{
	printf("\n\e[4;36mTests for ft_memmove:\n\e[0;0m");
}
static void	test_strlcat(void)
{
	printf("\n\e[4;36mTests for ft_strlcpy:\n\e[0;0m");
}
