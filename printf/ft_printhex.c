/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:19:57 by timartin          #+#    #+#             */
/*   Updated: 2022/04/26 16:12:19 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

int	ft_printhex(unsigned int num, char type)
{
	int			full_len;
	char const	*basex;
	char const	*base_x;

	basex = "0123456789abcdef";
	base_x = "0123456789ABCDEF";
	full_len = ft_hexlen(num);
	if (num >= 16)
	{
		ft_printhex(num / 16, type);
		ft_printhex(num % 16, type);
	}
	else
	{
		if (type == 'x')
			ft_printchar(basex[num]);
		else if (type == 'X')
			ft_printchar(base_x[num]);
	}
	return (full_len);
}
