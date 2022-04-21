/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:25:02 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/21 18:59:58 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "libft.h"
#include "tests.h"

int	main(void)
{
	// test_is(ft_isprint);
	// test_strlen("god");
	// test_memset("AAA", '5', 4);
	// test_bzero("hello world", 2);
	// test_memcpy_memmove(ft_memmove, "Hello", 6);
	// test_strlcpy("Hello", -1);
	// test_strlcat("Hello ", "World", 12);
	// test_strlcat(NULL, "World", 0);
	printf("%zu\n", ft_strlcat(NULL, "World", 0));
	// test_to_upper_lower(ft_tolower, 'C');
	// test_strchr_strrchr(ft_strchr, "hello\0ccc", '\0');
	// test_strncmp_memcmp((int (*)(const void *, const void *, size_t))ft_strncmp,
	// 					"Hel\0lo",
	// 					"Hel\0l0",
	// 					6);
	// test_memchr("Hello", '\0', 3);
	// test_strncmp_memcmp(ft_memcmp, "Hel\0lo", "Hel\0l0", 6);
	// test_strnstr("Hello World aaa", "World", 16);
	// test_atoi("+1");
	// test_atoi_inputs();
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
	print_w_nul_nonprnt("src", s, ft_strlen(s) + 1 > len ? ft_strlen(s)
			+ 1 : len);
	print_w_nul_nonprnt("or", (char *)memset(or_s, c, len), ft_strlen(s)
			+ 1 > len ? ft_strlen(s) + 1 : len);
	print_w_nul_nonprnt("ft", (char *)ft_memset(ft_s, c, len), ft_strlen(s)
			+ 1 > len ? ft_strlen(s) + 1 : len);
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
	print_w_nul_nonprnt("or", or_s, ft_strlen(b) + 1 > len ? ft_strlen(b)
			+ 1 : len);
	print_w_nul_nonprnt("ft", ft_s, ft_strlen(b) + 1 > len ? ft_strlen(b)
			+ 1 : len);
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
	print_w_nul_nonprnt("or", or_s, (ft_strlen(src) + 1 > n) ? ft_strlen(src)
			+ 1 : n);
	print_w_nul_nonprnt("ft", ft_s, (ft_strlen(src) + 1 > n) ? ft_strlen(src)
			+ 1 : n);
	printf("res:\t%s\n" CRESET, memcmp(or_s, ft_s, strlen((char *)src)
				+ 1) == 0 ? GRN "OK" : RED "KO");
	free(or_s);
	free(ft_s);
	printf("\n😎 " UCYN "memcpy/memmove comparison:\n" CRESET);
	char * or ;
	h_reset_memcpy_memmove(& or, &ft);
	printf(BHGRN "\nPATTERN 1 (dest < src):\n" CRESET);
	memcpy(or, or +5, 5);
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
	size_t	or_r;
	size_t	ft_r;

	printf(UCYN "\nTests for ft_strlcpy:\n" CRESET);
	print_w_nul_nonprnt("src", src, ft_strlen(src) + 1);
	char * or = malloc(ft_strlen(src) + 1);
	or_r = strlcpy(or, src, cpysize);
	print_w_nul_nonprnt("or", or, ft_strlen(src) + 1);
	ft = malloc(ft_strlen(src) + 1);
	ft_r = strlcpy(ft, src, cpysize);
	print_w_nul_nonprnt("ft", ft, ft_strlen(src) + 1);
	printf("or_r:\t(%zu)\n", or_r);
	printf("ft_r:\t(%zu)\n", ft_r);
	printf("res:\t%s\n" CRESET, or_r == ft_r ? GRN "OK" : RED "KO");
	free(or);
	free(ft);
}

static void	test_strlcat(char *dst, const char *src, size_t f_dst_s)
{
	char	*ft;
	size_t	or_r;
	size_t	ft_r;

	char * or = strdup(dst);
	ft = strdup(dst);
	printf(UCYN "\nTests for ft_strlcat:\n" CRESET);
	print_w_nul_nonprnt("src", (char *)src, ft_strlen(src) + ft_strlen(dst)
			+ 1);
	or_r = strlcat(or, src, f_dst_s);
	print_w_nul_nonprnt("or", or, ft_strlen(src) + ft_strlen(dst) + 1);
	ft_r = strlcat(ft, src, f_dst_s);
	print_w_nul_nonprnt("ft", ft, ft_strlen(src) + ft_strlen(dst) + 1);
	printf("or_r:\t(%zu)\n", or_r);
	printf("ft_r:\t(%zu)\n", ft_r);
	printf("res:\t%s\n" CRESET, or_r == ft_r ? GRN "OK" : RED "KO");
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
	printf("c:\t(%c)\n", c);
	print_w_nul_nonprnt("str", (char *)s, ft_strlen(s) + 1);
	print_w_nul_nonprnt("or", f(s, c), ft_strlen(s) + 1);
	print_w_nul_nonprnt("ft", f(s, c), ft_strlen(s) + 1);
	printf("res:\t%s\n" CRESET, strcmp(!strchr(s, c) ? "NULL" : strchr(s, c),
				!ft_strchr(s, c) ? "NULL" : ft_strchr(s,
					c)) == 0 ? GRN "OK" : RED "KO");
}

