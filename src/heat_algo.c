/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 05:20:12 by aelouarg          #+#    #+#             */
/*   Updated: 2019/05/29 12:01:18 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void		heat_map_rekt(int **tab, int x, int y, t_map map, int c)
{
	if (x + 1 < map.x && tab[y][x + 1] == c)
		tab[y][x] = c + 1;
	if (x - 1 >= 0 && tab[y][x - 1] == c)
		tab[y][x] = c + 1;
	if (y + 1 < map.y && tab[y + 1][x] == c)
		tab[y][x] = c + 1;
	if (y - 1 >= 0 && tab[y - 1][x] == c)
		tab[y][x] = c + 1;
	if (y - 1 >= 0 && x - 1 >= 0 && tab[y - 1][x - 1] == c)
		tab[y][x] = c + 1;
	if (y + 1 < map.y && x + 1 < map.x && tab[y + 1][x + 1] == c)
		tab[y][x] = c + 1;
	if (x - 1 >= 0 && y + 1 < map.y && tab[y + 1][x - 1] == c)
		tab[y][x] = c + 1;
	if (y - 1 >= 0 && x + 1 < map.x && tab[y - 1][x + 1] == c)
		tab[y][x] = c + 1;
}

static void		heat_map(int **tab, t_map map)
{
	int	c;
	int	i;
	int	j;

	c = 0;
	while (++c < map.x)
	{
		i = -1;
		while (++i < map.y)
		{
			j = -1;
			while (++j < map.x)
			{
				if (tab[i][j] == 0)
					heat_map_rekt(tab, j, i, map, c);
			}
		}
	}
}

static void		heat_init_rekt(int **tab, int x, int y, t_map map)
{
	if (x + 1 < map.x && tab[y][x + 1] != -1 && tab[y][x + 1] != -2)
		tab[y][x + 1] = 1;
	if (x - 1 >= 0 && tab[y][x - 1] != -1 && tab[y][x - 1] != -2)
		tab[y][x - 1] = 1;
	if (y + 1 < map.y && tab[y + 1][x] != -1 && tab[y + 1][x] != -2)
		tab[y + 1][x] = 1;
	if (y - 1 >= 0 && tab[y - 1][x] != -1 && tab[y - 1][x] != -2)
		tab[y - 1][x] = 1;
	if (y - 1 >= 0 && x - 1 >= 0 && tab[y - 1][x - 1] != -1 &&
			tab[y - 1][x - 1] != -2)
		tab[y - 1][x - 1] = 1;
	if (y + 1 < map.y && x + 1 < map.x && tab[y + 1][x + 1] != -1 &&
			tab[y + 1][x + 1] != -2)
		tab[y + 1][x + 1] = 1;
	if (x - 1 >= 0 && y + 1 < map.y && tab[y + 1][x - 1] != -1 &&
			tab[y + 1][x - 1] != -2)
		tab[y + 1][x - 1] = 1;
	if (y - 1 >= 0 && x + 1 < map.x && tab[y - 1][x + 1] != -1 &&
			tab[y - 1][x + 1] != -2)
		tab[y - 1][x + 1] = 1;
}

void			heat_init(int **tab, t_map map)
{
	int	c;
	int	i;
	int	j;

	if (who_counter(map.p) == -1 && map.map[1][8] == '.')
	{
		c = -3;
		tab[0][8] = -3;
	}
	else
		c = who_counter(map.p);
	i = -1;
	while (++i < map.y)
	{
		j = -1;
		while (++j < map.x)
			if (tab[i][j] == c)
				heat_init_rekt(tab, j, i, map);
	}
	heat_map(tab, map);
}
