/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:15:35 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/13 18:53:20 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_trimmed(char *dst, const char *src, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (set[j])
		{
			if (src[i] != set[j])
				dst[i] = src[i];
			j++;
		}
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	if (s1 && set)
	{
		res = malloc((ft_strlen(s1) + 1) * sizeof(char));
		if (res)
		{
			return (res);
		}
	}
	return (NULL);
}
