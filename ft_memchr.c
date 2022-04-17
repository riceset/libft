/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:07:49 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/15 23:44:39 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*trav;
	size_t	i;

	trav = (char *) s;
	i = 0;
	while (i < n)
	{
		if (*trav == (unsigned char) c)
			return (trav);
		trav++;
		i++;
	}
	return (NULL);
}
