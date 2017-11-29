/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sauverpieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsysaath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:02:18 by gsysaath          #+#    #+#             */
/*   Updated: 2017/11/29 08:18:47 by gsysaath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

static int		nbrederet(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			i++;
		str++;
	}
	return i;
}

char **tableaupieces(char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if(!(tab = (char **)malloc(sizeof(char *) * (nbrederet(str) + 1))))
		return (NULL);
	while (*str)
	{
		j = 0;
		tab[i] = (char *)malloc(sizeof(char) * 4);
		while (*str != '\n')
			tab[i][j++] = *str++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

pieces_list		*ft_construction(char **tab)
{
	int i;
	int j;
	int k;
	int shiftx;
	int shifty;
	pieces_list *list;

	i = -1;
	while (*tab)
	{
		j = -1;
		k = 0;
		while ((++i + 1) % 5 != 0)
		{
			while (++j < 4)
			{
				if (tab[i][j] == '#')
				{
					if (k == 0)
					{
						shiftx = i;
						shifty = j;
					}
					list->tab[k][0] = i - shiftx;
					list->tab[k++][1] = j - shifty;
				}
			}
		}
		if ((i + 1) % 5 == 0)
		{
			i++;
			list->previous = list;
			list = list->next;
		}
	}
	list = 0;
	return (list);
}
