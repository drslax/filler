/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
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

void	parse_map(t_map *map)
{
	char 	*tmp;
	char	*line;
	int		i;
	
	i = -1;
	map->map = (char **)malloc(sizeof(char *)*(map->y));
	while(++i < map->y)
	{
		get_next_line(0, &line);
		tmp = line;
		line = &line[4];
		map->map[i] = line;
		ft_putstr_fd(map->map[i],2);
		ft_putstr_fd("\n",2);
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
	ft_putnbr_fd(map.p,2);
	ft_putstr_fd("\n",2);
	ft_putnbr_fd(map.y,2);
	ft_putstr_fd("\n",2);
	ft_putnbr_fd(map.x,2);
	ft_putstr_fd("\n",2);
	parse_map(&map);
	tab = map_to_int(map);
	heat_init(tab,map);
	heat_map(tab,map);
	print_tab(tab, map.x, map.y);
	return 0;
}
