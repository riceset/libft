/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:31:47 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/09 01:33:45 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int	i;
	int	*numbers;

	if (min >= max)
		return (NULL);
	numbers = malloc(sizeof(int) * (max - min));
	if (!numbers)
		return (NULL);
	i = 0;
	while (min < max)
		numbers[i++] = min++;
	return (numbers);
}
