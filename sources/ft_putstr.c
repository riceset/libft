/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:27:01 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/09 01:08:15 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		while (len > INT_MAX)
		{
			write(1, s, INT_MAX);
			s += INT_MAX;
			len -= INT_MAX;
		}
		write(1, s, len);
	}
}
