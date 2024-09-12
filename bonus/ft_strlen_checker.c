/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:43:41 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 16:09:15 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

//#include <stdio.h>//
//#include <string.h>//

size_t	ft_strlen_checker(const char *str)
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
