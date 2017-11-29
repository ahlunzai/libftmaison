/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:53:11 by gsysaath          #+#    #+#             */
/*   Updated: 2017/11/29 06:04:44 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

typedef struct			tetris_list
{
	int tab[4][2];

	struct tetris_list	*next;
	struct tetris_list	*previous;
}						pieces_list;

char					**placementmap(pieces_list *list);
pieces_list				*ft_construction(char **tab);
char					**tableaupieces(char *str);
#endif