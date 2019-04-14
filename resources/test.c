/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:29:37 by aelouarg          #+#    #+#             */
/*   Updated: 2019/04/14 23:34:01 by aelouarg         ###   ########.fr       */
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
	int	i,j;
	char	**tab2;
	char 	*s[256];

		for(i = 0;i < 25; i++)
		{
			get_next_line(0, &s[i]);
			ft_putstr_fd(s[i], 2);
			ft_putstr_fd("\n", 2);
		}
	return 0;
}
