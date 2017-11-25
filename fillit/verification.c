/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:41:55 by gsysaath          #+#    #+#             */
/*   Updated: 2017/11/25 08:44:12 by gsysaath         ###   ########.fr       */
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
#include <libft.a>

int		diesepoint(char *str, int n)
{
	int j;
	int k;
	int i;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && i * n < 20 * n)
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
		if (diesepoint(str, n) == 0)
		{
			str = str + 19;
			n++;
			if (str[1] == '\0')
				return (0);
			if (str[1] == '\n')
			{
				str = str + 2;
				if (str[2] != '#' && str[2] != '.')
					return (1);
			}
			else
				str = str + 1;
		}
		else
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	buf[2048];
	int		size;

	printf("%d\n%d\n%d\n", O_RDONLY, O_WRONLY, O_RDWR);
	if (ac != 2)
		return (write(1, "usage: fillit source_file", 26));
	fd = open(av[1], 2);
	if (fd == -1)
	{
		ft_putstr("error");
		return (1);
	}
	while (size == read(fd, buf, 2047))
		write (1, buf, size);
	if (verification(buf) == 1)
		ft_putstr("error");
	printf("%d", verification(buf));
	close (fd);
	return (0);
};
