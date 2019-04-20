/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:39:05 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/08 05:29:42 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (const char)c)
		str++;
	if (*str == (const char)c)
		return ((char *)str);
	return (0);
}
