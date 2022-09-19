/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:29:28 by timartin          #+#    #+#             */
/*   Updated: 2022/04/21 18:16:31 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int	i;
	int	full_len;

	i = 0;
	full_len = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		full_len = 6;
		return (full_len);
	}
	while (str[i])
	{
		full_len += ft_printchar(str[i]);
		i++;
	}
	return (full_len);
}
