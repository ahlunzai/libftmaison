/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:24:06 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/01 12:25:39 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"


g_list		*creationtableau(int size)
{
	g_list		*grille;
	int			i;
	int			j;

	if(!(grille = (g_list *)malloc(sizeof(g_list))))
		return (NULL);
	grille->x = 0;
	grille->y = 0;
	grille->lenline = size;
	grille->sizemap = size * size;
	grille->gap = 0;
	if(!(grille->map = (char **)malloc(sizeof(char *) * grille->lenline)))
		return (NULL);
	i = -1;
	while (++i < grille->lenline)
	{
		if(!(grille->map[i] = (char *)malloc(sizeof(char) * grille->lenline)))
			return (NULL);
		j = -1;
		while (++j < grille->lenline)
			grille->map[i][j] = '.';
	}
	return (grille);
}

int			place_pieces(g_list *grille, pieces_list **list, int i)
{
	int		k;

	while (grille->x < grille->lenline && grille->gap < (grille->lenline * 2))
	{
		grille->y = 0;
		while (grille->y < grille->lenline 
				&& grille->gap < (grille->lenline * 2))
		{
			k = 0;
			while (grille->map[grille->x + (*list)->tab[k][0]]
					[grille->y + (*list)->tab[k][1]] == '.')
			{
				grille->map[grille->x + (*list)->tab[k][0]]
					[grille->y + (*list)->tab[k][1]] = 'A' + i;
				k++;
			}
			if (k == 4)
				return (1);
			else
			{
				(grille->y)++;
				grille->gap++;
			}
		}
		(grille->x)++;
		(grille->gap)++;
	}
	return (0);
}

char		**placement(g_list *grille, pieces_list **list)
{
	if (grille->gap < (grille->lenline * 2) && list != NULL)
	{
		if (place_pieces(grille, list, i) == 1)
			placement(grille, ++list, ++i);
	}
	if (grille->gap >= (grille->lenline * 2) || list != NULL)
	{
		grille->lenline = grille->lenline + 1;
		grille->gap = 0;
		placement(grille, list, i);
	}
	return (grille->map);
}
