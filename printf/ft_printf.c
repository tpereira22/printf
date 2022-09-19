/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:58:36 by timartin          #+#    #+#             */
/*   Updated: 2022/04/26 16:08:52 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(const char type, va_list args)
{
	int	full_len;

	full_len = 0;
	if (type == 'c')
		full_len += ft_printchar(va_arg(args, int));
	else if (type == 's')
		full_len += ft_printstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		full_len += ft_printnum(va_arg(args, int), full_len);
	else if (type == 'u')
		full_len += ft_printunsigned(va_arg(args, unsigned int));
	else if (type == 'p')
		full_len += ft_printptr(va_arg(args, unsigned long));
	else if (type == 'x' || type == 'X')
		full_len += ft_printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		full_len += ft_printchar(37);
	return (full_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		full_len;
	va_list	args;

	va_start(args, str);
	i = 0;
	full_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			full_len += ft_sort(str[i + 1], args);
			i++;
		}
		else
			full_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (full_len);
}
