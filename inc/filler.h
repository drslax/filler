/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 23:42:41 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/16 18:51:16 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_map
{
	int				x;
	int				y;
	int				p;
	char			**map;
}					t_map;

typedef struct		s_token
{
	int				x;
	int				y;
	char			**token;
}					t_token;

int					who_counter(int p);
int					**map_to_int(t_map map);
void				heat_map(int **tab, t_map map);
void				heat_init(int **tab, t_map map);

#endif
