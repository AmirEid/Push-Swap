/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:52:24 by aeid              #+#    #+#             */
/*   Updated: 2023/11/23 18:04:53 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int nbr)
{
	int		len;
	char	*p;

	len = ft_nbrlen(nbr);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	while (nbr != 0)
	{
		p[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (p);
}

int	ft_putunsigned(unsigned int nbr)
{
	int		count;
	char	*p;

	count = 0;
	if (nbr == 0)
		count += write(1, "0", 1);
	else
	{
		p = ft_uitoa(nbr);
		count += ft_putstr(p);
		free(p);
	}
	return (count);
}
