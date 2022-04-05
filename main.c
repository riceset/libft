/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:21:45 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/05 05:36:32 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	/* memset */
	/* char	str[] = "Hello World!"; */

	/* ft_memset(str, '0', ft_strlen(str)); */

	/* printf("%s\n", str); */

	/* bzero */
	char	str[] = "Hi";

	printf("%s\n", str);

	ft_bzero(str, 2);

	printf("%d\n", str[0]);
}
