/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lepluspetitcarre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 05:05:37 by gsysaath          #+#    #+#             */
/*   Updated: 2017/11/29 08:13:24 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

char	**placementmap(pieces_list *list)
{
	char	**map;
	int		i;
	int		j;
	int		k;


	i = -1;
	while (++i < 4)
	{
		map = (char **)malloc(sizeof(char *) * 5);
		j = -1;
		while (++j < 4)
		{
			map[i] = (char *)malloc(sizeof(char) * 5);
			map[i][j] = '.';
		}
		map[i][j] = '\0';
	}
	map[i] = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			while (map[i][j] == '.')
			{
				map[i][j] = '1';
				i = i + list->tab[k][0];
				j = j + list->tab[k][1];
				k++;
			}
			j++;
		}
		i++;
	}
	return (map);
}
