/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 05:46:16 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/09 01:19:42 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*loop(char *str, char *to_find, int i, int j)
{
	int	k;

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			k = i;
			j = 0;
			while (to_find[j] != '\0')
			{
				if (str[k] != to_find[j])
					break ;
				if (j + 1 == (int)ft_strlen(to_find))
					return (&str[i]);
				k++;
				j++;
			}
		}
		i++;
	}
	return ((char *)0x0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strcmp(to_find, "") == 0)
		return (str);
	return (loop(str, to_find, i, j));
}
