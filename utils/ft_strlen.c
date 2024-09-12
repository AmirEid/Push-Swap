/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:43:41 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 12:53:32 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

//#include <stdio.h>//
//#include <string.h>//

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

/*int main()
{
    //int i = ft_strlen ("hello");//
    int i = strlen("Hello");
    printf("the length of the array is %i", i);
    return (0);
}*/
