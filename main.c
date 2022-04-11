/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:21:45 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/11 04:00:18 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	str = malloc(6);
	strcpy(str, "Hello");
	
	/* !!!!!!!!!TESTS!!!!!!!!! */

	/* chr_test(ft_isalpha, 'a'); */
	/* strlen_test(str); */
	/* memset_test(str, 'A', ft_strlen(str)); */
	/* bzero_test(str, ft_strlen(str)); */
	/* memcpy_test(str); */
	/* memmove_test(str); */
	/* strlcpy_test(str, "AAAAA", 6); */
	/* strlcat_test(str, "AAAAA", 7); */

	free(str);
	return (0);
}
