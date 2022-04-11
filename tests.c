/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:44:21 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/11 00:08:48 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	chr_test(int (*smth)(int), int c)
{
	if (smth == ft_toupper || smth == ft_tolower)
		printf("input:\t%c\noutput:\t%c\n", c, smth(c));
	else
		printf("input:\t%c\noutput:\t%s\n", c, smth(c) ? "TRUE" : "FALSE");
	return ;
}

void	strlen_test(const char *s)
{
	printf("or:\t%zu\nft:\t%zu\n", strlen(s), ft_strlen(s));
	return ;
}

void	memset_test(char *b, int c, size_t len)
{
	char	*b2;

	b2 = malloc(ft_strlen(b) + 1);
	strcpy(b2, b);

	memset(b, c, len);
	ft_memset(b2, c, len);

	printf("or:\t%s\nft:\t%s\n", b, b2);

	free(b2);
	return ;
}

void	bzero_test(char *b, size_t len)
{
	char	*b2;

	b2 = malloc(ft_strlen(b) + 1);
	strcpy(b2, b);

	bzero(b, len);
	ft_bzero(b2, len);

	printf("or:\t%s\nft:\t%s\n", b, b2);

	free(b2);
	return ;
}

void	memcpy_test(const char *src)
{
	char	dup[ft_strlen(src) + 1];
	char	dup2[ft_strlen(src) + 1];

	//NULLの場合
	/* ft_memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */
	/* memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */

	ft_memcpy(dup, src, sizeof(char) * (ft_strlen(src) + 1));
	memcpy(dup2, src, sizeof(char) * (ft_strlen(src) + 1));
	printf("FT_MEMCPY:\noriginal:\t%s\nduplicated:\t%s\n", src, dup);
	printf("MEMCPY:\noriginal:\t%s\nduplicated:\t%s\n", src, dup);

	//Doubleの場合
	/* double	srcd[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; */
	/* double	destd[5]; */
	/* ft_memcpy(destd, srcd, sizeof(srcd)); */
	/* for (int i = 0; i < 5; i++) */
	/* 	printf("%d: %.1f\n", i, destd[i]); */
	return ;
}

void	memmove_test(void)
{
#define STR "WATERMELONJUICE"
	char	str[] = STR;
	char	aaa[] = STR;

	//dst < src
	printf("%s\n", str);
	memmove(str, str + 5, 10);
	printf("%s\n\n", str);
	printf("%s\n", aaa);
	ft_memmove(aaa, aaa + 5, 10);
	printf("%s\n", aaa);

	//dst > src
	/* printf("%s\n", str); */
	/* memmove(str + 10, str, 5); */
	/* printf("%s\n\n", str); */
	/* printf("%s\n", aaa); */
	/* ft_memmove(aaa + 10, aaa, 5); */
	/* printf("%s\n", aaa); */

	//src == dst
	/* printf("%s\n", str); */
	/* memmove(str, str, 5); */
	/* printf("%s\n\n", str); */
	/* printf("%s\n", aaa); */
	/* ft_memmove(aaa, aaa, 5); */
	/* printf("%s\n", aaa); */
	return ;
}

void	strlcpy_test(char *dst, const char *src, size_t cpysize)
{
	char	*dst2;

	dst2 = malloc(ft_strlen(dst) + 1);
	strcpy(dst2, dst);

	strlcpy(dst, src, cpysize);
	ft_strlcpy(dst2, src, cpysize);

	printf("or:\t%s\nft:\t%s\n", dst, dst2);

	return ;
}

void	strlcat_test(void)
{
	return ;
}

void	toupper_test(void)
{
	return ;
}

void	tolower_test(void)
{
	return ;
}

void	strchr_test(void)
{
	return ;
}

void	strrchr_test(void)
{
	return ;
}

void	strncmp_test(void)
{
	return ;
}

void	memchr_test(void)
{
	return ;
}

void	memcmp_test(void)
{
	return ;
}

void	strnstr_test(void)
{
	return ;
}

void	atoi_test(void)
{
	return ;
}
