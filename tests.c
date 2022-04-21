/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:25:02 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/21 01:23:36 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "libft.h"
#include "tests.h"
#include <stddef.h>

int	main(void)
{
	// test_is(ft_isprint);
	// test_strlen("god");
	test_memset("AAA", '5', 4);
	// test_bzero("hello world", 2);
	// test_memcpy_memmove(ft_memmove, "Hello", 6);
	// test_strlcpy("Hello", -1);
	// test_strlcat("Hello ", "World", 12);
	// test_to_upper_lower(ft_tolower, 'C');
	// test_strchr_strrchr(ft_strchr, "hello\0ccc", '\0');
}

//Helper function for test_memcpy_memmove
//that resets all given strings to "WATERMELONJUICE".
static void	h_reset_memcpy_memmove(char ** or, char **ft)
{
#define TEST_STR "WATERMELONJUICE"
	* or = strcpy(malloc(16), TEST_STR);
	*ft = strcpy(malloc(16), TEST_STR);
}

static void print_w_nul_nonprnt(char *title, char *s, size_t n)
{
	printf("%s:\t\"", title);
	for (size_t i = 0; i < n; i++)
	{
		if (isprint(s[i]))
			printf("%c", s[i]);
		else if (s[i] == '\0')
			printf(REDHB "\\0" CRESET);
		else
			printf(BLKHB "\\😈" CRESET);
	}
	printf("\"\n");
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
	printf("\n" UCYN "\nOTHER TESTS:\n" CRESET);
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

	printf("'%c' -->\t(%zu)\n", c, len);
	print_w_nul_nonprnt("src", s, ft_strlen(s) + 1 > len ? ft_strlen(s) + 1 : len);
	print_w_nul_nonprnt("or", (char *)memset(or_s, c, len), ft_strlen(s) + 1 > len ? ft_strlen(s) + 1 : len);
	print_w_nul_nonprnt("ft", (char *)ft_memset(ft_s, c, len), ft_strlen(s) + 1 > len ? ft_strlen(s) + 1 : len);
	printf("res:\t%s\n", strcmp(or_s, ft_s) == 0 ? GRN "OK" : RED "KO");
	// printf("'%c' --> \"%s\" (%zu)\nor: \t\"%s\"\nft: \t\"%s\"\nres:\t%s\n" CRESET,
	// 		c,
	// 		(char *)s,
	// 		len,
	// 		(char *)memset(or_s, c, len),
	// 		(char *)ft_memset(ft_s, c, len),
	// 		strcmp(or_s, ft_s) == 0 ? GRN "OK" : RED "KO");

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

	print_w_nul_nonprnt("or", or_s, ft_strlen(b) + 1 > len ? ft_strlen(b) + 1 : len);
	print_w_nul_nonprnt("ft", ft_s, ft_strlen(b) + 1 > len ? ft_strlen(b) + 1 : len);
	printf("res:\t%s\n" CRESET, memcmp(or_s, ft_s, strlen((char *)b)
			+ 1) == 0 ? GRN "OK" : RED "KO");
	free(or_s);
	free(ft_s);
}

