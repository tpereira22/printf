/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:28:26 by timartin          #+#    #+#             */
/*   Updated: 2022/04/26 16:11:40 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(unsigned int num)
{
	int		len;
	char	*numstr;

	len = ft_len(num);
	numstr = (char *)malloc(sizeof(char) + (len + 1));
	if (!numstr)
		return (NULL);
	numstr[len] = '\0';
	while (num != 0)
	{
		numstr[len - 1] = num % 10 + 48;
		num = num / 10;
		len--;
	}
	return (numstr);
}

int	ft_printunsigned(unsigned int num)
{
	int		full_len;
	char	*numstr;

	full_len = 0;
	if (num == 0)
		full_len += ft_printchar('0');
	else
	{
		numstr = ft_itoa(num);
		full_len += ft_printstr(numstr);
		free(numstr);
	}
	return (full_len);
}
