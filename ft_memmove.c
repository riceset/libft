/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:26:24 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/08 00:51:48 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
		return (dst);
	}
	if (dst > src)
		while (n > 0)
		{
			((unsigned char *) dst)[n - 1] = ((unsigned char *) src)[n - 1];
			n--;
		}
	return (dst);
}
