/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:13:18 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/17 10:28:36 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int	valid_place(t_map map, t_token token, int **tab, int y, int x)
{
	int	i;
	int	j;
	int	score;
	int	count;
	
	i = -1;
	score = 0;
	count = 0;
	while (++i < token.y)
	{
		j = -1;
		while (++j < token.x)
		{
			if (x >= map.x || y >= map.y)
				return(0);
			if (tab[y][x] == -(map.p) && token.token[i][j] == '*')
				count++;
			score += tab[y][x];
			x++;
		}
		y++;
	}
	if (count == 1)
		return (score);
	return (0);

}

static t_coord	token_coord(t_map map, t_token token, int **tab)
{
	t_coord		point;
	int		score;
	int		i;
	int		j;

	i = -1;
	point.x = -5;
	point.y = -5;
	point.score = 214;
	//point.score = 2147483647;
	while (++i < map.y)
	{
		j = -1;
		while (++j < map.x)
		{

			score = valid_place(map, token, tab, i, j);
			if (score && score < point.score)
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
	//ft_putnbr_fd(point.x, 2);
	ft_putstr_fd(" ", 1);
	//ft_putstr_fd(" ", 2);
	ft_putnbr_fd(point.x, 1);
	//ft_putnbr_fd(point.y, 2);
	ft_putstr_fd("\n", 1);
	//ft_putstr_fd("\n", 2);
}
