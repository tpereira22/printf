/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:19:18 by timartin          #+#    #+#             */
/*   Updated: 2022/04/26 16:12:03 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long p1)
{
	int	len;

	len = 0;
	while (p1 != 0)
	{
		len++;
		p1 = p1 / 16;
	}
	return (len);
}

void	ft_putptr(unsigned long p1)
{
	if (p1 >= 16)
	{
		ft_putptr(p1 / 16);
		ft_putptr(p1 % 16);
	}
	else
	{
		if (p1 <= 9)
			ft_printchar(p1 + 48);
		else
			ft_printchar(p1 - 10 + 'a');
	}
}

int	ft_printptr(unsigned long p1)
{
	int		full_len;

	full_len = 0;
	full_len += ft_printchar('0');
	full_len += ft_printchar('x');
	if (p1 == 0)
		full_len += ft_printchar('0');
	else
	{
		ft_putptr(p1);
		full_len += ft_ptrlen(p1);
	}
	return (full_len);
}
