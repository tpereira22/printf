/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:37:16 by timartin          #+#    #+#             */
/*   Updated: 2022/04/26 16:13:18 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);

int		ft_sort(const char type, va_list args);

int		ft_printptr(unsigned long p1);

void	ft_putptr(unsigned long p1);

int		ft_ptrlen(unsigned long p1);

int		ft_printhex(unsigned int num, char type);

int		ft_hexlen(unsigned int num);

int		ft_printunsigned(unsigned int num);

int		ft_printnum(int num, int full_len);

int		ft_numlen(int num);

int		ft_printstr(const char *str);

int		ft_printchar(int c);

char	itoa(unsigned int num);

int		ft_len(unsigned int num);

#endif
