/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:31:05 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/21 01:34:17 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

//Helper function for test_memcpy_memmove
//that resets all given strings to "WATERMELONJUICE".
void	h_reset_memcpy_memmove(char ** or, char **ft)
{
#define TEST_STR "WATERMELONJUICE"
	* or = strcpy(malloc(16), TEST_STR);
	*ft = strcpy(malloc(16), TEST_STR);
}

void print_w_nul_nonprnt(char *title, char *s, size_t n)
{
	printf("%s:\t\"", title);
	for (size_t i = 0; i < n; i++)
	{
		if (isprint(s[i]))
			printf("%c", s[i]);
		else if (s[i] == '\0')
			printf(REDHB "\\0" CRESET);
		else
			printf(BLKHB "\\😈" CRESET);
	}
	printf("\"\n");
}
