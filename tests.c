/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:44:21 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/08 01:30:38 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

//isalpha, isdigit, isalnum, isascii, isprint
void	issmth_test(int (*smth)(int), int c)
{
	printf("'%c' %s\n", c, smth(c) ? "Y" : "N");
}

void	strlen_test(const char *s)
{
	printf("size: %lu\n", ft_strlen(s));
	return ;
}

void	memset_test(char *b, int c, size_t len)
{
	ft_memset(b, c, len);
	printf("%s\n", b);
	return ;
}

void	bzero_test(char *s, size_t n)
{
	ft_bzero(s, n);
	printf("%s\n", s);
	return ;
}

struct	s_person
{
	char	*name;
	int		age;
};

typedef struct s_person	t_person;

void	memcpy_test(const char *src)
{
	char	dup[ft_strlen(src) + 1];
	char	dup2[ft_strlen(src) + 1];

	/* ft_memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */
	/* memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */

	ft_memcpy(dup, src, sizeof(char) * (ft_strlen(src) + 1));
	memcpy(dup2, src, sizeof(char) * (ft_strlen(src) + 1));

	printf("FT_MEMCPY:\noriginal:\t%s\nduplicated:\t%s\n", src, dup);
	printf("MEMCPY:\noriginal:\t%s\nduplicated:\t%s\n\n", src, dup);

	double	srcd[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double	destd[5];

	ft_memcpy(destd, srcd, sizeof(srcd));

	for (int i = 0; i < 5; i++)
		printf("%d: %.1f\n", i, destd[i]);

	t_person	j;
	t_person	k;

	strcpy(j.name, "aaa");
	j.age = 42;

	ft_memcpy(&k, &j, sizeof(t_person));
	printf("\n%s is %d years old.", k.name, k.age);
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

void	strlcpy_test(void)
{
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
