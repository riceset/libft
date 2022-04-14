/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:29:22 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/14 11:57:56 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_find_divisor(int n)
{
	int	i;
	int	div;
	int	digits;

	i = 0;
	div = 1;
	digits = 1;
	while (n /= 10)
		digits++;
	while (i < digits)
	{
		div *= 10;
		i++;
	}
	return (div);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;
	int		divisor;
	char	c;

	ln = (long long) n;
	divisor = ft_find_divisor(ln);
	while (ln %= divisor)
	{
		divisor /= 10;
		c = ln / divisor + '0';
		ft_putchar_fd(c, fd);
	}
	return ;
}
