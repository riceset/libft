/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:05:12 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/22 19:03:55 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*trav;

	trav = (char *)s;
	if ((char)c == '\0')
	{
		while (*trav)
			trav++;
		return (trav);
	}
	while (*trav)
	{
		if (*trav == (char)c)
			return (trav);
		trav++;
	}
	return (NULL);
}
