/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:06:07 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/11 14:10:06 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//go backwards

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	char	*head;
	char	*trav;

	c2 = (char) c;
	head = (char *) s;
	trav = head;
	while (*trav)
		trav++;
	while (trav >= head)
	{
		if (*trav == c2)
			return (trav);
		trav--;
	}
	return (NULL);
}
