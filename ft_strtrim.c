/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:15:35 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/14 09:32:44 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*g_head;
static char	*g_tail;

int	ft_res_size(char *s1, char *set, int len)
{
	char	*trav;

	g_head = s1;
	g_tail = s1 + (len - 1);
	trav = set;
	while (*trav)
	{
		while (*g_head == *trav)
		{
			trav = set;
			len--;
			g_head++;
		}
		while (*g_tail == *trav)
		{
			trav = set;
			len--;
			g_tail--;
		}
		trav++;
	}
	if (len < 0)
		len = 0;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*trav;
	int		res_size;

	if (s1 && set)
	{
		res_size = ft_res_size((char *) s1, (char *) set, ft_strlen(s1));
		res = ft_calloc((res_size + 1), sizeof(char));
		if (res)
		{
			trav = res;
			while (g_head <= g_tail)
				*trav++ = *g_head++;
			return (res);
		}
	}
	return (NULL);
}
