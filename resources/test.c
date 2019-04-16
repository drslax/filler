/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:29:37 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/16 05:01:50 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

char	who_play(t_map map)
{
	if (map.p == 1)
		return ('O');
	else
		return ('X');
}

int		who_counter(int p)
{
	if (p == 1)
		return (2);
	else
		return (1);
}

int		edit_tab(char c)
{
	if (c == 'X' || c == 'x' )
		return (-2);
	else if(c == 'O' || c == 'o')	
		return (-1);
	return (0);
}

int		**heat_tab(t_map map)
{
	int		**tab;
	int		i;
	int		j;
	char	p;

	i = -1;
	tab = (int **)malloc(sizeof(int *)*map.y);
	while(++i < map.y)
		tab[i] = (int *)malloc(sizeof(int )*map.x);
	p = who_play(map);
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

void	print_tab(int **tab, int x, int y)
{
	int		i,j;

	i = -1;
	while (++i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr_fd(tab[i][j], 2);
			j++;	
		}
		ft_putstr_fd("\n", 2);
	}
}

int 	main(void)
{
	int		i;
	t_map	map;
	char 	*tmp;
	char 	*tmp2;
	int		**tab;

	i = 8;
	get_next_line(0, &tmp);
	map.p = ft_atoi(&tmp[10]);
	free(tmp);
	get_next_line(0, &tmp);
	map.y = ft_atoi(&tmp[8]);
	while (ft_isdigit(tmp[i++]))
		map.x = ft_atoi(&tmp[i]);
	free(tmp);
	get_next_line(0, &tmp);
	free(tmp);
	i = -1;
	ft_putnbr_fd(map.p,2);
	ft_putstr_fd("\n",2);
	ft_putnbr_fd(map.y,2);
	ft_putstr_fd("\n",2);
	ft_putnbr_fd(map.x,2);
	ft_putstr_fd("\n",2);
	map.map = (char **)malloc(sizeof(char **)*(map.y));
	while(++i < map.y)
	{
		get_next_line(0, &tmp);
		tmp2 = tmp;
		tmp = &tmp[4];
		map.map[i] = tmp;
		ft_putstr_fd(map.map[i],2);
		ft_putstr_fd("\n",2);
	}
	tab = heat_tab(map);
	print_tab(tab, map.x, map.y);
	free(tmp2);
	return 0;
}
