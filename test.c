/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 03:40:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/17 03:45:30 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SUCCESS 0

struct node
{
	int 		n;
	struct node *next;
};

typedef struct node node;

int	main(int argc, char **argv)
{
	for (int i = 1; i <= 10; i++)
		printf("%d\n", i);
	
	printf("👋 Hello World!\n");

	return (SUCCESS);
}

void	do_nothing(void)
{
}
