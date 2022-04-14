/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:21:45 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/14 16:39:46 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		switch (decide(argv[1]))
		{
			case (o_isalpha):
				chr_test(ft_isalpha, argv[2][0]);
				break;
			case (o_isdigit):
				chr_test(ft_isdigit, argv[2][0]);
				break;
			case (o_isalnum):
				chr_test(ft_isalnum, argv[2][0]);
				break;
			case (o_isascii):
				chr_test(ft_isascii, argv[2][0]);
				break;
			case (o_isprint):
				chr_test(ft_isprint, argv[2][0]);
				break;
			case (o_strlen):
				strlen_test(argv[2]);
				break;
			case (o_memset):
				memset_test(argv[2], argv[3][0], ft_strlen(argv[2]));
				break;
			case (o_bzero):
				bzero_test(argv[2], ft_strlen(argv[2]));
				break;
			case (o_memcpy):
				memcpy_test(argv[2]);
				break;
			case (o_memmove):
				memmove_test(argv[2]);
				break;
			case (o_strlcpy):
				strlcpy_test(argv[2], argv[3], atoi(argv[4]));
				break;
			case (o_strlcat):
				strlcat_test(argv[2], argv[3], atoi(argv[4]));
				break;
			case (o_strchr):
				strchr_test(strchr, argv[2], argv[3][0]);
				break;
			case (o_strrchr):
				strchr_test(strrchr, argv[2], argv[3][0]);
				break;
			case (o_memchr):
				memchr_test(argv[2], argv[3][0], strlen(argv[2]));
				break;
			case (o_strncmp):
				strncmp_test(argv[2], argv[3], atoi(argv[4]));
				break;
			case (o_memcmp):
				memcmp_test(argv[2], argv[3], atoi(argv[4]));
				break;
			case (o_strnstr):
				strnstr_test(argv[2], argv[3], atoi(argv[4]));
				break;
			case (o_atoi):
				atoi_test(argv[2]);
				break;
			case (o_calloc):
				calloc_test(atoi(argv[2]), atoi(argv[3]));
				break;
			case (o_substr):
				substr_test(argv[2], atoi(argv[3]), atoi(argv[4]));
				break;
			case (o_strjoin):
				strjoin_test(argv[2], argv[3]);
				break;
			case (o_strtrim):
				strtrim_test(argv[2], argv[3]);
				break;
			case (o_split):
				split_test(argv[2], argv[3][0]);
				break;
			case (o_itoa):
				itoa_test(atoi(argv[2]));
				break;
			case (o_strmapi):
				/* strmapi_test("", f); */
				break;
			case (o_putchar_fd):
				putchar_fd_test(argv[2][0], 1);
				break;
			case (o_putstr_fd):
				putstr_fd_test(argv[2], 1);
				break;
			case (o_putendl_fd):
				ft_putendl_fd(argv[2], 1);
				break;
			case (o_putnbr_fd):
				putnbr_fd_test(atoi(argv[2]), 1);
				break;
			default:
				break;
		}
	}
	return (0);
}
