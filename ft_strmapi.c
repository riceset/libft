/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:21:06 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/13 19:50:55 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (s)
	{
		res = ft_calloc((ft_strlen(s) + 1), sizeof(char));
		if (res)
		{
			i = 0;
			while(s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
			return (res);
		}
	}
	return (NULL);
}
