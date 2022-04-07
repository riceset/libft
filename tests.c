/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:44:21 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/06 13:10:30 by tkomeno          ###   ########.fr       */
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

void	memset_test(void)
{
	return ;
}

void	bzero_test(void)
{
	return ;
}

void	memcpy_test(const char *src)
{
	char	dup[ft_strlen(src) + 1];
	char	dup2[ft_strlen(src) + 1];

	/* ft_memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */
	/* memcpy(NULL, NULL, sizeof(char) * (ft_strlen(src) + 1)); */
	ft_memcpy(dup, src, sizeof(char) * (ft_strlen(src) + 1));
	memcpy(dup2, src, sizeof(char) * (ft_strlen(src) + 1));

	printf("FT_MEMCPY:\noriginal:\t%s\nduplicated:\t%s\n", src, dup);
	printf("MEMCPY:\noriginal:\t%s\nduplicated:\t%s\n", src, dup);
	return ;
}

void	memmove_test(void)
{
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
