/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 01:11:52 by gsysaath          #+#    #+#             */
/*   Updated: 2017/11/24 03:16:02 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	buf[2048];
	int		size;

	if (ac != 2)
		return (write(1, "usage: fillit source_file", 26));
	fd = open(av[1], 0_RDONLY);
	if (fd == -1)
		return (1);
	while (size = read(fd, buf, 2047))
		write (1, buf, size);
	close (fd);
	return (0);
}