static void	test_memcpy_memmove(void *(*f)(void *, const void *, size_t),
								const void *src,
								size_t n)
{
	char	*or_s;
	char	*ft_s;
	char	*ft;

	if (f == ft_memcpy)
		printf(UCYN "\nTests for ft_memcpy:\n" CRESET);
	else if (f == ft_memmove)
		printf(UCYN "\nTests for ft_memmove:\n" CRESET);
	or_s = memset(malloc(strlen(src) + 1), '.', strlen(src) + 1);
	ft_s = memset(malloc(strlen(src) + 1), '.', strlen(src) + 1);
	printf("src:\t\"%s\" (%zu)\n", (char *)src, n);
	printf("or:\t\"%s\"\nft:\t\"%s\"\n", or_s, ft_s);
	if (f == ft_memcpy)
		memcpy(or_s, src, n);
	else if (f == ft_memmove)
		memmove(or_s, src, n);
	f(ft_s, src, n);
	print_w_nul_nonprnt("or", or_s, (ft_strlen(src) + 1 > n) ? ft_strlen(src) + 1 : n);
	print_w_nul_nonprnt("ft", ft_s, (ft_strlen(src) + 1 > n) ? ft_strlen(src) + 1 : n);
	printf("res:\t%s\n" CRESET, memcmp(or_s, ft_s, strlen((char *)src)
			+ 1) == 0 ? GRN "OK" : RED "KO");
	free(or_s);
	free(ft_s);
	printf("\n😎 " UCYN "memcpy/memmove comparison:\n" CRESET);
	char * or ;
	h_reset_memcpy_memmove(& or, &ft);
	printf(BHGRN "\nPATTERN 1 (dest < src):\n" CRESET);
	memcpy(or, or + 5, 5);
	ft_memcpy(ft, ft + 5, 5);
	printf("or_cpy: \"%s\"\n", or);
	printf("ft_cpy: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	memmove(or, or +5, 5);
	ft_memmove(ft, ft + 5, 5);
	printf("or_mov: \"%s\"\n", or);
	printf("ft_mov: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	printf(BHGRN "\nPATTERN 1 (dest <= src):\n" CRESET);
	memcpy(or, or +5, 10);
	ft_memcpy(ft, ft + 5, 10);
	printf("or_cpy: \"%s\"\n", or);
	printf("ft_cpy: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	memmove(or, or +5, 10);
	ft_memmove(ft, ft + 5, 10);
	printf("or_mov: \"%s\"\n", or);
	printf("ft_mov: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	printf(BHBLU "\nPATTERN 2 (src < dst):\n" CRESET);
	memcpy(or +10, or, 5);
	ft_memcpy(ft + 10, ft, 5);
	printf("or_cpy: \"%s\"\n", or);
	printf("ft_cpy: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	memmove(or +10, or, 5);
	ft_memmove(ft + 10, ft, 5);
	printf("or_mov: \"%s\"\n", or);
	printf("ft_mov: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	printf(BHBLU "\nPATTERN 2 (src <= dst):\n" CRESET);
	//UNDEFINED
	//https://stackoverflow.com/questions/24148788/memcpy-gives-different-output-in-different-compiler
	memcpy(or +5, or, 10);
	ft_memcpy(ft + 5, ft, 10);
	printf("or_cpy: \"%s\"\n", or);
	printf("ft_cpy: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	memmove(or +5, or, 10);
	ft_memmove(ft + 5, ft, 10);
	printf("or_mov: \"%s\"\n", or);
	printf("ft_mov: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	printf(BHGRN "\nPATTERN 3 (dest == src):\n" CRESET);
	memcpy(or +5, or +5, 5);
	ft_memcpy(ft + 5, ft + 5, 5);
	printf("or_cpy: \"%s\"\n", or);
	printf("ft_cpy: \"%s\"\n", ft);
	free(or);
	free(ft);
	h_reset_memcpy_memmove(& or, &ft);
	memmove(or +5, or +5, 5);
	ft_memmove(ft + 5, ft + 5, 5);
	printf("or_mov: \"%s\"\n", or);
	printf("ft_mov: \"%s\"\n", ft);
	free(or);
	free(ft);
}

static void	test_strlcpy(char *src, size_t cpysize)
{
	char	*ft;

	printf(UCYN "\nTests for ft_strlcpy:\n" CRESET);
	// print_w_nul_nonprnt("src", src, ft_strlen(src) + 1);
	printf("sr:    \"");
	for (size_t i = 0, n = ft_strlen(src) + 1; i < n; i++)
	{
		if (src[i])
			printf("%c", src[i]);
		else
			printf(REDHB "\\0" CRESET);
	}
	printf("\"\n");
	printf("or:    \"");
	char * or = malloc(ft_strlen(src) + 1);
	strlcpy(or, src, cpysize);
	// print_w_nul_nonprnt("or", or, ft_strlen(src) + 1);
	for (size_t i = 0, n = ft_strlen(src) + 1; i < n; i++)
	{
		if (or [i])
			printf("%c", or [i]);
		else
			printf(REDHB "\\0" CRESET);
	}
	printf("\"\n");
	printf("ft:    \"");
	ft = malloc(ft_strlen(src) + 1);
	strlcpy(ft, src, cpysize);
	// print_w_nul_nonprnt("ft", ft, ft_strlen(src) + 1);
	for (size_t i = 0, n = ft_strlen(src) + 1; i < n; i++)
	{
		if (ft[i])
			printf("%c", ft[i]);
		else
			printf(REDHB "\\0" CRESET);
	}
	printf("\"\n");
	free(or);
	free(ft);
}

static void	test_strlcat(char *dst, const char *src, size_t f_dst_s)
{
	char	*ft;

	char * or = strdup(dst);
	ft = strdup(dst);
	printf(UCYN "\nTests for ft_strlcat:\n" CRESET);
	print_w_nul_nonprnt("src", (char *)src, ft_strlen(src) + ft_strlen(dst) + 1);
	strlcat(or, src, f_dst_s);
	print_w_nul_nonprnt("or", or, ft_strlen(src) + ft_strlen(dst) + 1);
	strlcat(ft, src, f_dst_s);
	print_w_nul_nonprnt("ft", ft, ft_strlen(src) + ft_strlen(dst) + 1);
	free(or);
	free(ft);
}

static void	test_to_upper_lower(int (*f)(int c), int c)
{
	if (f == ft_toupper)
		printf(UCYN "\nTests for ft_toupper:\n" CRESET);
	else if (f == ft_tolower)
		printf(UCYN "\nTests for ft_tolower:\n" CRESET);
	printf("c:     '%c'\n", c);
	if (f == ft_toupper)
		printf("or:    '%c'\n", toupper(c));
	else if (f == ft_tolower)
		printf("or:    '%c'\n", tolower(c));
	printf("ft:    '%c'\n", f(c));
	printf("\n" UCYN "TABLE:\n" CRESET);
	for (int i = (f == ft_toupper ? 'a' : 'A'),
				j = (f == ft_toupper ? 'z' : 'Z');
			i <= j;
			i++)
		printf("'%c' -> '%c'\n", i, f(i));
}

static void	test_strchr_strrchr(char *(*f)(const char *, int), const char *s,
		int c)
{
	if (f == ft_strchr)
		printf(UCYN "\nTests for ft_strchr:\n" CRESET);
	else if (f == ft_strrchr)
		printf(UCYN "\nTests for ft_strrchr:\n" CRESET);
	print_w_nul_nonprnt("str", (char *)s, ft_strlen(s) + 1);
	print_w_nul_nonprnt("or", strchr(s, c), ft_strlen(s) + 1);
	print_w_nul_nonprnt("ft", ft_strchr(s, c), ft_strlen(s) + 1);
}
