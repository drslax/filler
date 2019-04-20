/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 05:30:02 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/08 06:10:07 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	const char	*pt;

	pt = str;
	if (c == '\0')
	{
		while (*pt)
			pt++;
		return ((char *)pt);
	}
	while (*str)
	{
		if (*str == (const char)c)
			pt = str;
		str++;
	}
	if (*pt == (const char)c)
		return ((char *)pt);
	return (0);
}
