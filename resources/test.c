/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:29:37 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/15 17:56:59 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../libft/libft.h"

int main()
{
	int		i;
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
	return 0;
}
