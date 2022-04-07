/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:26:24 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/06 12:54:17 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, t_size n)
{
	t_size			i;
	unsigned char	*buf;

	i = 0;
	buf = malloc(n);
	while (i < n)
	{
		buf[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (buf);
}
