/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:29:37 by aelouarg          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/16 01:18:48 by aelouarg         ###   ########.fr       */
=======
/*   Updated: 2019/04/15 17:56:59 by aelouarg         ###   ########.fr       */
>>>>>>> 737a0286e45bdc73b2cfe8412ccf04588a2af3cd
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

char	who_play(t_map map)
{
	if (map.p == 1)
		return ('O');
	else
		return ('Y');
}
int		heat_tab(t_map map)
{
	int		**tab;
	int		i;
	char	p;

	i = 0;
	tab = (int **)malloc(sizeof(int **)*map.y);
	while(i++ < map.x)
		tab[i] = (int *)malloc(sizeof(int *)*map.x);
	p = who_play(map);
	i = 0;
	j = 0;
	while ()
	return (0);
}

int 	main(void)
{
	int		i;
<<<<<<< HEAD
	t_map	map;
	char 	*tmp;
	char 	*tmp2;

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
		free(tmp2);
	}
=======
	int		player;
	int		tab[2];
	char 	**map;
	char 	*tmp;
	char 	*tmp2;

		i = 8;
		get_next_line(0, &tmp);
		player = tmp[10];
		free(tmp);
		get_next_line(0, &tmp);
		tab[0] = ft_atoi(&tmp[8]);
		while (ft_isdigit(tmp[i++]))
		tab[1] = ft_atoi(&tmp[i]);
		free(tmp);
		get_next_line(0, &tmp);
		free(tmp);
		i = -1;
		map = (char **)malloc(sizeof(char **)*(tab[0]));
		while(++i < tab[0])
		{
			get_next_line(0, &tmp);
			tmp2 = tmp;
			tmp = &tmp[4];
			map[i] = tmp;
			free(tmp2);
		}
>>>>>>> 737a0286e45bdc73b2cfe8412ccf04588a2af3cd
	return 0;
}