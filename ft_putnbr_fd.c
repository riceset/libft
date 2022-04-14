/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:29:22 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/14 12:00:14 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digits(int n)
{
	int	digits;

	digits = 0;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

void	prnt(int num, int digits, char numbers[], int fd)
{
	int	i;

	i = 0;
	if (num == 0)
		ft_putchar_fd('0', fd);
	else if (num < 0)
	{
		ft_putchar_fd('-', fd);
		while (i < digits)
		{
			ft_putchar_fd(numbers[i], fd);
			i++;
		}
	}
	else
	{
		while (i < digits)
		{
			ft_putchar_fd(numbers[i], fd);
			i++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		tmp;
	int		digits;
	char	numbers[10];

	i = 0;
	tmp = n;
	digits = get_digits(n);
	if (tmp == -2147483648)
		tmp += 1;
	if (tmp < 0)
		tmp *= -1;
	while (i < digits)
	{
		numbers[digits - i - 1] = (tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	if (n == -2147483648)
		numbers[9] = '8';
	prnt(n, digits, numbers, fd);
}
