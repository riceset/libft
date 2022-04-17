/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:16:58 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/16 00:53:15 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*tmp;
	char	*head;
	char	*tail;

	i = 0;

	head = (char *) s;
	while (s[i])
	{
		while (s[i] != c)
			i++;
		tmp = malloc(i + 1);
		if (!tmp)
			return (NULL);
	}
}
