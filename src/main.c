/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:29:37 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/16 05:01:50 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		who_counter(int p)
{
	if (p == 1)
		return (-2);
	else
		return (-1);
}

int		edit_tab(char c)
{
	if (c == 'X' || c == 'x' )
		return (-2);
	else if(c == 'O' || c == 'o')	
		return (-1);
	return (0);
}

int		**map_to_int(t_map map)
{
	int		**tab;
	int		i;
	int		j;

	i = -1;
	tab = (int **)malloc(sizeof(int *)*map.y);
	while(++i < map.y)
		tab[i] = (int *)malloc(sizeof(int )*map.x);
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

void		heat_map_rekt(int **tab, int x, int y, t_map map, int c)
{
	if(x + 1 < map.x && tab[y][x + 1] == c)
		tab[y][x] = c + 1;
	if(x - 1 >= 0 && tab[y][x - 1] == c)
		tab[y][x] = c + 1;
	if(y + 1 < map.y && tab[y + 1][x] == c)
		tab[y][x] = c + 1;
	if(y - 1 >= 0 && tab[y - 1][x] == c)
		tab[y][x] = c + 1;
	if(y - 1 >= 0 && x - 1 >= 0 && tab[y - 1][x - 1] == c)
		tab[y][x] = c + 1;
	if(y + 1 < map.y && x + 1 < map.x && tab[y + 1][x + 1] == c)
		tab[y][x] = c + 1;
	if(x - 1 >= 0 && y + 1 < map.y && tab[y + 1][x - 1] == c)
		tab[y][x] = c + 1;
	if(y - 1 >= 0 && x + 1 < map.x && tab[y - 1][x + 1] == c)
		tab[y][x] = c + 1;
}

void		heat_map(int **tab, t_map map)
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
			while(++j < map.x)
			{
				if (tab[i][j] == 0)
					heat_map_rekt(tab, j, i, map, c);
			}
		}
	}
}

int		heat_init_rekt(int **tab, int x, int y, t_map map)
{
	if(x + 1 < map.x && tab[y][x + 1] != -1 && tab[y][x + 1] != -2)
		tab[y][x + 1] = 1;
	if(x - 1 >= 0 && tab[y][x - 1] != -1 && tab[y][x - 1] != -2)
		tab[y][x - 1] = 1;
	if(y + 1 < map.y && tab[y + 1][x] != -1 && tab[y + 1][x] != -2 )
		tab[y + 1][x] = 1;
	if(y - 1 >= 0 && tab[y - 1][x] != -1 && tab[y - 1][x] != -2)
		tab[y - 1][x] = 1;
	if(y - 1 >= 0 && x - 1 >= 0 && tab[y - 1][x - 1] != -1 && tab[y - 1][x - 1] != -2)
		tab[y - 1][x - 1] = 1;
	if(y + 1 < map.y && x + 1 < map.x && tab[y + 1][x + 1] != -1 && tab[y + 1][x + 1] != -2)
		tab[y + 1][x + 1] = 1;
	if(x - 1 >= 0 && y + 1 < map.y && tab[y + 1][x - 1] != -1 && tab[y + 1][x - 1] != -2)
		tab[y + 1][x - 1] = 1;
	if(y - 1 >= 0 && x + 1 < map.x && tab[y - 1][x + 1] != -1 && tab[y - 1][x + 1] != -2)
		tab[y - 1][x + 1] = 1;
}

int		heat_init(int **tab, t_map map)
{
	int	c;
	int	i;
	int	j;

	c = who_counter(map.p);
	i = -1;
	while (++i < map.y)
	{
		j = -1;
		while(++j < map.x)
			if (tab[i][j] == c)
				heat_init_rekt(tab, j, i, map);
	}
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
			if (tab[i][j] <= 9 && tab[i][j] >=0)
				ft_putstr_fd(" ", 2);
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
	tab = map_to_int(map);
	heat_init(tab,map);
	heat_map(tab,map);
	print_tab(tab, map.x, map.y);
	free(tmp2);
	return 0;
}
