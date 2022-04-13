/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:31:13 by tkomeno           #+#    #+#             */
/*   Updated: 2022/04/13 15:45:04 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isalpha() function tests for any character for which isupper(3) or
 * islower(3) is true.  The value of the argument must be representable as
 * an unsigned char or the value of EOF. */
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
