/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:15:35 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/13 23:42:26 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (s1 && set)
	{
		res = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
		if (res)
		{
			i = 0;
			k = i;
			while (s1[i])
			{
				j = 0;
				while (set[j])
				{
					if (s1[k] == set[j])
					{
						j = 0;
						k++;
					}
					else
						j++;
				}
				res[i] = s1[k];
				k++;
				i++;
			}
			return (res);
		}
	}
	return (NULL);
}
