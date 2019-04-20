/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouarg <anas.elouargui@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 06:36:02 by aelouarg          #+#    #+#             */
/*   Updated: 2018/10/08 06:36:41 by aelouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		l;

	l = 0;
	while (src[l] != '\0')
	{
		dest[l] = src[l];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}
