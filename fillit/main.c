/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:41:55 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/02 13:08:06 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"
#include "header.h"

int		diesepoint(char *str)
{
	int j;
	int k;
	int i;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && i < 20)
	{
		while (str[i] && (i + 1) % 5 != 0)
		{
			if (str[i] == '#' && (str[i + 1] == '#' || str[i - 1] == '#'
						|| str[i + 5] == '#' || str[i - 5] == '#'))
				k++;
			if (str[i] == '#' || str[i] == '.')
				i++;
			else
				return (1);
		}
		if (str[i] == '\n')
			j++;
		i++;
	}
	return ((j == 4 && k == 4) ? 0 : 1);
}

int		verification(char *str)
{
	int n;

	n = 1;
	while (*str)
	{
		if (diesepoint(str) == 0)
		{
			str = str + 19;
			if (str[1] == '\0')
				return (0);
			if (str[1] == '\n')
			{
				if (str[2] != '#' && str[2] != '.')
					return (1);
				str = str + 2;
			}
			else
				str = str + 1;
		}
		else
			return (1);
	}
	return (0);
}

char *read_from_file(const char *filename)
{
	long int size = 0;
	FILE *file = fopen(filename, "r");

	if(!file) {
		fputs("File error.\n", stderr);
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);

	char *result = (char *) malloc(size);
	if(!result) {
		fputs("Memory error.\n", stderr);
		return NULL;
	}

	if(fread(result, 1, size, file) != size) {
		fputs("Read error.\n", stderr);
		return NULL;
	}

	fclose(file);
	return result;
}



int		main(int ac, char **av)
{
	int		fd;
	char	buf[2048];
	int		size;
	char	*buf2;

	if (ac != 2)
		return (write(1, "usage: fillit source_file", 26));
	fd = open(av[1], 2);
	if (fd == -1)
	{
		ft_putstr("error");
		return (1);
	}
	while ((size = read(fd, buf, 2047)));
	buf2 = read_from_file(av[1]);
	printf("bu2 %s\n",buf2);
	printf("\n%d\n", verification(buf));
	if (verification(buf) == 1)
		ft_putstr("error\n");
	printf("%d\n", verification(buf));
	affichagelist(ft_construction(tableaupieces(buf2)));
	printf("%s\n", "hahaha");
	close (fd);
	return (0);
};
