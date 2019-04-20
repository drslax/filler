/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 01:14:49 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/18 02:41:09 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int		edit_tab(char c)
{
	if (c == 'X' || c == 'x')
		return (-2);
	else if (c == 'O' || c == 'o')
		return (-1);
	return (0);
}

int				**map_to_int(t_map map)
{
	int		**tab;
	int		i;
	int		j;

	i = -1;
	tab = (int **)malloc(sizeof(int *) * map.y);
	while (++i < map.y)
		tab[i] = (int *)malloc(sizeof(int) * map.x);
	i = -1;
	while (++i < map.y)
	{
		j = -1;
		while (++j < map.x)
		{
			tab[i][j] = edit_tab(map.map[i][j]);
		}
	}
	return (tab);
}
