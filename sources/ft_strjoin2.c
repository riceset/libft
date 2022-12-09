/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:13:10 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/09 01:36:23 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(char **strs, char *sep, char *res, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			res[k++] = strs[i][j++];
		j = 0;
		if (i != size - 1)
			while (sep[j])
				res[k++] = sep[j++];
		i++;
	}
	res[k] = '\0';
}

static int	ft_size(int size, char **strs, char *sep)
{
	int	res_size;
	int	i;

	res_size = 0;
	i = 0;
	while (i < size)
	{
		res_size += ft_strlen(strs[i]);
		i++;
	}
	res_size += ft_strlen(sep) * (size - 1);
	return (res_size);
}

char	*ft_strjoin2(int size, char **strs, char *sep)
{
	char	*res;
	int		res_size;

	if (size == 0)
	{
		res = malloc(sizeof(char) * 1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res_size = ft_size(size, strs, sep);
	res = malloc(sizeof(char) * (res_size + 1));
	if (res == NULL)
		return (NULL);
	ft_copy(strs, sep, res, size);
	return (res);
}
