/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:06:07 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/23 14:14:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	char	*head;

	c2 = (char)c;
	head = (char *)s;
	while (*s)
		s++;
	if (c == '\0')
	{
		while (*s)
			s--;
		return ((char *)s);
	}
	while (s >= head)
	{
		if (*s == c2)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
