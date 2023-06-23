/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:26:58 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/23 18:01:43 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_varstrjoin(int count, ...)
{
	int i;
	char *tmp;
	char *result;
	char *current;
	va_list args;

	va_start(args, count);
	i = -1;
	result = NULL;
	while (++i < count)
	{
		current = va_arg(args, char *);
		if (result == NULL)
			result = ft_strdup(current);
		else
		{
			tmp = result;
			result = ft_strjoin(tmp, current);
			free(tmp);
			if (!result)
				break ;
		}
	}
	va_end(args);
	return (result);
}
