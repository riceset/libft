/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:26:24 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/19 21:04:11 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst < src)
	{
		i = -1;
		while (++i < n)
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
	}
	if (dst > src)
	{
		i = n + 1;
		while (--i > 0)
			((unsigned char *) dst)[i - 1] = ((unsigned char *) src)[i - 1];
	}
	return (dst);
}
