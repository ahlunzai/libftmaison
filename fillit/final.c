/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:32:52 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/06 06:21:13 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

g_list	*creationtableau(int size)
{
	g_list		*grille;
	int			i;
	int			j;

	if(!(grille = (g_list *)malloc(sizeof(g_list))))
		return (NULL);
	grille->x = 0;
	grille->y = 0;
	grille->lenline = size;
	grille->i = -1;
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
	ft_putstr("ca marche creation tableau\n");
	return (grille);
}

int		libre(g_list *grille, pieces_list **list, int x, int y)
{
	int		k;

	ft_putstr("rentre dans libre\n");
	grille->x = x;
	grille->y = y;
	while (grille->x < grille->lenline)
	{
		ft_putstr("rentre dans 1er while\n");
		while (grille->y < grille->lenline)
		{
			ft_putstr("rentre dans 2eme while\n");
			k = 0;
			while (grille->map[grille->x + (*list)->tab[k][0]]
					[grille->y + (*list)->tab[k][1]] == '.' && k < 4)
			{
				ft_putstr("rentre dans while bug\n");
				k++;
			}
			ft_putstr("a fini le 3eme while\n");
			if (k == 4)
			{
				ft_putstr("ca marche libre\n");
				return (1);
			}
			else
				(grille->y)++;
		}
		(grille->x)++;
	}
	return (0);
}

void		place_piece(g_list *grille, pieces_list **list, int i)
{
	int			k;

	k = -1;
	while (++k < 4)
		grille->map[grille->x + (*list)->tab[k][0]][grille->y + (*list)->tab[k][1]]
			= 'A' + i;
	(grille->y)++;
	if (grille->y == grille->lenline)
	{
		grille->x = grille->x + 1;
		grille->y = 0;
	}
}

void		supprime_piece(g_list *grille, pieces_list **list)
{
	int			k;

	(grille->y)--;
	if (grille->y < 0)
	{
		(grille->x)--;
		grille->y = grille->lenline - 1;
	}
	k = -1;
	while (++k < 4)
		grille->map[grille->x + (*list)->tab[k][0]][grille->y + (*list)->tab[k][1]]
			= '.';
}


char	**placepieces(g_list *grille, pieces_list **list, int x, int y)
{
	ft_putstr("debut de placepieces\n");
	while (*list != NULL)
	{
		ft_putstr("rentre dans boucle while \n");
		if (libre(grille, list, 0, 0) == 1)
		{
			ft_putstr("premier if\n");
			place_piece(grille, list, ++(grille->i));
			ft_putstr("fini le deuxieme place piece\n\n");
			*list = (*list)->next;
			if (*list == NULL)
				return (grille->map);
			if (libre(grille, list, 0, 0) == 1)
				placepieces(grille, list, grille->x, grille->y);
			else
			{
				*list = (*list)->previous;
				supprime_piece(grille, list);
				(grille->i)--;
				(grille->y)++;
				if (grille->y == grille->lenline)
				{
					(grille->x)++;
					grille->y = 0;
				}
				if (grille->x == grille->lenline)
					placepieces(creationtableau(grille->lenline + 1), list, 0, 0);
				placepieces(grille, list, grille->x, grille->y);
			}
		}
		else
			placepieces(creationtableau(grille->lenline + 1), list, 0, 0);
	}
	return (grille->map);
}
