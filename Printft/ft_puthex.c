/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:49:08 by aeid              #+#    #+#             */
/*   Updated: 2023/11/23 20:48:18 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlength(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count = 1;
	else
	{
		while (nbr != 0)
		{
			count++;
			nbr = nbr / 16;
		}
	}
	return (count);
}

static void	ft_printhex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_printhex((nbr / 16), format);
		ft_printhex((nbr % 16), format);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
		{
			if (format == 'x')
				ft_putchar(nbr - 10 + 'a');
			else
				ft_putchar(nbr - 10 + 'A');
		}
	}
}

int	ft_puthex(unsigned int nbr, const char format)
{
	if (nbr == 0)
		write(1, "0", 1);
	else
		ft_printhex(nbr, format);
	return (ft_hexlength(nbr));
}
