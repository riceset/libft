/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:55:04 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/13 15:35:24 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a substringfrom the string ’s’.
 * The substring begins at index ’start’ and is ofmaximum size ’len’. */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sb;

	i = 0;
	if (s)
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		sb = malloc((len + 1) * sizeof(char));
		if (sb)
		{
			if (start <= ft_strlen(s))
				while (s[start] && i < len)
					sb[i++] = s[start++];
			sb[i] = '\0';
			return (sb);
		}
	}
	return (NULL);
}