/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:05:12 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/11 04:47:41 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* s, 't' + 256 */

char	*ft_strchr(const char *s, int c)
{
	char	*t;
	char	d;

	t = (char *) s;
	d = (char) c;
	if (d == '\0')
	{
		while (*t)
			t++;
		return (t);
	}
	while (*t)
	{
		if (*t == d)
			return (t);
		t++;
	}
	return (NULL);
}
