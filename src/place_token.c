/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:13:18 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/17 15:59:16 by aelouarg         ###   ########.fr       */
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
			if (x >= map.x || y >= map.y)
				return(0);
			if (tab[y][x] == -2)
				return(0);
			if (tab[y][x] == -1 && token.token[i][j] == '*')
				count++;
			if (tab[y][x] != -(map.p) && token.token[i][j] == '*')
				score += tab[y][x];
			x++;
			j++;
		}
		i++;
		y++;
	}
	if (count == 1)
	{

		ft_putnbr_fd(a, 2);
		ft_putstr_fd(" | ", 2);
		ft_putnbr_fd(b, 2);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("count = ",2);
		ft_putnbr_fd(count,2);
		ft_putstr_fd("\n",2);
		return (score);
	}
	if (count)
	{
		ft_putstr_fd("count = ",2);
		ft_putnbr_fd(count,2);
		ft_putstr_fd("\n",2);
	}
	return (0);

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
			if (score && score <= point.score)
			{		
				point.x = j;
				point.y = i;
				point.score = score;
				ft_putnbr_fd(point.y,2);
				ft_putstr_fd(" - ",2);
				ft_putnbr_fd(point.x,2);
				ft_putstr_fd("  ",2);
				ft_putstr_fd("score = ",2);
				ft_putnbr_fd(score,2);
				ft_putstr_fd("\n",2);
			}
		}
	}
	return (point);
}

void	place_token(t_map map, t_token token, int **tab)
{
	t_coord		point;

	point = token_coord(map, token, tab);
	ft_putstr_fd("\n", 2);
	ft_putnbr_fd(point.y, 1);
	ft_putnbr_fd(point.y, 2);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(" ", 2);
	ft_putnbr_fd(point.x, 1);
	ft_putnbr_fd(point.x, 2);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 2);
}
