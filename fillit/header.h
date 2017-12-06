/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:53:11 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/06 02:23:41 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

typedef struct			tetris_list
{
	int tab[4][2];

	int i;
	struct tetris_list	*next;
	struct tetris_list	*previous;
}						pieces_list;

typedef struct			grille_list
{
	char **map;
	int x;
	int y;
	int lenline;
	int i;
}						g_list;

g_list					*creationtableau(int size);
char					**placepieces(g_list *grille, pieces_list **list, int x, int y);
void					affichagelist(pieces_list **list);
char					**placementmap(pieces_list **list);
pieces_list				**ft_construction(char **tab);
char					**tableaupieces(char *str);
#endif
