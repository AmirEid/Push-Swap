/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:35:45 by amireid           #+#    #+#             */
/*   Updated: 2023/11/23 18:04:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar((va_arg(args, int)));
	else if (format == '%')
		count += ft_putchar('%');
	else if (format == 'i' || format == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_pointer(va_arg(args, unsigned long long));
	else if (format == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (*(str + i) == '%')
		{
			length += ft_format(args, *(str + i + 1));
			i++;
		}
		else
			length += ft_putchar(*(str + i));
		i++;
	}
	va_end(args);
	return (length);
}
