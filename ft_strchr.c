/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:05:12 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/11 14:04:23 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;
	char	c2;

	t = (char *) s;
	c2 = (char) c;
	if (c2 == '\0')
	{
		while (*t)
			t++;
		return (t);
	}
	while (*t)
	{
		if (*t == c2)
			return (t);
		t++;
	}
	return (NULL);
}
