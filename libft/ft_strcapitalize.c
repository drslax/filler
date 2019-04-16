/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:42:14 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/11 22:42:34 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
		{
			str[0] -= 32;
			i++;
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] < 48 || str[i - 1] > 122)
				str[i] -= 32;
			if (str[i - 1] > 57 && str[i - 1] < 65)
				str[i] -= 32;
			if (str[i - 1] > 90 && str[i - 1] < 97)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
