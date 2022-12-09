/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 06:22:58 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/09 01:32:34 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	check_characters(char *base, int base_digits)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < base_digits - 1)
	{
		j = i + 1;
		while (j < base_digits)
		{
			if (base[j] == base[i])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static t_bool	check_valid_base(char *base, int base_digits)
{
	int	i;

	i = 0;
	if (base_digits == 0 || base_digits == 1)
		return (FALSE);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (FALSE);
		else if (!(base[i] > ' ' && base[i] <= '~'))
			return (FALSE);
		i++;
	}
	if (check_characters(base, base_digits))
		return (TRUE);
	return (FALSE);
}

static int	a2i(char *str, char *base, int base_digits)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				res = res * base_digits + j;
			j++;
		}
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	valid_base;
	int	base_digits;
	int	n;

	base_digits = ft_strlen(base);
	valid_base = check_valid_base(base, base_digits);
	if (!valid_base)
		return (0);
	n = a2i(str, base, base_digits);
	return (n);
}
