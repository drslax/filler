/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:13:18 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/18 03:25:22 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int	valid_place(t_map map, t_token token, int **tab, int a, int b)
{
	int	i;
	int	j;
	int y = a;
	int x = b;
	int	score;
	int	count;

	i = 0;
	score = 0;
	count = 0;
	while (i < token.y)
	{
		j = 0;
		x = b;
		while (j < token.x)
		{
			if ((x >= map.x || y >= map.y) && token.token[i][j] == '*')
				return(-1);
			if (token.token[i][j] == '*' && tab[y][x] == who_counter(map.p))
				return(-1);
			if (token.token[i][j] == '*' && tab[y][x] == -(map.p))
				count++;
			if (token.token[i][j] == '*' && tab[y][x] != -(map.p))
				score += tab[y][x];
			x++;
			j++;
		}
		i++;
		y++;
	}
	if (count == 1)
		return (score);
	return (-1);

}

static t_coord	token_coord(t_map map, t_token token, int **tab)
{
	t_coord		point;
	int		score;
	int		i;
	int		j;

	i = -1;
	point.x = -1;
	point.y = -1;
	point.score = 2147483647;
	while (++i < map.y)
	{
		j = -1;
		while (++j < map.x)
		{

			score = valid_place(map, token, tab, i, j);
			if ((score > 0 && score <= point.score) || (score == 0 && point.score == 2147483647))
			{		
				point.x = j;
				point.y = i;
				point.score = score;
			}
		}
	}
	return (point);
}

void	place_token(t_map map, t_token token, int **tab)
{
	t_coord		point;

	point = token_coord(map, token, tab);
	ft_putnbr_fd(point.y, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(point.x, 1);
	ft_putstr_fd("\n", 1);
}
