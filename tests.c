/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:44:21 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/12 21:44:37 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

void	chr_test(int (*smth)(int), int c)
{
	printf("⚡️ chr:\n");

	if (smth == ft_toupper || smth == ft_tolower)
		printf("input:\t%c\noutput:\t%c\n", c, smth(c));
	else
		printf("input:\t%c\noutput:\t%s\n", c, smth(c) ? "TRUE" : "FALSE");
	return ;
}

void	strlen_test(const char *s)
{
	printf("⚡️ strlen:\n");

	printf("or:\t%zu\nft:\t%zu\n", strlen(s), ft_strlen(s));
	return ;
}

void	memset_test(char *b, int c, size_t len)
{
	printf("⚡️ memset:\n");
	char	*b2 = ft_strdup(b);

	memset(b, c, len);
	ft_memset(b2, c, len);

	printf("or:\t%s\nft:\t%s\n", b, b2);

	free(b2);
	return ;
}

void	bzero_test(char *b, size_t len)
{
	printf("⚡️ bzero:\n");

	char	*b2 = ft_strdup(b);

	bzero(b, len);
	ft_bzero(b2, len);

	printf("or:\t%s\nft:\t%s\n", b, b2);

	free(b2);
	return ;
}

void	memcpy_test(const char *src)
{
	printf("⚡️ memcpy:\n");

	char	*dst = ft_strdup(src);
	char	*dst2 = ft_strdup(src);

	printf("SRC:\t%s\n", src);

	//NULLの場合
	/* ft_memcpy(NULL, "42", sizeof(char) * (ft_strlen(src) + 1)); */
	/* memcpy(NULL, "42", sizeof(char) * (ft_strlen(src) + 1)); */

	ft_memcpy(dst, src, sizeof(char) * (ft_strlen(src) + 1));
	memcpy(dst2, src, sizeof(char) * (ft_strlen(src) + 1));

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
	printf("⚡️ memmove:\n");

	char	*dst = ft_strdup(src);
	char	*dst2 = ft_strdup(src);

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

	free(dst);
	free(dst2);
	return ;
}

void	strlcpy_test(char *dst, const char *src, size_t cpysize)
{
	printf("⚡️ strlcpy:\n");

	char	*dst2 = ft_strdup(dst);

	strlcpy(dst, src, cpysize);
	ft_strlcpy(dst2, src, cpysize);

	printf("or:\t%s\nft:\t%s\n", dst, dst2);

	free(dst2);
	return ;
}

void	strlcat_test(char *dst, const char *src, size_t f_dst_s)
{
	printf("⚡️ strlcat:\n");

	char	*dst2 = ft_strdup(dst);
	size_t	out;
	size_t	out2;

	out = strlcat(dst, src, f_dst_s);
	out2 = ft_strlcat(dst2, src, f_dst_s);

	printf("or:\t%s\no1:\t%zu\nft:\t%s\no2\t%zu\n", dst, out, dst2, out2);
	
	free(dst2);
	return ;
}

void	strchr_test(char *(*f)(const char *s, int c), const char *s, int c)
{
	printf("⚡️ strchr:\n");

	char	*rt1;
	char	*rt2;

	if (f == strchr)
	{
		rt1 = strchr(s, c);
		rt2 = ft_strchr(s, c);
	}
	else if (f == strrchr)
	{
		rt1 = strrchr(s, c);
		rt2 = ft_strrchr(s, c);
	}
	else
		return ;
	printf("RT1:\t\"%p\" | \"%s\"\nRT2:\t\"%p\" | \"%s\"\nRES:\t%s\n", rt1, rt1, rt2, rt2, rt1 == rt2 ? "アドレスが一致します (✅)" : "アドレスが一致しません (❌)");
	return ;
}

void	strncmp_test(const char *s1, const char *s2, size_t n)
{
	printf("⚡️ strncmp:\n");
	
	int	o1 = strncmp(s1, s2, n);
	int	o2 = ft_strncmp(s1, s2, n);
	printf("or:\t%d\nft:\t%d\n", o1, o2);
	return ;
}

void	memchr_test(const void *s, int c, size_t n)
{
	printf("⚡️ memchr:\n");

	void	*rt1;
	void	*rt2;

	rt1 = memchr(s, c, n);
	rt2 = ft_memchr(s, c, n);

	printf("RT1:\t\"%p\"\nRT2:\t\"%p\"\nRES:\t%s\n", rt1, rt2, rt1 == rt2 ? "アドレスが一致します (✅)" : "アドレスが一致しません (❌)");
	return ;
}

void	memcmp_test(const void *v1, const void *v2, size_t n)
{
	printf("⚡️ memcmp:\n");

	int	o1 = memcmp(v1, v2, n);
	int	o2 = ft_memcmp(v1, v2, n);
	printf("or:\t%d\nft:\t%d\n", o1, o2);
	return ;
}

void	strnstr_test(const char *str, const char *substr, size_t len)
{
	printf("⚡️ strnstr:\n");

	char	*o1 = strnstr(str, substr, len);
	char	*o2 = ft_strnstr(str, substr, len);

	printf("or:\t%s\nft:\t%s\n", o1, o2);
	return ;
}

void	atoi_test(const char *str)
{
	char	*str2 = ft_strdup(str);
	int	o1 = atoi(str);
	int	o2 = ft_atoi(str2);

	printf("or:\t%d\nft:\t%d\n", o1, o2);

	free(str2);
	return ;
}
