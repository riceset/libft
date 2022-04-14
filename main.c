/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:21:45 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/14 11:51:13 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	char *str = argv[1];
	
	/* ~~~~~~~~~~~~~~TESTS~~~~~~~~~~~~~~ */

	/* PART 1 */
	{
		/* chr_test(ft_isalnum, str[0]); */
		/* strlen_test(str); */
		/* memset_test(str, 'A', ft_strlen(str)); */
		/* bzero_test(str, ft_strlen(str)); */
		/* memcpy_test(str); */
		/* memmove_test(str); */
		/* strlcpy_test("a", "hello", -1); */
		/* strlcat_test(str, "AAAAA", 7); */
		/* strchr_test(strrchr, str, '5'); */
		/* memchr_test(str, '\0', strlen(str)); */
		/* strncmp_test("hi\0a", "hi\0b", 4); */
		/* memcmp_test("hi\0a", "hi\0b", 4); */
		/* strnstr_test("aaabcabcd", "cd", 8); */
		/* atoi_test(str); */
		/* calloc_test(SIZE_MAX / 2, 2); */
	}

	/* PART 2 */
	{
		/* substr_test("hello", 0, 999999999999999); */
		/* strtrim_test("abc", "abc"); */
		/* itoa_test(INT_MAX); */
		putnbr_fd_test(INT_MAX, 1);
	}

	/* BONUS */
	{

	}

	return (0);
}
