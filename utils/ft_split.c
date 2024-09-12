/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:47:52 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 12:53:29 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

//#include <stdio.h>//
//#include <stdlib.h>//

static size_t	wordcount(char const *str, char c)
{
	size_t	wordcount;
	size_t	i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			wordcount++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (wordcount);
}

static size_t	wordlength(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

static void	freeupmem(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free(*(str + i));
	}
	free(str);
}

static char	**split(char const *str, char c, char **s, size_t nowords)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < nowords)
	{
		while (*(str + j) && *(str + j) == c)
			j++;
		*(s + i + 1) = ft_substr(str, j, wordlength(str + j, c));
		if (!*(s + i + 1))
		{
			freeupmem(i, s);
			return (NULL);
		}
		while (*(str + j) && *(str + j) != c)
			j++;
		i++;
	}
	*(s + i + 1) = NULL;
	return (s);
}

char	**ft_split(char const *str, char c)
{
	char	**p;
	size_t	i;

	if (!str)
		return (NULL);
	i = wordcount(str, c);
	if (i == 0)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (i + 2));
	if (!p)
		return (NULL);
	p[0] = malloc(sizeof(char));
	if (!p[0])
		return (NULL);
	p[0][0] = '\0';
	p = split(str, c, p, i);
	return (p);
}
/*
int	main(void)
{
	const char	*str;
	char		delimiter;
	char		**words;
	int			i;

	str = ",,Hello,,World,How,Are,You,Shit,Fuck";
	delimiter = ',';
	words = ft_split(str, delimiter);
	if (words != NULL)
	{
		i = 0;
		while (words[i] != NULL)
		{
			printf("%s\n", words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	else
	{
		printf("Invalid input or allocation failed\n");
	}
	return (0);
}*/
