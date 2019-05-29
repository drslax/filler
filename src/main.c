/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:29:37 by aelouarg          #+#    #+#             */
/*   Updated: 2019/05/28 06:28:47 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int				who_counter(int p)
{
	if (p == 1)
		return (-2);
	else
		return (-1);
}

void			freehom(t_map *map, t_token *token, int ***tab)
{
	int		i;

	i = -1;
	while (++i < map->y)
	{
		free(map->map[i]);
		free((*tab)[i]);
		if (i < token->y)
			free(token->token[i]);
	}
	free(*tab);
	free(token->token);
	free(map->map);
}

int				init_token(t_token *token)
{
	int		i;
	int		j;

	i = -1;
	while (++i < token->x)
	{
		j = -1;
		while (++j < token->y && token->token[j][i] == '.')
			;
		if (j != token->y)
			break ;
	}
	return (i);
}

static void		parse_token(t_token *token)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 6;
	get_next_line(0, &tmp);
	token->y = ft_atoi(&tmp[6]);
	while (ft_isdigit(tmp[i++]))
		token->x = ft_atoi(&tmp[i]);
	free(tmp);
	i = -1;
	token->token = (char **)malloc(sizeof(char *) * (token->y));
	while (++i < token->y)
	{
		get_next_line(0, &line);
		token->token[i] = ft_strdup(line);
		free(line);
	}
	token->minx = init_token(token);
}

static	void	parse_map(t_map *map, t_token *token)
{
	char	*line;
	int		**tab;
	int		i;

	i = -1;
	map->map = (char **)malloc(sizeof(char *) * (map->y));
	while (++i < map->y)
	{
		get_next_line(0, &line);
		map->map[i] = ft_strdup(&line[4]);
		free(line);
	}
	parse_token(token);
	tab = map_to_int(*map);
	heat_init(tab, *map);
	place_token(*map, *token, tab);
	freehom(map, token, &tab);
}

int				main(void)
{
	int		i;
	t_token	token;
	char	*tmp;
	t_map	map;

	while (get_next_line(0, &tmp) > 0)
	{
		if (!ft_strncmp(tmp, "$$$", 3))
		{
			map.p = ft_atoi(&tmp[10]);
			free(tmp);
			get_next_line(0, &tmp);
		}
		map.y = ft_atoi(&tmp[8]);
		i = 8;
		while (ft_isdigit(tmp[i++]))
			;
		map.x = ft_atoi(&tmp[i]);
		free(tmp);
		get_next_line(0, &tmp);
		free(tmp);
		parse_map(&map, &token);
	}
	tmp ? free(tmp) : 0;
	return (0);
}
