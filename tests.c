/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:44:21 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/11 02:42:07 by tkomeno          ###   ########.fr       */
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

/* void	memcpy_test(const char *src) */
/* { */
/* 	char	dst[ft_strlen(src) + 1]; */
/* 	char	dst2[ft_strlen(src) + 1]; */

/* 	//NULLの場合 */
/* 	ft_memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */
/* 	memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */

/* 	/1* ft_memcpy(dst, src, sizeof(char) * (ft_strlen(src) + 1)); *1/ */
/* 	/1* memcpy(dst2, src, sizeof(char) * (ft_strlen(src) + 1)); *1/ */
/* 	printf("FT_MEMCPY:\noriginal:\t%s\ndstlicated:\t%s\n", src, dst); */
/* 	printf("MEMCPY:\noriginal:\t%s\ndstlicated:\t%s\n", src, dst2); */

/* 	//Doubleの場合 */
/* 	/1* double	srcd[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; *1/ */
/* 	/1* double	destd[5]; *1/ */
/* 	/1* ft_memcpy(destd, srcd, sizeof(srcd)); *1/ */
/* 	/1* for (int i = 0; i < 5; i++) *1/ */
/* 	/1* 	printf("%d: %.1f\n", i, destd[i]); *1/ */
/* 	return ; */
/* } */

void	memcpy_test(const char *src)
{
	char	*dst;
	char	*dst2;

	dst = malloc(ft_strlen(src) + 1);
	dst2 = malloc(ft_strlen(src) + 1);

	printf("SRC:\t%s\n", src);

	//NULLの場合
	/* ft_memcpy(NULL, "42", sizeof(char) * (ft_strlen(src) + 1)); */
	memcpy(NULL, "42", sizeof(char) * (ft_strlen(src) + 1));

	/* ft_memcpy(dst, src, sizeof(char) * (ft_strlen(src) + 1)); */
	/* memcpy(dst2, src, sizeof(char) * (ft_strlen(src) + 1)); */

	printf("ORG:\t%s\nFT_:\t%s\nRES:\t%s\n", dst, dst2, (strcmp(dst, dst2) == 0) ? "(✅)" : "(❌)");


	/* その他 */

	//Doubleの場合
	/* double	srcd[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; */
	/* double	destd[5]; */
	/* ft_memcpy(destd, srcd, sizeof(srcd)); */
	/* for (int i = 0; i < 5; i++) */
	/* 	printf("%d: %.1f\n", i, destd[i]); */

	return ;
}

void	memmove_test(const char *src)
{
	char	*dst;
	char	*dst2;

	dst = malloc(ft_strlen(src) + 1);
	dst2 = malloc(ft_strlen(src) + 1);

	strcpy(dst, src);
	strcpy(dst2, src);

	printf("SRC:\t%s\n", src);

	//dst < src
	memmove(dst, dst + 5, 10);
	ft_memmove(dst2, dst2 + 5, 10);

	//dst > src
	/* memmove(dst + 10, dst, 5); */
	/* ft_memmove(dst2 + 10, dst2, 5); */

	//src == dst
	/* memmove(dst, dst, 5); */
	/* ft_memmove(dst2, dst2, 5); */

	printf("ORG:\t%s\nFT_:\t%s\nRES:\t%s\n", dst, dst2, (strcmp(dst, dst2) == 0) ? "(✅)" : "(❌)");

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

void	strlcat_test(char *dst, const char *src, size_t f_dst_s)
{
	char	*dst2;
	size_t	out;
	size_t	out2;

	dst2 = malloc(ft_strlen(dst) + 1);
	strcpy(dst2, dst);

	out = strlcat(dst, src, f_dst_s);
	out2 = ft_strlcat(dst2, src, f_dst_s);

	printf("or:\t%s\no1:\t%zu\nft:\t%s\no2\t%zu\n", dst, out, dst2, out2);
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
