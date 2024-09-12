/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:59:09 by amireid           #+#    #+#             */
/*   Updated: 2024/03/28 12:51:21 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//#include <stdio.h>

char	*ft_left_n(int fd, char *str)
{
	char	*p;
	int		read_bytes;

	p = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!p)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, p, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(p);
			return (NULL);
		}
		p[read_bytes] = '\0';
		str = ft_strjoin(str, p);
	}
	free(p);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*string[4096];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = ft_left_n(fd, string[fd]);
	if (!tmp)
	{
		if (string[fd])
		{
			free(string[fd]);
			string[fd] = NULL;
		}
		return (NULL);
	}
	string[fd] = tmp;
	line = ft_first_line(string[fd]);
	string[fd] = ft_new_left(string[fd]);
	return (line);
}
/*
int	main(void)
{
    int fd1;
    int fd2;
    int fd3;
    int fd4;
    int i = 1;
    char *line;

    fd1 = open("tests/file1.txt", O_RDONLY);
    fd2 = open("tests/file2.txt", O_RDONLY);
    fd3 = open("tests/file3.txt", O_RDONLY);
    fd4 = open("tests/file4.txt", O_RDONLY);
    while (i < 10)
    {
        line = get_next_line(fd1);
        printf("This is line number %d: %s\n", i, line);
        free(line);
        line = get_next_line(fd2);
        printf("This is line number %d: %s\n", i, line);
        free(line);
        line = get_next_line(fd3);
        printf("This is line number %d: %s\n", i, line);
        free(line);
        line = get_next_line(fd4);
        printf("This is line number %d: %s\n", i, line);
        free(line);
        i++;
    }
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    return (0);
}*/