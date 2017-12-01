/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichagelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 03:07:38 by gsysaath          #+#    #+#             */
/*   Updated: 2017/12/01 13:43:01 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

void	affichagelist(pieces_list **list)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			ft_putnbr((*list)->tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	list++;
	if (list != NULL)
		affichagelist(list);
}
