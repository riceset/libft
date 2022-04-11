/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:20:12 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/11 04:35:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	chr_test(int (*smth)(int), int c);

size_t	ft_strlen(const char *s);
void	strlen_test(const char *s);

void	*ft_memset(void *b, int c, size_t len);
void	memset_test(char *b, int c, size_t len);

void	ft_bzero(void *b, size_t len);
void	bzero_test(char *b, size_t len);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	memcpy_test(const char *src);

void	*ft_memmove(void *dest, const void *src, size_t n);
void	memmove_test(const char *src);

size_t	ft_strlcpy(char *dst, const char *src, size_t cpysize);
void	strlcpy_test(char *dst, const char *src, size_t cpysize);

size_t	ft_strlcat(char *dst, const char *src, size_t f_dst_s);
void	strlcat_test(char *dst, const char *src, size_t f_dst_s);

char	*ft_strchr(const char *s, int c);

/* char	*ft_strrchr(const char *s, int c); */
/* int		ft_strncmp(const char *s1, const char *s2, size_t n); */
/* void	*ft_memchr(const void *s, int c, size_t n); */
/* int		ft_memcmp(const void *s1, const void *s2, size_t n); */
/* char	*ft_strnstr(const char *haystack, const char *needle, size_t len); */
/* void	*ft_calloc(size_t count, size_t size); */
/* char	*ft_strdup(const char *s1); */
/* void	strchr_test(void); */
/* void	strrchr_test(void); */
/* void	strncmp_test(void); */
/* void	memchr_test(void); */
/* void	memcmp_test(void); */
/* void	strnstr_test(void); */
/* void	atoi_test(void); */

#endif