static void	test_strncmp_memcmp(int (*f)(const void *, const void *, size_t),
								const char *s1,
								const char *s2,
								size_t n)
{
	if (f == (int (*)(const void *, const void *, size_t))ft_strncmp)
		printf(UCYN "\nTests for ft_strncmp:\n" CRESET);
	else if (f == ft_memcmp)
		printf(UCYN "\nTests for ft_memcmp:\n" CRESET);
	printf("n:\t(%zu)\n", n);
	print_w_nul_nonprnt("s1", (char *)s1, ft_strlen(s1) + 1 > n ? ft_strlen(s1)
			+ 1 : n);
	print_w_nul_nonprnt("s2", (char *)s2, ft_strlen(s2) + 1 > n ? ft_strlen(s2)
			+ 1 : n);
	if (f == (int (*)(const void *, const void *, size_t))ft_strncmp)
		printf("or:\t%d\n", strncmp(s1, s2, n));
	else if (f == ft_memcmp)
		printf("or:\t%d\n", memcmp(s1, s2, n));
	printf("ft:\t%d\n", f(s1, s2, n));
	printf("res:\t%s\n" CRESET, strncmp(s1, s2, n) == ft_strncmp(s1, s2,
				n) ? GRN "OK" : RED "KO");
}

static void	test_memchr(const void *s, int c, size_t n)
{
	printf(UCYN "\nTests for ft_memchr:\n" CRESET);
	printf("c:\t(%c)\n", c);
	print_w_nul_nonprnt("str", (char *)s, ft_strlen(s) + 1);
	print_w_nul_nonprnt("or", (char *)memchr(s, c, n), ft_strlen(s) + 1);
	print_w_nul_nonprnt("ft", (char *)ft_memchr(s, c, n), ft_strlen(s) + 1);
	printf("res:\t%s\n" CRESET, strcmp(!memchr(s, c, n) ? "NULL" : memchr(s, c,
					n), !ft_memchr(s, c, n) ? "NULL" : ft_memchr(s, c,
					n)) == 0 ? GRN "OK" : RED "KO");
}

static void	test_strnstr(const char *str, const char *substr, size_t len)
{
	printf(UCYN "\nTests for ft_memchr:\n" CRESET);
	print_w_nul_nonprnt("str", (char *)str, ft_strlen(str) + 1);
	print_w_nul_nonprnt("substr", (char *)substr, ft_strlen(substr) + 1);
	print_w_nul_nonprnt("or", strnstr(str, substr, len), ft_strlen(str)
			+ 1 > len ? ft_strlen(str) + 1 : len);
	print_w_nul_nonprnt("ft", ft_strnstr(str, substr, len), ft_strlen(str)
			+ 1 > len ? ft_strlen(str) + 1 : len);
	printf("res:\t%s\n" CRESET, strcmp(strnstr(str, substr, len),
				ft_strnstr(str, substr, len)) == 0 ? GRN "OK" : RED "KO");
}

static void	test_atoi(const char *str)
{
	printf(UCYN "\nTests for ft_atoi:\n" CRESET);
	print_w_nul_nonprnt("str", (char *)str, ft_strlen(str) + 1);
	printf("or:\t%d\n", atoi(str));
	printf("ft:\t%d\n", ft_atoi(str));
	printf("res:\t%s\n" CRESET,
			atoi(str) == ft_atoi(str) ? GRN "OK" : RED "KO");
}

static void	test_atoi_inputs()
{
	char *strs[] = {
		"9223372036854775805",
		"9223372036854775806",
		"9223372036854775807",
		"9223372036854775808",
		"9223372036854775809",
		"18446744073709551613",
		"18446744073709551614",
		"18446744073709551615",
		"18446744073709551616",
		"18446744073709551617",
		"-9223372036854775805",
		"-9223372036854775806",
		"-9223372036854775807",
		"-9223372036854775808",
		"-9223372036854775809",
		"-18446744073709551613",
		"-18446744073709551614",
		"-18446744073709551615",
		"-18446744073709551616",
		"-18446744073709551617",
	};

	for (int i = 0; i < 20; i++)
		test_atoi(strs[i]);
}
