/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:15:35 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/14 12:22:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_res_size(char *s1, char *set, char **head, char **tail)
{
	char	*trav;
	char	len;

	trav = set;
	len = ft_strlen(s1);
	*head = s1;
	*tail = s1 + (len - 1);
	while (*trav)
	{
		while (**head == *trav)
		{
			trav = set;
			len--;
			(*head)++;
		}
		while (**tail == *trav)
		{
			trav = set;
			len--;
			(*tail)--;
		}
		trav++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*trav;
	char	*head;
	char	*tail;
	int		res_size;

	if (s1 && set)
	{
		res_size = ft_res_size((char *) s1, (char *) set, &head, &tail);
		if (res_size < 0)
			res_size = 0;
		res = ft_calloc((res_size + 1), sizeof(char));
		if (res)
		{
			trav = res;
			while (head <= tail)
				*trav++ = *head++;
			return (res);
		}
	}
	return (NULL);
}
