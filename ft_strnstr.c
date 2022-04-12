/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:09:47 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/12 12:04:34 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (substr[i] == '\0')
		return ((char *)str);
	while (str[i])
	{
		k = i;
		j = 0;
		if (str[i] == substr[0])
			while (substr[j] && j < len)
			{
				if (j + 1 == ft_strlen(substr))
					return ((char *)(str + i));
				k++;
				j++;
			}
		i++;
	}
	return (NULL);
}
