/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:25:48 by timartin          #+#    #+#             */
/*   Updated: 2022/04/25 15:02:05 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int num)
{
	int	len;

	if (num == INT_MIN)
		return (0);
	len = 1;
	if (num < 0)
		num = -num;
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_printnum(int num, int full_len)
{
	if (full_len == 0)
		full_len = ft_numlen(num);
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		full_len = 11;
		return (full_len);
	}
	else if (num < 0)
	{
		full_len += ft_printchar('-');
		num = -num;
		ft_printnum(num, full_len);
	}
	else if (num >= 10)
	{
		ft_printnum(num / 10, full_len);
		ft_printnum(num % 10, full_len);
	}
	else if (num < 10)
		ft_printchar(num + 48);
	return (full_len);
}
