/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:04:15 by amireid           #+#    #+#             */
/*   Updated: 2023/11/23 19:10:10 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int nbr);
int		ft_puthex(unsigned int nbr, const char format);
int		ft_pointer(unsigned long long n);
char	*ft_itoa(int i);

#endif