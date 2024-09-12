/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:51 by aeid              #+#    #+#             */
/*   Updated: 2023/11/23 20:12:22 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointerlength(uintptr_t n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

static void	ft_printpointer(uintptr_t n)
{
	if (n >= 16)
	{
		ft_printpointer(n / 16);
		ft_printpointer(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_pointer(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		ft_printpointer(n);
		count += ft_pointerlength(n);
	}
	return (count);
}
